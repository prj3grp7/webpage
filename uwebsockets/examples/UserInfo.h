#pragma once

#include <iostream>
#include <string>
#include <stdlib.h>
#include <cstdint>
using namespace std;

class UserInfo
{
public:
	UserInfo(string username1 = "", string username2 = "", string team = 0, uint8_t red = 0, uint8_t green = 0, uint8_t blue = "", int cups = 12)
		: username1_(username1), username2_(username2), team_(team), red_(red), green_(green), blue_(blue), cups_(cups) {
	}

	//Inds�t copyconstructor
	UserInfo(const UserInfo & copyMe)
	{
		this->team_ = copyMe.team_;
		this->username1_ = copyMe.username1_;
		this->username2_ = copyMe.username2_;
		this->red_ = copyMe.red_;
		this->green_ = copyMe.green_;
		this->blue_ = copyMe.blue_;
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

	void setRed(const string & red)
	{
		red_ = stoi(red);
	}

	void setGreen(const string & green)
	{
		green_ = stoi(green);
	}

	void setBlue(const string & blue)
	{

		blue_ = stoi(blue);
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

	const unsigned int getRed() const
	{
		return static_cast<unsigned int>(red_);
	}

	const unsigned int getGreen() const
	{
		return static_cast<unsigned int>(green_);
	}

	const unsigned int getBlue() const
	{
		return static_cast<unsigned int>(blue_);
	}

	~UserInfo()
	{}
private:
	string username1_;
	string username2_;
	string team_;
	uint8_t red_;
	uint8_t green_;
	uint8_t blue_;
	int cups_;
};
