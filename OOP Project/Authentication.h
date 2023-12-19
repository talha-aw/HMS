#include<iostream>
#include<conio.h>
#include<string>
#include<string.h>
#include<windows.h>
#include<fstream>
#include<sstream>
using namespace std;
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
		system("cls");
		cout << "\t\t\t\t **********************************************" << endl;
		cout << "\t\t\t\t # ========================================== #" << endl;
		cout << "\t\t\t\t # |          ACCOUNT REGISTRATION          | #" << endl;
		cout << "\t\t\t\t # ========================================== #" << endl;
		cout << "\t\t\t\t **********************************************" << endl;
		cout << "\t\t\t\t Enter User Name: ";
		getline(cin >> ws, username);
		cout << "\t\t\t\t Enter Password: ";
		getline(cin >> ws, password);

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
				type = 1; //Type 1 is for Admin
				if (checkExist(type))
				{
					cFile(); // Creates new user in file
				}
				else
				{
					cout << "\t\t\t\t Username already Exist" << endl;
					cout << "\t\t\t\t Returning to Menu....";
					Sleep(1000);
					return;
				}

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
			type = 2; //Type 2 is for Guest
			if (checkExist(type))
			{
				cFile();
			}
			else
			{
				cout << "\t\t\t\t Username already Exist" << endl;
				cout << "\t\t\t\t Returning to Menu....";
				Sleep(1000);
				return;
			}
			break;
		}
		
		default:
			cout << "\t\t\t\t Invalid Option";
			break;
		}
	}
	void cFile()
	{
		ofstream file("User.txt", ios::app);
		if (file.is_open())
		{
			file << username + "~" + password + "~" << type << endl;
			file.close();
		}
		cout << "\t\t\t\t Registration Successful \n\t\t\t\t Press Any Key to Continue......";
	}
	bool checkExist(int Type)
	{
		string temp, line; // File reading Variables
		bool isName = false; //Finds user with same name
		bool isType = false; //Finds user with same type
		int TYPE = 0;
		ifstream rfile("User.txt");
		if (rfile.is_open())
		{
			while (getline(rfile, line))
			{
				if (!line.length() == 0) //Ignores Blank Spaces in File
				{
					stringstream ss(line);
					getline(ss, temp, '~');
					if (temp == username)
					{
						isName = true;
					}
					getline(ss, temp, '~'); //ignoring this line till ~
					getline(ss, temp, '~');
					TYPE = stoi(temp); //Converting string number into Integer

					if (TYPE == type)
					{
						isType = true;
					}
				}
				if (isName && isType) //checks if username and type is same or not
				{
					rfile.close();
					return false;
				}
			}
			rfile.close();

		}
		return true;
	}
	int loginMenu()
	{
		int choice;
		system("cls");
		cout << "\t\t\t\t **********************************************" << endl;
		cout << "\t\t\t\t # ========================================== #" << endl;
		cout << "\t\t\t\t # |            REGISTRATION FOR            | #" << endl;
		cout << "\t\t\t\t # |                                        | #" << endl;
		cout << "\t\t\t\t # |          ::Select From Below::         | #" << endl;
		cout << "\t\t\t\t # |                                        | #" << endl;
		cout << "\t\t\t\t # |          1. Admin                      | #" << endl;
		cout << "\t\t\t\t # |          2. Staff                      | #" << endl;
		cout << "\t\t\t\t # |          3. Guest                      | #" << endl;
		cout << "\t\t\t\t # |                                        | #" << endl;
		cout << "\t\t\t\t # ========================================== #" << endl;
		cout << "\t\t\t\t **********************************************" << endl;
		cout << "\t\t\t\t Enter Your Choice: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
		{
			if (login(choice) == choice)
			{
				cout << "\t\t\t\t Admin Login Successful";
				return 1;
			}
			else
			{
				cout << "\t\t\t\t Invalid Username or Password";
			}
			break;
		}
		case 2:
		{
			if (login(choice) == choice)
			{
				cout << "\t\t\t\t Staff Login Successful";
				return 2;
			}
			else
			{
				cout << "\t\t\t\t Invalid Username or Password";
			}
			break;
		}
		case 3:
		{
			if (login(choice) == choice)
			{
				cout << "\t\t\t\t Guest Login Successful";
				return 3;
			}
			else
			{
				cout << "\t\t\t\t Invalid Username or Password";
			}
			break;
		}
		default:
			return 0;
			break;
		}
		


	}
	int login(int usertype)
	{
		system("cls");
		cout << "\t\t\t\t **********************************************" << endl;
		cout << "\t\t\t\t # ========================================== #" << endl;
		cout << "\t\t\t\t # |               LOGIN USER               | #" << endl;
		cout << "\t\t\t\t # ========================================== #" << endl;
		cout << "\t\t\t\t **********************************************" << endl;
		cout << "\t\t\t\t Enter User Name: ";
		getline(cin >> ws, username);
		cout << "\t\t\t\t Enter Password: ";
		getline(cin >> ws, password);

		string temp, line;
		ifstream rFile;
		rFile.open("User.txt");
		if (rFile.is_open())
		{
			while (!rFile.eof())
			{
				getline(rFile, line);
				stringstream ss(line);
				getline(ss, temp, '~');
				if (temp == username)
				{
					getline(ss, temp, '~');
					if (temp == password)
					{
						getline(ss, temp, '~');
						int TYPE = stoi(temp);
						if (TYPE == usertype)
						{
							extern string loggedUser; //Accessing Global Variables
							extern bool isLoggedin;
							loggedUser = username; //Assigning values to Global variables
							isLoggedin = true;
							return TYPE;
						}
					}
				}
			}
		}

	}

};

