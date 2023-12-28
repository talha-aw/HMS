#pragma once
#include<iostream>
#include<conio.h>
#include<string>
#include<string.h>
#include<windows.h>
#include<fstream>
#include<sstream>
#include<iomanip>
#include<chrono>
//#include"BasicInfo.h"
#include"Authentication.h"
using namespace std;
extern bool isLoggedin;

void display()
{
	system("cls");
	cout << "\t\t\t\t                   *                        *" << endl;
	cout << "\t\t\t\t                  **          *    *        **     " << endl;
	cout << "\t\t\t\t              ******          ******        ******   " << endl;
	cout << "\t\t\t\t             ********         ******        ******** " << endl;
	cout << "\t\t\t\t            *********         ******        *********   " << endl;
	cout << "\t\t\t\t           **********         ******        **********" << endl;
	cout << "\t\t\t\t          ************       ********       ***********" << endl;
	cout << "\t\t\t\t         **************     **********     *************" << endl;
	cout << "\t\t\t\t        *************************************************" << endl;
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
}

void MENU()
{
	while (true)
	{
		system("cls");
		cout << "\t\t\t\t\t  ____  ____ _____.   . ___  .     ." << endl;
		cout << "\t\t\t\t\t /     |    |  |  |   ||   | |\\   /|" << endl;
		cout << "\t\t\t\t\t|   ---|    |  |  |---||---| | \\ / |" << endl;
		cout << "\t\t\t\t\t \\____||____|  |  |   ||   | |  V  |" << endl;
		cout << "\t\t\t\t\t.   . ___ _____ ___ .   " << endl;
		cout << "\t\t\t\t\t|   ||   |  |  |    |   " << endl;
		cout << "\t\t\t\t\t|---||   |  |  |--- |   " << endl;
		cout << "\t\t\t\t\t|   ||___|  |  |___ |___" << endl;

		cout << "\t\t\t\t **********************************************" << endl;
		cout << "\t\t\t\t # ========================================== #" << endl;
		cout << "\t\t\t\t # |             ::MAIN MENU::              | #" << endl;
		cout << "\t\t\t\t # |                                        | #" << endl;
		cout << "\t\t\t\t # |            1. Sign Up                  | #" << endl;
		cout << "\t\t\t\t # |            2. Login                    | #" << endl;
		cout << "\t\t\t\t # |            3. About                    | #" << endl;
		cout << "\t\t\t\t # |            4. Sign Out                 | #" << endl;
		cout << "\t\t\t\t # |            5. Exit                     | #" << endl;
		cout << "\t\t\t\t # ========================================== #" << endl;
		cout << "\t\t\t\t **********************************************" << endl;
		int choice=0;
		cout << "\t\t\t\t Enter Choice: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
		{
			if (!isLoggedin)
			{
				Authentication user;
				user.signup();
			}
			else
			{
				cout << "\t\t\t\t User is Already Logged In" << endl;
				Sleep(1000);
			}
			break;
		}
		case 2:
		{
			Authentication user;
			if (!isLoggedin)
			{
				user.loginMenu();
			}
			else
			{
				user.loginMenu();
			}
			break;
		}
		case 4:
		{
			if (isLoggedin)
			{
				cout << "\t\t\t\t Sign out Successful";
				isLoggedin = false;
				Sleep(1000);
			}
			break;
		}
		case 5:
		{
			display();
			cout << "\t\t\t\t\t\t    WAYNE MANOR since 1989  ";
			Sleep(2000);
			exit(0);
		}
		default:
			cout << "\t\t\t\t Invalid Choice"<<endl;
			cout << "\t\t\t\t Try Again"<<endl;
			Sleep(1500);
			break;
		}
	}

}


