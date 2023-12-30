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
void addManager();
void addStaff();
void delStaff();
void delManager();
void AstaffMenu();
void AmanagerMenu();
void managerMenu();
void addRoom();
void delRoom();
void updRoom();

using namespace std;
extern bool isLoggedin;
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
		AmanagerMenu();
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
		AstaffMenu();
		break;
	}
	case 4:
	{
		break;
	}
	case 5:
	{
		isLoggedin = false;
		isAdmin = false;
		loggedUser.clear();
		MENU();
		break;
	}
	default:
		break;
	}



}


void AstaffMenu()
{
	Staff user;
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
	case 2:
	{
		delStaff();
		break;
	}
	case 3:
	{
		user.updateInfo();
		break;
	}
	case 4:
	{
		user.displayInfo();
		break;
	}
	case 5:
	{
		cout << "\t\t\t\t Returning to Admin Menu....";
		Sleep(1000);
		AdminMenu();
		break;
	}
	default:
		break;
	}
}

void addStaff() //Friend Function of Class Staff
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

void delStaff() //Friend Function of Admin
{
	Staff user;
	bool found = false;
	string staffid;
	cout << "\t\t\t\t Enter Staff ID:";
	getline(cin>>ws, staffid);
	
	ifstream infile;
	infile.open("Staff.txt", ios::binary);
	ofstream outfile("tempStaff.txt", ios::binary | ios::app);

	if (infile.is_open() && outfile.is_open()) {
		while (infile.read(reinterpret_cast<char*>(&user), sizeof(user))) 
		{
			if (user.staffId != staffid) 
			{
				outfile.write(reinterpret_cast<char*>(&user), sizeof(user));
			}
			else {
				found = true;
			}

		}

		if (!found) {
			cout << "\n\n\t\tRecord not found" << endl;
		}
		else {
			cout << "\n\n\t\tRecord Deleted Successfully!\n";
		}
		infile.close();
		outfile.close();
		remove("Staff.txt");
		rename("tempStaff.txt","Staff.txt");
	}
	else {
		cout << "\n\n\t\tFile doesn't exist";
	}
	cout << "press any key to continue!";
	_getch();
	AstaffMenu();
}




void AmanagerMenu() 
{
	Manager user;
	int choice = 0;
	system("cls");
	cout << "\t\t\t\t **********************************************" << endl;
	cout << "\t\t\t\t # ========================================== #" << endl;
	cout << "\t\t\t\t # |             ::MANAGER MENU::           | #" << endl;
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
	case 2:
	{
		delManager();
		break;
	}
	case 3:
	{
		user.updateInfo();
		break;
	}
	case 4:
	{
		user.displayInfo();
		break;

	}
	case 5:
	{
		cout << "\t\t\t\t Returning to Menu...";
		Sleep(1000);
		AdminMenu();
	}
	default:
		break;
	}


}
void addManager() //Friend Function of Manager
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
void delManager() //Friend Function of Manager
{
	Manager user;
	bool found = false;
	string Manid;
	cout << "\t\t\t\t Enter Staff ID:";
	getline(cin >> ws, Manid);

	ifstream infile;
	infile.open("Manager.txt", ios::binary);
	ofstream outfile("tempManager.txt", ios::binary | ios::app);

	if (infile.is_open() && outfile.is_open()) {
		while (infile.read(reinterpret_cast<char*>(&user), sizeof(user)))
		{
			if (user.ManId != Manid)
			{
				outfile.write(reinterpret_cast<char*>(&user), sizeof(user));
			}
			else {
				found = true;
			}

		}

		if (!found) {
			cout << "\n\n\t\tRecord not found" << endl;
		}
		else {
			cout << "\n\n\t\tRecord Deleted Successfully!\n";
		}
		infile.close();
		outfile.close();
		remove("Manager.txt");
		rename("tempManager.txt", "Manager.txt");

	}
	else {
		cout << "\n\n\t\tFile doesn't exist";
	}
	cout << "press any key to continue!";
	_getch();
	if (isAdmin)
		AstaffMenu();
	else
		staffMenu();
}






void roomMenu()
{
	Room room;
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
	case 2:
	{
		delRoom();
		break;
	}
	case 3:
	{
		updRoom();
		break;
	}
	case 4:
	{
		room.displayRoom();
		break;
	}
	case 5:
	{
		cout << "\t\t\t\t Returning to Room Menu....";
		Sleep(1000);
		AdminMenu();
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
		_getch();
		Sleep(1000);
		roomMenu();
	}
	else
	{
		cout << "\t\t\t\t Room Number Already Exist" << endl;
		cout << "\t\t\t\t Returning to Menu...." << endl;
		Sleep(1000);
		roomMenu();
	}

}



void delRoom()
{
	Room room;
	bool found = false;
	string roomnum;
	cout << "\t\t\t\t Enter Staff ID:";
	getline(cin >> ws, roomnum);

	ifstream infile;
	infile.open("Room.txt", ios::binary);
	ofstream outfile("tempRoom.txt", ios::binary | ios::app);

	if (infile.is_open() && outfile.is_open()) {
		while (infile.read(reinterpret_cast<char*>(&room), sizeof(room)))
		{
			if (room.roomNum != roomnum)
			{
				outfile.write(reinterpret_cast<char*>(&room), sizeof(room));
			}
			else {
				found = true;
				continue;
			}

		}

		if (!found) {
			cout << "\n\n\t\t Room not found" << endl;
		}
		else {
			cout << "\n\n\t\t Room Deleted Successfully!\n";
		}
		infile.close();
		outfile.close();
		remove("Room.txt");
		rename("tempRoom.txt", "Room.txt");

	}
	else {
		cout << "\n\n\t\tFile doesn't exist";
	}
	cout << "press any key to continue!";
	_getch();
	if (isAdmin)
		roomMenu();
}
void updRoom()
{
	Room room, temp;
	int size = sizeof(temp);
	fstream file("Room.txt", ios::binary | ios::in | ios::out);
	cout << "Enter Room number you want to Update: ";
	getline(cin >> ws, room.roomNum);
	if (file.is_open())
	{
		while (file.read(reinterpret_cast<char*>(&temp), sizeof(temp)))
		{
			if (temp.roomNum == room.roomNum)
			{
				int Temp;
				cout << "\t\t\t\t Select Room Type: " << endl;
				cout << "\t\t\t\t 1.Luxury 2.Suite 3.Economy ";
				cin >> room.type;
				cout << "\t\t\t\t Enter Room Number: ";
				getline(cin >> ws, room.roomNum);
				cout << "\t\t\t\t Enter Availability Status (1. Yes 2.No) :";
				cin >> Temp;
				if (Temp == 1)
				{
					room.availability = true;
				}
				else
				{
					room.availability = false;
				}
				if (room.type == 1) // Luxury
				{
					room.price = 20000;
				}
				else if (room.type == 2) // Suite
				{
					room.price = 15000;
				}
				if (room.type == 3) // Economy
				{
					room.price = 10000;
				}
				file.seekp(-size, ios::cur);
				file.write(reinterpret_cast<char*>(&room), sizeof(room));
				file.close();
				cout << "\t\t\t\t Room Updated Successfully";
				_getch();
			}
		}
	}
	if (isAdmin)
		roomMenu();
}