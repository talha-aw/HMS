#include<iostream>
#include<conio.h>
#include<string>
#include<string.h>
#include<windows.h>
#include<fstream>
#include<chrono>
#include<iomanip>
//#include"Admin.h";
//#include"Reservation.h";

//#include"Authentication.h";

#include "MainMenu.h"
using namespace std;
string Masterkey = "1234";
string loggedUser;
bool isLoggedin = false;

void start();




int main()
{
	/*Reservation a;
	a.makeReservation();*/
	//start();
	//addManager();

	//addRoom();
	Authentication a;
	a.loginMenu();
	return 0;
}

