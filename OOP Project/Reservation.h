#pragma once
#include "BasicInfo.h"
#include<iostream>
#include<conio.h>
#include<string>
#include<string.h>
#include<windows.h>
#include<fstream>
#include<sstream>
#include"MainMenu.h"
#include "Rooms.h"
extern bool isAdmin;
extern string loggedUser;
void foodMenu();
void GuestMenu();
template<class r> 
class Reservation : public Guest<string,string>, public Room<r>
{
private:
	int type;
	int size;
	bool service;

public:
	void makeReservation()
	{
		
			int choice=0;
			system("cls");
			cout << "\t\t\t\t **********************************************" << endl;
			cout << "\t\t\t\t # ========================================== #" << endl;
			cout << "\t\t\t\t # |            ::RESERVATION MENU::        | #" << endl;
			cout << "\t\t\t\t # |                                        | #" << endl;
			cout << "\t\t\t\t # |            1. New Guest     	         | #" << endl;
			cout << "\t\t\t\t # |            2. Book Room                | #" << endl;
			cout << "\t\t\t\t # |            3. Food                     | #" << endl;
			cout << "\t\t\t\t # |            4. Log out                  | #" << endl;
			cout << "\t\t\t\t # |                                        | #" << endl;
			cout << "\t\t\t\t # ========================================== #" << endl;
			cout << "\t\t\t\t **********************************************" << endl;
			start:
			choice = 0;
			cout << "Enter Your Choice: ";
			cin >> choice;
			{

				switch (choice)
				{
				case 1:
				{
					Guest <string,string> gUser,temp;
					bool isFound=false;
					gUser.setInfo();
					ifstream rFile("Guest.txt", ios::binary);
					if (rFile.is_open())
					{
						if (rFile.read(reinterpret_cast<char*>(&temp), sizeof(temp)))
						{
							while (!rFile.eof())
							{
								if (gUser.getcnic() == temp.getcnic())
								{
									cout << "\t\t\t\t CNIC Already Exist... You can Book Room";
									Sleep(1000);
									makeReservation();
									break;
								}
								rFile.read(reinterpret_cast<char*>(&temp), sizeof(temp));
							}
						}

					}
						gUser.Registration(gUser);
						cout << "Registration Successful..";
						Sleep(1000);
						makeReservation();
						break;
				
				}
				case 2:
				{
				
					bookRoom();
					break;
				}
				case 3:
				{
					foodMenu();
					break;

				}
				case 4:
				{
					cout << "\t\t\t\t Returning to Main Menu...";
					Sleep(1000);
					GuestMenu();
					break;
				}
				default:
					{
					cout << "\t\t\t\t Invalid input. Select from 1 to 4";
					cin.clear();
					while (cin.get() != '\n')
					{
						continue;
					}
					Sleep(1500);
					goto start;
					break;

					}
				}
			}
			
	}

void bookRoom()
{
		Guest<string,string> G;
		int sizeG = sizeof(G);
		string cnic;
		bool isFound = false; //Room Found
		bool isGuest = false; //Guest Found
		cout << "Enter CNIC: ";
		getline(cin >> ws, cnic);

		fstream file("Guest.txt", ios::binary|ios::in|ios::out);
		if (file.is_open())
		{
			while (file.read(reinterpret_cast<char*>(&G), sizeof(G)))
			{
				if (G.getcnic() == cnic)
				{
					isGuest = true;
				}
			}
			file.close();
		}

		if (isGuest)
		{

			string choice;
			Reservation reserve;
			int temp1;
			cout << "\t\t\t\t Select Room Type: " << endl;
			start:
			cout << "\t\t\t\t 1.Luxury (20,000) 2.Suite (15,000) 3.Economy (10,000): ";
			cin >> reserve.type;
			switch (reserve.type)
			{
			case 1:
			{
				G.setbill(20000,G);
				break;
			}
			case 2:
			{
				G.setbill(15000,G);
				break;
			}
			case 3:
			{
				G.setbill(10000,G);
				break;
			}
			default:
				cout << "\t\t\t\t Invalid input. Please enter integer.\n";
				cin.clear();
				while (cin.get() != '\n') {
					continue;
				}
				goto start;
				break;
			}
			cout << "\t\t\t\t Select Room Size: " << endl;
			start2:
			cout << "\t\t\t\t 1.Single 2.Double (Rs.3000) 3.Family: (Rs.5000)";
			cin >> temp1;
			switch (temp1)
			{
			case 1:
				{
					G.setbill(0,G);
					break;
				}
			case 2:
				{
					G.setbill(3000,G);
					break;

				}
			case 3:
				{
					G.setbill(5000,G);
					break;
				}
			default:
			{

				cin.clear();
				while (cin.get() != '\n')
				{
					continue;
				}
				Sleep(1500);
				goto start2;
				break;
			}
			}
			cout << "\t\t\t\t Do you want Extra Services? (Like Room services etc)" << endl;
			cout << "\t\t\t\t Extra Services Charges are: Rs.5000" << endl;
			start3:
			cout << "\t\t\t\t Enter Yes or No ";
			getline(cin >> ws, choice);
			if (choice == "Yes" || choice == "yes")
			{
				G.setbill(5000,G);
				service = true;
			}
			else if (choice == "No" || choice == "no")
			{
				service = false;
			}
			else
			{
				cout << "\t\t\t\t Invalid Input";
				cin.clear();
				while (cin.get() != '\n')
				{
					continue;
				}
				Sleep(1500);
				goto start3;
			}

			Room<string>temp;
			int size = sizeof(temp);
			fstream rfile("Room.txt", ios::binary | ios::in | ios::out);
			if (rfile.is_open())
			{
				while (rfile.read(reinterpret_cast<char*>(&temp), sizeof(temp)))
				{
					if (temp.gettype() == reserve.type && temp.getavailability() == true)
					{
						isFound = true;
						cout << "\t\t\t\t Room Registered by: " << loggedUser;
						cout << "\t\t\t\t Room Number: " << temp.getroomNum();
						cout << "\t\t\t\t Room Size: ";
						if (reserve.size == 1)
						{
							cout << "\t\t\t\t Single" << endl;
						}
						else if (reserve.size == 2)
						{
							cout << "\t\t\t\t Double" << endl;
						}
						else if (reserve.size == 3)
						{
							cout << "\t\t\t\t Family" << endl;
						}

						//Update Room availability Status
						rfile.seekp(-size, ios::cur);
						temp.setavailabilityfalse();
						rfile.write(reinterpret_cast<char*>(&temp), sizeof(temp));
						Guest<string,string> a;
						fstream file("Guest.txt", ios::binary | ios::in | ios::out);
						if (file.is_open())
						{
							while (file.read(reinterpret_cast<char*>(&a), sizeof(a)))
							{
								if (a.getcnic() == cnic)
								{
									// Update Guest Info
									time_t now = time(0);
									// convert now to string form
									#pragma warning(suppress : 4996). // Exception for ctime
									char* date_time = ctime(&now);
									this->check_in = date_time;
									//Adding Room Bills
									file.seekp(-sizeG, ios::cur);
									file.write(reinterpret_cast<char*>(&G), sizeof(G));
									break;
								}
							}
							file.close();
						}
					}
				}
			}
				if (!isFound)
				{
					cout << "\t\t\t\t Room not Available. Try Other Room Type....";
					Sleep(1800);
					rfile.close();
					makeReservation();
				}
				else
				{
					cout << "\t\t\t\t Press any key to continue...";
					_getch();
				}
				rfile.close();
				makeReservation();
		}
			else
			{
				cout << "\t\t\t\t Guest not found...";
				Sleep(1000);
				makeReservation();
			}
		
	}


};


