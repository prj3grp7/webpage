#include <vector>
#include <string>
#include <iostream>
#include <unistd.h>
#include <string_view>
#include <uWS/uWS.h>
#include <sstream>
#include "WS.hpp"
#include "UserInfo.hpp"
#include "Message.hpp"
#include "MsgQueue.hpp"
#include "WSInd.hpp"

WS::WS(MsgQueue * GCQueue)
	: WSMsgQueue_(10)
{
	this->GCQueue_=GCQueue;
}

WS::WS(){}

void WS::WSInit()
{

h.onMessage([&](uWS::WebSocket<uWS::SERVER> *ws, char *message, size_t length, uWS::OpCode opCode) {

	// Splitting string and storing substrings in vector
	string gameInformation = message;
	char delimiter = '-';
	vector<string> tokens;

	istringstream str(gameInformation);
	for (string substring; getline(str, substring, delimiter); tokens.push_back(substring));

	WSInd* ind = new WSInd(true);

	//Setting team2
	ind->team2->setTeam(tokens.back());
	tokens.pop_back();
	ind->team2->setUser2(tokens.back());
	tokens.pop_back();
	ind->team2->setUser1(tokens.back());
	tokens.pop_back();

	// Setting team1
	ind->team1->setTeam(tokens.back());
	tokens.pop_back();
	ind->team1->setUser2(tokens.back());
	tokens.pop_back();
	ind->team1->setUser1(tokens.back());
	tokens.pop_back();

	// Sending to GameController class
	GCQueue_->send(ID_INFO_READY, ind);

	// Sending back to WS client
	ws->send(message, length, opCode);
});}


//void WS::sendInfo(){}
