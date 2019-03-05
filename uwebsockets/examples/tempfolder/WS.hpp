#ifndef WS_H
#define WS_H

#include "UserInfo.hpp"
#include "Message.hpp"
#include "MsgQueue.hpp"

class WS
{
public:
	WS(MsgQueue * GCQueue);
	~WS();
	void WSInit();
	//void sendInfo();

private:
	MsgQueue WSMQueue_;
	MsgQueue * GCQueue_;
};

#endif
