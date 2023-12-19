#include<iostream>
#include<conio.h>
#include<string>
#include<string.h>
#include<windows.h>
#include<fstream>
#include<sstream>
using namespace std;


class basicInfo //Abstract class
{
protected:
	string name;
	int age;
	string cnic;
	string address;
	string phone;
	string gender;
public:
	virtual void displayInfo() = 0; // Pure virtual function
	virtual void setInfo() {};
};

class Guest :public basicInfo
{
private:
	string emgContact;
	long long int wallet;
	string check_in;
	string check_out;
	string ReservationID;

public:



};