#ifndef GC_H
#define GC_H

#include "Message.hpp"
#include "WSInd.hpp"

class GC
{
public:
	GC();
	~GC();
	void dispatcherWSmessage(unsigned long MessageID, Message* msg);
	void handleUserInfo(WSInd * ind);

private:
	//MsgQueue GCQueue_;
};

#endif
