#ifndef WSIND_H
#define WSIND_H

#include "Message.hpp"
#include "UserInfo.hpp"

class WSInd : public Message
{
public:
	WSInd(bool info)
		: info_(info){}

	virtual ~WSInd(){}

	bool info_ = false;
	UserInfo team1;
	UserInfo team2;
};

#endif
