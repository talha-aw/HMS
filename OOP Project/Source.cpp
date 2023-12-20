#include<iostream>
#include<conio.h>
#include<string>
#include<string.h>
#include<windows.h>
#include<fstream>
#include<chrono>
#include<iomanip>
#include<iomanip>

#include"Authentication.h";
#include"BasicInfo.h";

using namespace std;
string Masterkey = "1234";
string loggedUser;
bool isLoggedin = false;






int main()
{
	Guest a;
	a.setInfo();
	a.Registration();
	/*Authentication a;
	a.loginMenu();*/
	return 0;
}

