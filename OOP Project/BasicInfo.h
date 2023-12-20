#include<iostream>
#include<conio.h>
#include<string>
#include<string.h>
#include<windows.h>
#include<fstream>
#include<sstream>
#include<chrono>
#include<iomanip>
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
	string email;
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
	static int ReservationID;
	

public:

	void displayInfo()
	{

	}
	void setInfo()
	{
		cout << "Enter Name: ";
		getline(cin >> ws, name);
		cout << "Enter Age: ";
		cin >> age;
		cout << "Enter CNIC: ";
		getline(cin >> ws, cnic);
		cout << "Enter Phone Number: ";
		getline(cin >> ws, phone);
		cout << "Enter Address: ";
		getline(cin >> ws, address);
		cout << "Enter Gender: ";
		getline(cin >> ws, gender);
		cout << "Enter Emergency Contact: ";
		getline(cin >> ws, emgContact);


		////To Store Current Time and Date
		//auto time = std::chrono::system_clock::now();
		//std::time_t now_c = std::chrono::system_clock::to_time_t(time);

		//
		//struct tm timeInfo;
		//localtime_s(&timeInfo, &now_c);

		//stringstream ss;
		//ss << std::put_time(&timeInfo, "%Y-%m-%d %H:%M:%S");
		//getline(ss, check_in);

	}



	void Registration()
	{
		ofstream file;
		file.open("Guest.txt", ios::app);
		file << ReservationID + "~" + cnic + "~" + name + "~" + phone + "~" + address + "~" + gender + "~" + emgContact + "~" + email + check_in << endl;
		cout << "Registration Successful";
		file.close();
	}

};
int Guest::ReservationID = 1;