void ReserveMenu()
{
	Reservation<string> a;
	a.makeReservation();
}

void foodMenu()
{
	int choice = 0;

	
		choice = 0;
		system("cls");
		cout << "\t\t\t\t **********************************************" << endl;
		cout << "\t\t\t\t # ========================================== #" << endl;
		cout << "\t\t\t\t # |             ::FOOD MENU::              | #" << endl;
		cout << "\t\t\t\t # |                                        | #" << endl;
		cout << "\t\t\t\t # |         1. Breakfast Deal (2000)       | #" << endl;
		cout << "\t\t\t\t # |         2. Brunch Deal    (1500)       | #" << endl;
		cout << "\t\t\t\t # |         3. Lunch Deal     (2000)       | #" << endl;
		cout << "\t\t\t\t # |         4. Dinner Deal    (2500)       | #" << endl;
		cout << "\t\t\t\t # |         5. Exit                        | #" << endl;
		cout << "\t\t\t\t # |                                        | #" << endl;
		cout << "\t\t\t\t # ========================================== #" << endl;
		cout << "\t\t\t\t **********************************************" << endl;
			string cnic;
			cout << "\t\t\t\t Enter CNIC: ";
			getline(cin >> ws, cnic);
			Guest <string,string> temp;
			int size = sizeof(temp);
			fstream rFile("Guest.txt", ios::binary|ios::in|ios::out);
			if (rFile.is_open())
			{
				if (rFile.read(reinterpret_cast<char*>(&temp), sizeof(temp)))
				{
					while (!rFile.eof())
					{
						if (cnic == temp.getcnic())
						{
							start:
							cout << "Enter Your Choice: ";
							cin >> choice;
							switch (choice)
							{
							case 1:
							{
								cout << "\t\t\t\t Breakfast Deal Purchased..";
								temp.setfbill(2000, temp);
								break;
							}
							case 2:
							{
								cout << "\t\t\t\t Brunch Deal Purchased..";
								temp.setfbill(1500, temp);
								break;

							}
							case 3:
							{
								cout << "\t\t\t\t Lunch Deal Purchased..";
								temp.setfbill(2000, temp);
								break;

							}
							case 4:
							{
								cout << "\t\t\t\t Dinner Deal Purchased..";
								temp.setfbill(2500, temp);
								break;

							}
							default:
								cout << "\t\t\t\t Invalid Choice...";
								cout << "\t\t\t\t Invalid input. Please enter integer.\n";
								cin.clear();
								while (cin.get() != '\n') {
									continue;
								}
								Sleep(1000);
								goto start;
								break;
							}
							break;
						}
						rFile.read(reinterpret_cast<char*>(&temp), sizeof(temp));
					}
					rFile.seekp(-size, ios::cur);
					rFile.write(reinterpret_cast<char*>(&temp), sizeof(temp));
					rFile.close();

				}
				else 
				{
					cout << "\t\t\t\t Guest not found....";
					Sleep(1000);
				}
			}
	
		ReserveMenu();
}