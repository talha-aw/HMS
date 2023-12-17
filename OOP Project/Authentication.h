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
	string isadmin;
public:
	void setisadmin()
	{
		extern bool isAdmin;
		isadmin = isAdmin;
	}
	
	
	string getusername()
	{
		return username;
	}
	string getpassword()
	{
		return password;
	}

	string getisadmin()
	{
		return isadmin;
	}

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
		cout << "\t\t\t\t # |                                        | #" << endl;
		cout << "\t\t\t\t # ========================================== #" << endl;
		cout << "\t\t\t\t **********************************************" << endl;
		cout << "\t\t\t\t Enter Your Choice: ";
		cin >> choice;

	}



	void cFile(Authentication& user)
	{
		
		ofstream file("User.txt", ios::binary | ios::app);
		if (file.is_open())
		{
			file.write(reinterpret_cast<char*>(&user), sizeof(Authentication));
			file.close();
		}
		cout << "\t\t\t\t Registration Successful \n\t\t\t\t Press Any Key to Continue......";
		_getch();
	}
	bool checkExist(int userType,Authentication& user)
	{
		Authentication temp;
		string name;
		string is;
		name = user.getusername();
		is = user.getisadmin();
		bool isFound = false;
		ifstream rfile("User.txt",ios::binary);
		if (rfile.is_open())
		{

			while (rfile.read(reinterpret_cast<char*>(&temp),sizeof(Authentication)))
			{
				
			}
		}
		rfile.close();

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
		Authentication user;
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
				
				if (0) 
				{
					user.isadmin = "1";
					cFile(user);
				}
				else
				{
					if (!checkExist(1,user))
					{
						user.isadmin = "1";
						cFile(user);
					}
					else
					{
						cout << "\t\t\t\t Username already Exist"<<endl;
						cout << "\t\t\t\t Returning to Menu....";
						Sleep(1000);
						return;
					}
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
			if (!checkExist(0,user))
			{
				isAdmin = false;
				cFile(user);
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

