#include<iostream>
#include<conio.h>
#include<string>
#include<string.h>
#include<windows.h>
#include<fstream>
#include"Authentication.h";
using namespace std;
string Masterkey = "1234";
string loggedUser;
bool isLoggedin = false;



void display()
{
	cout << "\t\t\t\t                   *                        *" << endl;
	cout << "\t\t\t\t                  **          *    *        **     " << endl;
	cout << "\t\t\t\t              ******          ******        ******   " << endl;
	cout << "\t\t\t\t             ********         ******        ******** " << endl;
	cout << "\t\t\t\t            *********         ******        *********   " << endl;
	cout << "\t\t\t\t           **********         ******        **********" << endl;
	cout << "\t\t\t\t          ************       ********       ***********" << endl;
	cout << "\t\t\t\t        ***************     **********     *************" << endl;
	cout << "\t\t\t\t       *******  ____  ____ _____.   . ___  .     .*******" << endl;
	cout << "\t\t\t\t      ******** /     |    |  |  |   ||   | |\\   /|********" << endl;
	cout << "\t\t\t\t     *********|   ---|    |  |  |---||---| | \\ / |*********" << endl;
	cout << "\t\t\t\t     ********* \\____||____|  |  |   ||   | |  V  |*********" << endl;
	cout << "\t\t\t\t     ***************.   . ___ _____ ___ .   ***************" << endl;
	cout << "\t\t\t\t     ***************|   ||   |  |  |    |   ***************" << endl;
	cout << "\t\t\t\t     ***************|---||   |  |  |--- |   ***************" << endl;
	cout << "\t\t\t\t      **************|   ||___|  |  |___ |___**************" << endl;
	cout << "\t\t\t\t       **************************************************" << endl;
	cout << "\t\t\t\t        ********   ******  **********  ******   ********" << endl;
	cout << "\t\t\t\t         ******      ***    *******     ***     ******" << endl;
	cout << "\t\t\t\t          *****       *     ******       *      *****" << endl;
	cout << "\t\t\t\t           ****              ****               ****" << endl;
	cout << "\t\t\t\t            ***               **                ***" << endl;
	cout << "\t\t\t\t              *               **                *" << endl;
	cout << "\t\t\t\t                              **                   " << endl;
	_getch();

}


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
	display();
	Authentication a;
	a.loginMenu();
	return 0;
}

