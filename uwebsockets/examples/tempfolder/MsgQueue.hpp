#ifndef MSGQUEUE_H
#define MSGQUEUE_H

#include "Message.hpp"
#include "Item.hpp"
#include <queue>
#include <pthread.h>
#include <iostream>
using namespace std;

class MsgQueue
{
public:
	MsgQueue(unsigned long maxSize)
		: maxSize_(maxSize) {}

	void send(unsigned long id, Message * msg = NULL)
	{
		pthread_mutex_lock(&m);

		while (messageContainer.size() >= maxSize_)
			pthread_cond_wait(&c, &m);

		Item * item = new Item;
		item->id_ = id;
		item->msg_ = msg;
		messageContainer.push(item);

		pthread_cond_signal(&c);

		pthread_mutex_unlock(&m);
	}

	Message * receive(unsigned long& id)
	{
		pthread_mutex_lock(&m);

		while (messageContainer.size() == 0)
			pthread_cond_wait(&c, &m);

		// copy first element of queue and assign it new id
		Item * item = messageContainer.front();

		messageContainer.pop();

		pthread_cond_signal(&c);

		pthread_mutex_unlock(&m);

		id = item->id_;
		Message * msg = item->msg_;
		delete item;
		return msg;
	}

	~MsgQueue()
	{
		while(!messageContainer.empty()) messageContainer.pop();
	}

private:
	unsigned int maxSize_;
	queue<Item *> messageContainer;
	pthread_mutex_t m = PTHREAD_MUTEX_INITIALIZER;
	pthread_cond_t c = PTHREAD_COND_INITIALIZER;
};

#endif
