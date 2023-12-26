#pragma once
#include<iostream>
#include<conio.h>
#include<string>
#include<string.h>
#include<windows.h>
#include<fstream>
#include<sstream>
#include"Rooms.h"
//#include"BasicInfo.h"
void roomMenu();
void addRoom();
void addManager();
void addStaff();
void staffMenu();
void managerMenu();

using namespace std;

void AdminMenu()
{
	int choice;
	system("cls");
	cout << "\t\t\t\t **********************************************" << endl;
	cout << "\t\t\t\t # ========================================== #" << endl;
	cout << "\t\t\t\t # |             ::ADMIN MENU::             | #" << endl;
	cout << "\t\t\t\t # |                                        | #" << endl;
	cout << "\t\t\t\t # |            1. Managers     	         | #" << endl;
	cout << "\t\t\t\t # |            2. Rooms                    | #" << endl;
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
		managerMenu();
	/*	Guest gUser;
		gUser.setInfo();
		gUser.Registration(gUser);
		cout << "Registration Successful..";*/
		Sleep(1000);
		break;
	}
	case 2:
	{
		roomMenu();
		break;
	}
	case 3:
	{
		staffMenu();
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


void staffMenu()
{
	int choice = 0;
	system("cls");
	cout << "\t\t\t\t **********************************************" << endl;
	cout << "\t\t\t\t # ========================================== #" << endl;
	cout << "\t\t\t\t # |             ::STAFF MENU::             | #" << endl;
	cout << "\t\t\t\t # |                                        | #" << endl;
	cout << "\t\t\t\t # |            1. Add Staff                | #" << endl;
	cout << "\t\t\t\t # |            2. Delete Staff             | #" << endl;
	cout << "\t\t\t\t # |            3. Update Staff             | #" << endl;
	cout << "\t\t\t\t # |            4. Show Staff               | #" << endl;
	cout << "\t\t\t\t # |            5. Exit                     | #" << endl;
	cout << "\t\t\t\t # |                                        | #" << endl;
	cout << "\t\t\t\t # ========================================== #" << endl;
	cout << "\t\t\t\t **********************************************" << endl;
	cout << "Enter Your Choice: ";
	cin >> choice;
	switch (choice)
	{
	case 1:
	{
		addStaff();
		break;
	}
	case 3:
	{
		Staff user;
		user.updateinfo();
		break;
	}
	case 4:
	{
		Staff user;
		user.displayInfo();
		break;
	}
	default:
		break;
	}
}

void addStaff()
{
	Staff user;
	cout << "Enter Name: ";
	getline(cin >> ws, user.name);
	cout << "Enter Age: ";
	cin >> user.age;
	cout << "Enter CNIC: ";
	getline(cin >> ws, user.cnic);
	cout << "Enter Phone Number: ";
	getline(cin >> ws, user.phone);
	cout << "Enter Address: ";
	getline(cin >> ws, user.address);
	cout << "Enter Gender: ";
	getline(cin >> ws, user.gender);
	cout << "Enter Staff Role: \n";
	getline(cin >> ws, user.Role);
	cout << "Enter the salary: ";
	user.Salary = 50000;
	cout << "Enter the shift:(Morning/Night) ";
	getline(cin >> ws, user.Shift);
	cout << "Enter Staff Id: ";
	getline(cin >> ws, user.staffId);
	cout << "Enter Password: ";
	getline(cin >> ws, user.password);

	user.Registration(user);
}





void managerMenu()
{
	int choice = 0;
	system("cls");
	cout << "\t\t\t\t **********************************************" << endl;
	cout << "\t\t\t\t # ========================================== #" << endl;
	cout << "\t\t\t\t # |             ::ROOM MENU::              | #" << endl;
	cout << "\t\t\t\t # |                                        | #" << endl;
	cout << "\t\t\t\t # |            1. Add Manager              | #" << endl;
	cout << "\t\t\t\t # |            2. Delete Manager           | #" << endl;
	cout << "\t\t\t\t # |            3. Update Manager Details   | #" << endl;
	cout << "\t\t\t\t # |            4. Show Manager             | #" << endl;
	cout << "\t\t\t\t # |            5. Exit                     | #" << endl;
	cout << "\t\t\t\t # |                                        | #" << endl;
	cout << "\t\t\t\t # ========================================== #" << endl;
	cout << "\t\t\t\t **********************************************" << endl;
	cout << "Enter Your Choice: ";
	cin >> choice;
	switch (choice)
	{
	case 1:
	{
		addManager();
		break;
	}
	case 3:
	{
		Manager user;
		user.updateinfo();
		break;
	}
	case 4:
	{
		Manager user;
		user.displayInfo();
		break;

	}
	default:
		break;
	}


}
void addManager()
{
	Manager user;
	cout << "Enter Name: ";
	getline(cin >> ws, user.name);
	cout << "Enter Age: ";
	cin >> user.age;
	cout << "Enter CNIC: ";
	getline(cin >> ws, user.cnic);
	cout << "Enter Phone Number: ";
	getline(cin >> ws, user.phone);
	cout << "Enter Address: ";
	getline(cin >> ws, user.address);
	cout << "Enter Gender: ";
	getline(cin >> ws, user.gender);
	cout << "Enter the Salary: ";
	user.Salary=300000;
	cout << "Enter Manager Id: ";
	getline(cin >>ws,user.ManId);
	cout << "Enter Password: ";
	cin >> user.password;
	
	user.Registration(user);
}







void roomMenu()
{
	int choice=0;
	system("cls");
	cout << "\t\t\t\t **********************************************" << endl;
	cout << "\t\t\t\t # ========================================== #" << endl;
	cout << "\t\t\t\t # |             ::ROOM MENU::              | #" << endl;
	cout << "\t\t\t\t # |                                        | #" << endl;
	cout << "\t\t\t\t # |            1. Add Rooms     	         | #" << endl;
	cout << "\t\t\t\t # |            2. Delete Rooms             | #" << endl;
	cout << "\t\t\t\t # |            3. Update Room Details      | #" << endl;
	cout << "\t\t\t\t # |            4. Show Rooms               | #" << endl;
	cout << "\t\t\t\t # |            5. Exit                     | #" << endl;
	cout << "\t\t\t\t # |                                        | #" << endl;
	cout << "\t\t\t\t # ========================================== #" << endl;
	cout << "\t\t\t\t **********************************************" << endl;
	cout << "Enter Your Choice: ";
	cin >> choice;
	switch (choice)
	{
	case 1:
	{
		addRoom();
		break;
	}
	default:
		break;
	}
}
void addRoom()
{
	int Temp;
	Room addroom;
	cout << "\t\t\t\t Select Room Type: "<<endl;
	cout << "\t\t\t\t 1.Luxury 2.Suite 3.Economy " ;
	cin >> addroom.type;
	cout << "\t\t\t\t Enter Room Number: ";
	getline(cin >> ws, addroom.roomNum);
	cout << "\t\t\t\t Enter Availability Status (1. Yes 2.No) :";
	cin >> Temp;
	if (Temp == 1)
	{
		addroom.availability = true;
	}
	else
	{
		addroom.availability = false;
	}
	if (addroom.type==1) // Luxury
	{
		addroom.price = 20000;
	}
	else if (addroom.type==2) // Suite
	{
		addroom.price = 15000;
	}
	if (addroom.type==3) // Economy
	{
		addroom.price = 10000;
	}

	//Writing to File
	Room temp;
	bool isFind = false; //Finds Room with same number
	int TYPE = 0;
	ifstream rfile("Room.txt", ios::binary);
	if (rfile.is_open())
	{
		while (rfile.read(reinterpret_cast<char*>(&temp), sizeof(temp)))
		{
			if (addroom.roomNum == temp.roomNum)
			{
				isFind = true;
				rfile.close();
				break;
			}
		}
		rfile.close();
	}

	if (!isFind)
	{
		ofstream file("Room.txt", ios::binary | ios::app);
		if (file.is_open())
		{
			file.write(reinterpret_cast<char*>(&addroom), sizeof(addroom));
			file.close();
		}
		cout << "\t\t\t\t Room Added Successful \n\t\t\t\t Press Any Key to Continue......" << endl;
		Sleep(1000);
	}
	else
	{
		cout << "\t\t\t\t Room Number Already Exist" << endl;
		cout << "\t\t\t\t Returning to Menu...." << endl;
		Sleep(1000);
	}

}