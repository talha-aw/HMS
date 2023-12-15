#include<iostream>
#include<conio.h>
#include<string>
#include<string.h>
#include<windows.h>
#include<fstream>
#include"Authentication.h";
using namespace std;
bool isAdmin = false;
string Masterkey = "1234";



class Employees
{
private:
	string name;
	string id;
	int age;
	string cnic;
	string address;
	string phone;
	string gender;

public:
	Employees();
	~Employees();

	void input();
};


int main()
{

	Authentication a;
	a.signup();
	return 0;
}

void Start()
{
	system("cls");
	int option;
	cout << "\t\t\t\t ********************************\n";
	cout << "\t\t\t\t |                                *\n";
	cout << "\t\t\t\t |      Hotel Managment System       *\n";
	cout << "\t\t\t\t |                                *\n";
	cout << "\t\t\t\t ********************************\n";
	cout << "\t\t\t\t ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "\t\t\t\t ::Enter Your Choice::" << endl;
	cout << "\t\t\t\t 1: Admin" << endl;
	cout << "\t\t\t\t 2: Staff" << endl;
	cout << "\t\t\t\t 3: Guest" << endl;
	cout << "\t\t\t\t 4: Exit" << endl;
	cout << "\t\t\t\t Enter: ";
	cin >> option;
	switch (option)
	{
	case 1:
	{

		break;
	}
	/*case 2:
	{
		Staff();
		break;
	}
	case 3:
	{
		Guest();
		break;
	}
	case 4:
	{
		Exit();
		break;
	}*/

	default:
		break;
	}
}

