#include<iostream>
#include<conio.h>
#include<string>
#include<string.h>
#include<windows.h>
#include<fstream>
#include<sstream>
#include<iomanip>
#include<chrono>
#include"Authentication.h"
using namespace std;

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

void menu()
{
	cout << "\t\t\t\t   ____  ____ _____.   . ___  .     ." << endl;
	cout << "\t\t\t\t /     |    |  |  |   ||   | |\\   /|" << endl;
	cout << "\t\t\t\t |   ---|    |  |  |---||---| | \\ / |" << endl;
	cout << "\t\t\t\t  \\____||____|  |  |   ||   | |  V  |" << endl;
	cout << "\t\t\t\t .   . ___ _____ ___ .   " << endl;
	cout << "\t\t\t\t |   ||   |  |  |    |   " << endl;
	cout << "\t\t\t\t |---||   |  |  |--- |   " << endl;
	cout << "\t\t\t\t |   ||___|  |  |___ |___" << endl;

	cout << "\t\t\t\t **********************************************" << endl;
	cout << "\t\t\t\t # ========================================== #" << endl;
	cout << "\t\t\t\t # |             ::MAIN MENU::              | #" << endl;
	cout << "\t\t\t\t # |                                        | #" << endl;
	cout << "\t\t\t\t # |            1. Sign Up                  | #" << endl;
	cout << "\t\t\t\t # |            2. Login                    | #" << endl;
	cout << "\t\t\t\t # |            3. About                    | #" << endl;
	cout << "\t\t\t\t # |            4. Exit                     | #" << endl;
	cout << "\t\t\t\t # ========================================== #" << endl;
	cout << "\t\t\t\t **********************************************" << endl;
	int choice;
	cout << "\t\t\t\t Enter Choice";
	cin >> choice;
	switch (choice)
	{
	case 1:
	{
		extern bool isLoggedin;
		if (!isLoggedin)
		{
			Authentication user;
			user.signup();
		}
		break;
	}
	case 2:
	{
		Authentication user;
		user.loginMenu();
		break;
	}
	default:
		break;
	}
}


void start()
{
	display();
	menu();
	
}