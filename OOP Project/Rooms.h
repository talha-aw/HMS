#pragma once
#include<iostream>
#include<conio.h>
#include<string>
#include<string.h>
#include<windows.h>
#include<fstream>
#include<sstream>
using namespace std;
void roomMenu();

class Room
{
private:
	string roomNum;
	int type; //1.Luxury 2.Suite 3.Economy
	bool availability;
	long int price;
public:
	void setavailabilitytrue()
	{
		availability = true;
	}
	void setavailabilityfalse()
	{
		availability = false;
	}
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

	void displayRoom()
	{
		Room temp;
		ifstream rfile;
		rfile.open("Room.txt", ios::binary);
		if (rfile.read(reinterpret_cast<char*>(&temp), sizeof(temp)))
		{
			if (rfile.is_open())
			{
				if (isAdmin)
				{
					while (!rfile.eof())
					{
						
						cout << "\t\t\t\t Room Number: " << temp.roomNum << endl;
						cout << "\t\t\t\t Room Type: ";
						if (temp.type == 1)
							cout << "Luxury" <<endl;
						if (temp.type == 2)
							cout << "Suite" <<endl;
						if (temp.type == 3)
							cout << "Economy" <<endl;

						cout << "\t\t\t\t Price: " << temp.price << endl;
						
						cout << "\t\t\t\t Availability: ";
						if (temp.availability)
							cout << "Available" << endl;
						else
							cout << "Not Available" << endl;
						rfile.read(reinterpret_cast<char*>(&temp), sizeof(temp));
					}
				}
				

			}

		}
		cout << "\t\t\t\t Press any key to Continue:";
		_getch();
		roomMenu();
	}
};

