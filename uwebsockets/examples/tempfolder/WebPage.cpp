/*
 *  WebPage.cpp
 *	SERVER
 *  Created on: 20/10/2018
 *  Author: MH
 */

#include <uWS/uWS.h>
#include "WS.hpp"
#include "GC.hpp"
#include "UserInfo.hpp"
#include "Message.hpp"
#include "MsgQueue.hpp"
using namespace std;

MsgQueue * GCQueue = new MsgQueue(10);
GC GC;
WS WS(GCQueue);

void * GCFunc(void*);

int main()
{

uWS::Hub h;

pthread_t GCID;

WS.WSInit();

pthread_create(&GCID, nullptr, GCFunc, nullptr);
pthread_join(GCID, nullptr);

if (h.listen(3000)) {
	 h.run();
	}

}

void * GCFunc(void*)
{
	while(true)
	{
		unsigned long MessageID;
		Message * msg = GCQueue->receive(MessageID);
		GC.dispatcherWSmessage(MessageID, msg);
		delete msg;
	}
}
