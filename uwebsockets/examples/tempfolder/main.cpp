/*

#include <vector>
#include <string>
#include <iostream>
#include <unistd.h>
#include <string_view>
#include <uWS/uWS.h>
#include <sstream>
#include "WS.hpp"
#include "GC.hpp"

void* gameControllerThread(void * data)
void* listenThread(void * data)
void* WSThread(void * data)

int main()
{

uWS::Hub h;

UserInfo team1;
UserInfo team2;

WS::WSInit(team1, team2, &h);

pthread_t WSID, controllerID, listenID;

pthread_create(&WSID, nullptr, WSThread, &WSMsgQueue_);
pthread_create(&controllerID, nullptr, gameControllerThread, &GCQueue_);
pthread_create(&listenID, nullptr, listenThread, &h);

GCQueue_.send(ID_START);

pthread_join(WSID, nullptr);
pthread_join(controllerID, nullptr);
pthread_join(listenID, nullptr);

//if (h.listen(3000)) {
//	 h.run();
//}

return 0;
}


void* listenThread(void * data)
{
uWS::Hub * h = static_cast<uWS::Hub*>(data);
if (h->listen(3000))
	h->run();
}

void* WSThread(void * data)
{
	//MsgQueue * WSMsgQueue_ = static_cast<MsgQueue*>(data);

	while (true)
	{
		unsigned long id;
		Message * msg = WSMsgQueue_->receive(id);
		dispatchGameControllerRequests(id, msg);
		delete msg;
	}
}

void* gameControllerThread(void * data)
{
	//MsgQueue * GCQueue_ = static_cast<MsgQueue*>(data);

	while (true)
	{
		unsigned long id;
		Message* msg = GCQueue_->receive(id);
		dispatcherWSresponse(msg, id);
		delete msg;
	}
	return nullptr;
}

*/
