#pragma once
#include<iostream>
#include<conio.h>
#include<string>
#include<string.h>
#include<windows.h>
#include<fstream>
#include<sstream>
#include "BasicInfo.h"
#include "Rooms.h"
extern string loggedUser;
class Reservation :public Guest,public Room 
{
private:
	int type;
	int size;
	bool service;
	
public:
	void makeReservation()
	{
		int choice;
		system("cls");
		cout << "\t\t\t\t **********************************************" << endl;
		cout << "\t\t\t\t # ========================================== #" << endl;
		cout << "\t\t\t\t # |            ::RESERVATION MENU::        | #" << endl;
		cout << "\t\t\t\t # |                                        | #" << endl;
		cout << "\t\t\t\t # |            1. New Guest     	         | #" << endl;
		cout << "\t\t\t\t # |            2. Book Room                | #" << endl;
		cout << "\t\t\t\t # |            3. Staff                    | #" << endl;
		cout << "\t\t\t\t # |            4. Food                     | #" << endl;
		cout << "\t\t\t\t # |            5. Log out                  | #" << endl;
		cout << "\t\t\t\t # |                                        | #" << endl;
		cout << "\t\t\t\t # ========================================== #" << endl;
		cout << "\t\t\t\t **********************************************" << endl;
		cout << "Enter Your Choice: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
		{
			Guest gUser;
			gUser.setInfo();
			gUser.Registration(gUser);
			cout << "Registration Successful..";
			Sleep(1000);
			break;
		}
		case 2:
		{
			bookRoom();
			break;
		}
		case 3:
		{
			break;
		}
		case 4:
		{
			break;
		}
		case 5:
		{
			break;
		}
		default:
			break;
		}
	}

	void bookRoom()
	{
		string choice;
		Reservation reserve;
		cout << "\t\t\t\t Select Room Type: " << endl;
		cout << "\t\t\t\t 1.Luxury (20,000) 2.Suite (15,000) 3.Economy (10,000): ";
		cin >> reserve.type;
		cout << "\t\t\t\t Select Room Size: " << endl;
		cout << "\t\t\t\t 1.Single 2.Double (Rs.3000) 3.Family: (Rs.5000)";
		cin >> reserve.size;
		cout << "\t\t\t\t Do you want Extra Services? (Like Room services etc)" << endl;
		cout << "\t\t\t\t Extra Services Charges are: Rs.5000" << endl;
		cout << "\t\t\t\t Enter Yes or No ";
		getline(cin >> ws, choice);
		if (choice == "Yes" || choice == "yes")
		{
			service = true;
		}
		else if (choice == "No" || choice == "no")
		{
			service = false;
		}
		else
		{
			cout << "\t\t\t\t Invalid Input";
		}

		Room temp;
		ifstream rfile("Room.txt", ios::binary);
		if (rfile.is_open())
		{
			while (rfile.read(reinterpret_cast<char*>(&temp), sizeof(temp)))
			{
				if (temp.gettype() == reserve.type && temp.getavailability() == true)
				{
					cout << "\t\t\t\t Room Registered by: " << loggedUser;
					cout << "\t\t\t\t Room Number: " << temp.getroomNum();
					cout << "\t\t\t\t Room Size: ";
					if (size == 1)
					{
						cout << "\t\t\t\t Single"<< endl;
					}
					else if (size == 2)
					{
						cout << "\t\t\t\t Double"<<endl;
					}
					else if (size == 3)
					{
						cout << "\t\t\t\t Family"<<endl;
					}
					//Update Room availability Status
					break;
				}
			}
			rfile.close();
		}
	}




};