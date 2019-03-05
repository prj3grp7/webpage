#include <iostream>
#include "GC.hpp"
#include "UserInfo.hpp"
#include "Message.hpp"
#include "MsgQueue.hpp"

GC::GC();

GC::~GC(){}

void GC::dispatcherWSmessage(unsigned long MessageID, Message* msg)
{
	switch(MessageID)
	{
		case ID_INFO_READY:
		{
			WSInd * ind = static_cast<WSInd*>(msg);
			handleUserInfo(ind);
			break;
		}
		default:
		break;
	}
}

void GC::handleUserInfo(WSInd* ind)
{
	if (ind->Info_)
	{
	cout << "Team 1:" << endl;
	cout << "Teamname is: " << ind->team1.getTeam() << endl;
	cout << "Username1 is: " << ind->team1.getUser1() << endl;
	cout << "Username2 is: " << ind->team1.getUser2() << endl << endl;

	cout << "Team 2:" << endl;
	cout << "Teamname is: " << ind->team2.getTeam() << endl;
	cout << "Username1 is: " << ind->team2.getUser1() << endl;
	cout << "Username2 is: " << ind->team2.getUser2() << endl << endl;
	}
}
