#include<iostream>
#include<conio.h>
#include<string>
#include<string.h>
#include<windows.h>
#include<fstream>
#include "global.h"

using namespace std;



//class Employees
//{
//private:
//	string name;
//	string id;
//	int age;
//	string cnic;
//	string address;
//	string phone;
//	string gender;
//
//public:
//	Employees();
//	~Employees();
//
//	void input();
//};
//
//
//Employee::Employee()
//{
//}
//
//Employee::~Employee()
//{
//}
int main()
{
	MyClass my;
	my.name = "Talha";
	my.id = 10;
	MyClass my1;
	my1.name = "Huzaifa";
	my1.id = 20;

	my1=tempaMethod<MyClass>(my, my1);
	cout << my1.name << my1.id;
	global();
	Talha();
	return 0;
}
//
//void Start()
//{
//	system("cls");
//	int option;
//	cout << "\t\t\t\t ********************************\n";
//	cout << "\t\t\t\t |                                *\n";
//	cout << "\t\t\t\t |      Hotel Managment System       *\n";
//	cout << "\t\t\t\t |                                *\n";
//	cout << "\t\t\t\t ********************************\n";
//	cout << "\t\t\t\t ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
//	cout << "\t\t\t\t ::Enter Your Choice::" << endl;
//	cout << "\t\t\t\t 1: Admin" << endl;
//	cout << "\t\t\t\t 2: Staff" << endl;
//	cout << "\t\t\t\t 3: Guest" << endl;
//	cout << "\t\t\t\t 4: Exit" << endl;
//	cout << "\t\t\t\t Enter: ";
//	cin >> option;
//	switch (option)
//	{
//	case 1:
//	{
//		Admin();
//		break;
//	}
//	/*case 2:
//	{
//		Staff();
//		break;
//	}
//	case 3:
//	{
//		Guest();
//		break;
//	}
//	case 4:
//	{
//		Exit();
//		break;
//	}*/
//
//	default:
//		break;
//	}
//}
//
//
//void Admin()
//{
//	system("cls");
//	int option;
//	cout << "\t\t\t\t ********************************\n";
//	cout << "\t\t\t\t |                                *\n";
//	cout << "\t\t\t\t |           Admin Block           *\n";
//	cout << "\t\t\t\t |                                *\n";
//	cout << "\t\t\t\t ********************************\n";
//	cout << "\t\t\t\t ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
//	cout << "\t\t\t\t ::Enter Your Choice::" << endl;
//	cout << "\t\t\t\t 1: Manager Management" << endl;
//	cout << "\t\t\t\t 2: Staff Management" << endl;
//	cout << "\t\t\t\t 3: Room Management" << endl;
//	cout << "\t\t\t\t 4: Exit" << endl;
//	cout << "\t\t\t\t Enter: ";
//	
//}