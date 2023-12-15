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
public:
	void login()
	{
		int choice;
		system("cls");
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
	}
	void cFile()
	{
		ofstream file("User.txt", ios::app);
		if (file.is_open())
		{
			extern bool isAdmin;
			file << username + "$" + password + "$" << isAdmin << endl;
			file.close();
		}
		cout << "\t\t\t\t Registration Successful \n\t\t\t\t Press Any Key to Continue......";
	}
	bool checkExist(int userType)
	{
		string temp, line;
		bool isName = false;
		bool isUser = false;
		ifstream rfile("User.txt");
		if (rfile.is_open())
		{
			while (getline(rfile, line))
			{
				if (!line.length() == 0)
				{
					stringstream ss(line);
					getline(ss, temp,'$');
					if (temp == username)
					{
						isName = true;
					}
					getline(ss, temp, '$');
					getline(ss, temp, '$');
					int check = stoi(temp);
					if (check == userType)
					{
						isUser = true;
					}
				}
				if (isName && isUser)
				{
					return true;
				}
			}
			rfile.close();
			
		}
		return false;
	}
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
		extern string Masterkey;
		extern bool isAdmin;
		switch (choice)
		{
		case 1:
		{	
			string key;
			cout << "\t\t\t\t Enter MasterKey: ";
			getline(cin >> ws, key);
			if (key == Masterkey)
			{
				isAdmin = true;
				if (!checkExist(1))
				{
					cFile();
				}
				else
				{
					cout << "\t\t\t\t Username already Exist"<<endl;
					cout << "\t\t\t\t Returning to Menu....";
					Sleep(1000);
					return;
				}
				
				break;
			}
			else
			{
				cout << "\t\t\t\t Wrong MasterKey" <<endl;
				cout << "\t\t\t\t Returning to Menu....";
				Sleep(1000);
				return;
			}
		}
		case 2:
		{
			isAdmin = false;
			if (!checkExist(0))
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
	

};

