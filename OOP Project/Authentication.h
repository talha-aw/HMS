#include<iostream>
#include<conio.h>
#include<string>
#include<string.h>
#include<windows.h>
#include<fstream>
using namespace std;
class Authentication
{
private:
	string username;
	string password;
public:
	void login()
	{
		system("cls");

	}
	void cFile()
	{
		ofstream file("User.txt", ios::app);

	}
	void checkExist()
	{
		ifstream rfile("User.txt");
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
				cFile();
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
			isAdmin = false;
			break;
		default:
			cout << "\t\t\t\t Invalid Option";
			break;
		}
	}
	

};

