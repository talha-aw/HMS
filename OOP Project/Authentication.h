#include<iostream>
#include<conio.h>
#include<string>
#include<string.h>
#include<windows.h>
#include<fstream>
#include<sstream>
#include"temp.h"
#include"BasicInfo.h"
#include"Admin.h"
using namespace std;
extern bool isLoggedin;

class Authentication
{

private:
	string username;
	string password;
	int type; // User type
public:
	void signup()
	{
		int choice;
		Authentication user;
		system("cls");
		cout << "\t\t\t\t **********************************************" << endl;
		cout << "\t\t\t\t # ========================================== #" << endl;
		cout << "\t\t\t\t # |          ACCOUNT REGISTRATION          | #" << endl;
		cout << "\t\t\t\t # ========================================== #" << endl;
		cout << "\t\t\t\t **********************************************" << endl;
		cout << "\t\t\t\t Enter User Name: ";
		getline(cin >> ws, user.username);
		cout << "\t\t\t\t Enter Password: ";
		getline(cin >> ws, user.password);

		cout << "\t\t\t\t **********************************************" << endl;
		cout << "\t\t\t\t # ========================================== #" << endl;
		cout << "\t\t\t\t # |            REGISTRATION FOR            | #" << endl;
		cout << "\t\t\t\t # |                                        | #" << endl;
		cout << "\t\t\t\t # |          ::Select From Below::         | #" << endl;
		cout << "\t\t\t\t # |          1. Admin                      | #" << endl;
		cout << "\t\t\t\t # |          2. Guest                      | #" << endl;
		cout << "\t\t\t\t # |                                        | #" << endl;
		cout << "\t\t\t\t # ========================================== #" << endl;
		cout << "\t\t\t\t **********************************************" << endl;
		cout << "\t\t\t\t Enter Your Choice: ";
		cin >> choice;
		extern string Masterkey; //Access Global Variable from main
		switch (choice)
		{
		case 1:
		{
			string key;
			cout << "\t\t\t\t Enter MasterKey: ";
			getline(cin >> ws, key);
			if (key == Masterkey)
			{
				user.type = 1; //Type 1 is for Admin
				cFile(user); // Creates new user in file
				break;
			}
			else
			{
				cout << "\t\t\t\t Wrong MasterKey" << endl;
				cout << "\t\t\t\t Returning to Menu....";
				Sleep(1000);
				return;
			}
		}
		case 2:
		{
			user.type = 2; //Type 2 is for Guest
			cFile(user);
			break;
		}
		
		default:
			cout << "\t\t\t\t Invalid Option";
			exit(0);
			break;
		}
	}
	void cFile(Authentication& user)
	{
		Authentication temp;
		bool isFind = false; //Finds user with same type
		int TYPE = 0;
		ifstream rfile("User.txt", ios::binary);
		if (rfile.is_open())
		{
			
			while(rfile.read(reinterpret_cast<char*>(&temp), sizeof(temp)))
			{
				if (user.username == temp.username && user.type == temp.type)
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
			ofstream file("User.txt", ios::binary | ios::app);
			if (file.is_open())
			{
				file.write(reinterpret_cast<char*>(&user), sizeof(user));
				file.close();
			}
			cout << "\t\t\t\t Registration Successful \n\t\t\t\t Press Any Key to Continue......"<<endl;
			Sleep(1000);
		}
		else
		{
			cout << "\t\t\t\t Username already Exist" << endl;
			cout << "\t\t\t\t Returning to Menu...."<<endl;
			Sleep(1000);
		}
		TEMP();
	}
	
	void loginMenu()
	{
		int choice;
		while (true)
		{

			system("cls");
			cout << "\t\t\t\t **********************************************" << endl;
			cout << "\t\t\t\t # ========================================== #" << endl;
			cout << "\t\t\t\t # |                LOGIN FOR               | #" << endl;
			cout << "\t\t\t\t # |                                        | #" << endl;
			cout << "\t\t\t\t # |          ::Select From Below::         | #" << endl;
			cout << "\t\t\t\t # |                                        | #" << endl;
			cout << "\t\t\t\t # |          1. Admin                      | #" << endl;
			cout << "\t\t\t\t # |          2. Guest                      | #" << endl;
			cout << "\t\t\t\t # |          3. Staff                      | #" << endl;
			cout << "\t\t\t\t # |          4. Manager                    | #" << endl;
			cout << "\t\t\t\t # |          5. Exit                       | #" << endl;
			cout << "\t\t\t\t # |                                        | #" << endl;
			cout << "\t\t\t\t # ========================================== #" << endl;
			cout << "\t\t\t\t **********************************************" << endl;
			cout << "\t\t\t\t Enter Your Choice: ";
			cin >> choice;
			switch (choice)
			{
			case 1:
			{
				login(choice);
				break;
			}
			case 2:
			{
				login(choice);
				break;
			}
			case 3:
			{
				loginStaff();
				break;
			}
			case 4:
			{
				loginManager();
				break;
			}
			case 5:
			{
				cout << "\t\t\t\t Returning to Main Menu.....";
				Sleep(1500);
				return;
				break;
			}
			default:
				cout << "\t\t\t\t Invalid Choice";
				Sleep(1000);
				break;
			}
		
		}


	}
	void login(int usertype)
	{
		system("cls");
		cout << "\t\t\t\t **********************************************" << endl;
		cout << "\t\t\t\t # ========================================== #" << endl;
		cout << "\t\t\t\t # |               LOGIN USER               | #" << endl;
		cout << "\t\t\t\t # ========================================== #" << endl;
		cout << "\t\t\t\t **********************************************" << endl;
		Authentication user,temp;
		cout << "\t\t\t\t Enter User Name: ";
		getline(cin >> ws, user.username);
		cout << "\t\t\t\t Enter Password: ";
		getline(cin >> ws, user.password);
		bool isFound = false;

		ifstream rfile("User.txt", ios::binary);
		if (rfile.is_open())
		{

			while (rfile.read(reinterpret_cast<char*>(&temp), sizeof(temp)))
			{
				if (user.username == temp.username && user.password == temp.password)
				{
					if (usertype == temp.type)
					{
						isLoggedin = true;
						rfile.close();
						break;
					}
				}
			}
			rfile.close();
		}
		if (isLoggedin)
		{
			if(usertype==1)
			{
				cout << "\t\t\t\t Admin Login Successful"<<endl;
				AdminMenu();
				Sleep(1000);
				

			}
			else if (usertype == 2)
			{
				cout << "\t\t\t\t Guest Login Successful" << endl;
				Sleep(1000);
				Guest gUser;
				gUser.GuestMenu();
			}
		}
		else
		{
			cout << "\t\t\t\t Invalid Username or Password" << endl;
			Sleep(1000);
			if (!isLoggedin)
			{
				loginMenu();
			}
		}
		
		
	}
	void loginStaff()
	{
		system("cls");
		cout << "\t\t\t\t **********************************************" << endl;
		cout << "\t\t\t\t # ========================================== #" << endl;
		cout << "\t\t\t\t # |               LOGIN STAFF              | #" << endl;
		cout << "\t\t\t\t # ========================================== #" << endl;
		cout << "\t\t\t\t **********************************************" << endl;
		Authentication user;
		cout << "\t\t\t\t Enter User Name: ";
		getline(cin >> ws, user.username);
		cout << "\t\t\t\t Enter Password: ";
		getline(cin >> ws, user.password);
		bool isFound = false;
		Staff temp;
		ifstream rfile("Manager.txt", ios::binary);
		if (rfile.is_open())
		{

			while (rfile.read(reinterpret_cast<char*>(&temp), sizeof(temp)))
			{
				if (user.username == temp.getstaffId() && user.password == temp.getpassword())
				{
					isLoggedin = true;
					rfile.close();
					break;
				}
				else
				{
					cout << "\t\t\t\t Invalid Username or Password" << endl;
					Sleep(1000);
					if (!isLoggedin)
					{
						loginMenu();
					}
				}
			}
			rfile.close();
		}
		if (isLoggedin)
		{
			cout << "\t\t\t\t Staff Login Successful" << endl;
			Sleep(1000);
			staffMenu();
		}
		else
		{
			TEMP();
		}
	}


	void loginManager()
	{
		system("cls");
		cout << "\t\t\t\t **********************************************" << endl;
		cout << "\t\t\t\t # ========================================== #" << endl;
		cout << "\t\t\t\t # |               LOGIN MANAGER            | #" << endl;
		cout << "\t\t\t\t # ========================================== #" << endl;
		cout << "\t\t\t\t **********************************************" << endl;
		Authentication user;
		cout << "\t\t\t\t Enter User Name: ";
		getline(cin >> ws, user.username);
		cout << "\t\t\t\t Enter Password: ";
		getline(cin >> ws, user.password);
		bool isFound = false;
		Manager temp;
		ifstream rfile("Manager.txt", ios::binary);
		if (rfile.is_open())
		{

			while (rfile.read(reinterpret_cast<char*>(&temp), sizeof(temp)))
			{
				if (user.username == temp.getManId() && user.password == temp.getpassword())
				{
						isLoggedin = true;
						rfile.close();
						break;
				}
				else
				{
					cout << "\t\t\t\t Invalid Username or Password" << endl;
					Sleep(1000);
					if (!isLoggedin)
					{
						loginMenu();
					}
				}
			}
			rfile.close();
		}
		if (isLoggedin)
		{
				cout << "\t\t\t\t Manager Login Successful" << endl;
				Sleep(1000);
				managerMenu();
		}
		else
		{
			TEMP();
		}
	}
};

