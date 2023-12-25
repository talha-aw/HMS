#pragma once
#include<iostream>
#include<conio.h>
#include<string>
#include<string.h>
#include<windows.h>
#include<fstream>
#include<sstream>
using namespace std;

class Room
{
private:
	string roomNum;
	int type; //1.Luxury 2.Suite 3.Economy
	bool availability;
	long int price;
public:
	string getroomNum()
	{
		return roomNum;
	}

	int gettype()
	{
		return type;
	}
	bool getavailability()
	{
		return availability;
	}


	friend void addRoom();

};

