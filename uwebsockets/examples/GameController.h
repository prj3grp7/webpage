#pragma once
#include "MessageQueue.h"
#include "ThreadFunctor.h"

class GameController : public ThreadFunctor
{
public:
	GameController(MsgQueue * GCQueue)
		: GameControllerMsgQueue_(GCQueue) 
	{

	}
	virtual void run();
	void dispatcher(unsigned long id, Message * msg); 
	~GameController() {}
private:
	MsgQueue * GameControllerMsgQueue_ = nullptr; 

};