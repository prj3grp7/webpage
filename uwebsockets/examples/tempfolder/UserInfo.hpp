#ifndef USERINFO_H
#define USERINFO_H

#include <iostream>
#include <string>
using namespace std;

class UserInfo
{
public:
	UserInfo(string username1 = "", string username2 = "", string team = "", int cups = 12)
		: username1_(username1), username2_(username2), team_(team), cups_(cups) {
	}

	void setCups(int & cups)
	{
		cups_ = cups;
	}

	void setUser1(const string &user1)
	{
		username1_ = user1;
	}

	void setUser2(const string &user2)
	{
		username2_ = user2;
	}

	void setTeam(const string &team)
	{
		team_ = team;
	}

	const int getCups() const
	{
		return cups_;
	}

	const string getUser1() const
	{
		return username1_;
	}

	const string getUser2() const
	{
		return username2_;
	}

	const string getTeam() const
	{
		return team_;
	}

	private:
		string username1_;
		string username2_;
		string team_;
		int cups_;
};

#endif
