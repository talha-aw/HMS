#include<iostream>
#include<conio.h>
#include<string>
#include<string.h>
#include<windows.h>
#include<fstream>
#include<sstream>
#include<chrono>
#include<iomanip>
using namespace std;


class basicInfo //Abstract class
{
protected:
	string name;
	int age;
	string cnic;
	string address;
	string phone;
	string gender;
	string email;
public:
	virtual void displayInfo() = 0; // Pure virtual function
	virtual void setInfo() {};
};

class Guest :public basicInfo
{
private:
	string emgContact;
	long long int wallet;
	string check_in;
	string check_out;
	long int ReservationID;

public:
	void GuestMenu()
	{
		int choice;
		system("cls");
		cout << "\t\t\t\t **********************************************" << endl;
		cout << "\t\t\t\t # ========================================== #" << endl;
		cout << "\t\t\t\t # |             ::GUEST MENU::             | #" << endl;
		cout << "\t\t\t\t # |                                        | #" << endl;
		cout << "\t\t\t\t # |            1. Make Reservation         | #" << endl;
		cout << "\t\t\t\t # |            2. Show Details             | #" << endl;
		cout << "\t\t\t\t # |            3. Food Service             | #" << endl;
		cout << "\t\t\t\t # |            4. Check Out                | #" << endl;
		cout << "\t\t\t\t # |            5. Log out                  | #" << endl;
		cout << "\t\t\t\t # |                                        | #" << endl;
		cout << "\t\t\t\t # ========================================== #" << endl;
		cout << "\t\t\t\t **********************************************" << endl;
		cout << "Enter Your Choice: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
		{
			break;
		}
		case 2:
		{
			Details();
			break;
		}
		case 3:
		{
			break;
		}
		case 4:
		{
			break;
		}
		case 5:
		{
			break;
		}
		default:
			break;
		}
	
	
	
	}

	void Details()
	{
		int choice;
		system("cls");
		cout << "\t\t\t\t **********************************************" << endl;
		cout << "\t\t\t\t # ========================================== #" << endl;
		cout << "\t\t\t\t # |             ::DETAILS MENU::           | #" << endl;
		cout << "\t\t\t\t # |                                        | #" << endl;
		cout << "\t\t\t\t # |            1. Guest Details            | #" << endl;
		cout << "\t\t\t\t # |            2. Room Details             | #" << endl;
		cout << "\t\t\t\t # |            3. Exit                     | #" << endl;
		cout << "\t\t\t\t # |                                        | #" << endl;
		cout << "\t\t\t\t # ========================================== #" << endl;
		cout << "\t\t\t\t **********************************************" << endl;
		cout << "Enter Your Choice: ";
		cin >> choice;
		switch (choice)	
		{
		case 1:
		{
			int option;
			cout << "\t\t\t\t **********************************************" << endl;
			cout << "\t\t\t\t # ========================================== #" << endl;
			cout << "\t\t\t\t # |             ::DETAILS MENU::           | #" << endl;
			cout << "\t\t\t\t # |                                        | #" << endl;
			cout << "\t\t\t\t # |            1. Show Details             | #" << endl;
			cout << "\t\t\t\t # |            2. Update Details           | #" << endl;
			cout << "\t\t\t\t # |            3. Exit                     | #" << endl;
			cout << "\t\t\t\t # |                                        | #" << endl;
			cout << "\t\t\t\t # ========================================== #" << endl;
			cout << "\t\t\t\t **********************************************" << endl;
			cout << "\t\t\t\t Enter Choice: ";
			if (option == 1)
			{
				displayInfo();
				break;
			}
			else if (option == 2)
			{
				updateInfo();
			}

			break;
		}
		default:
			break;
		}



	}





	void displayInfo()
	{
		string temp, line;
		ifstream rfile;
		rfile.open("Guest.txt");
		int count = 1;
		while (!rfile.eof())
		{
			getline(rfile, line);
			if (!line.length() == 0)
			{
				cout << "\t\t\t\t # ========================================== #" << endl;
				cout << "\t\t\t\t # |               GUEST # " << count << "                 |# " << endl;
				cout << "\t\t\t\t # ========================================== #" << endl;
				stringstream ss(line);
				getline(ss, temp, '~');
				cout << "\t\t\t\t CNIC: " << temp <<endl;
				getline(ss, temp, '~');
				cout << "\t\t\t\t Name: " << temp << endl;
				getline(ss, temp, '~');
				cout << "\t\t\t\t Phone: " << temp << endl;
				getline(ss, temp, '~');
				cout << "\t\t\t\t Address: " << temp << endl;
				getline(ss, temp, '~');
				cout << "\t\t\t\t Gender: " << temp << endl;
				getline(ss, temp, '~');
				cout << "\t\t\t\t Emergency Contact: " << temp << endl;
				getline(ss, temp, '~');
				cout << "\t\t\t\t Email Id: " << temp << endl;
				count++;
			}
			cout << endl;
		}
		rfile.close();
	}
	void setInfo()
	{
		cout << "Enter Name: ";
		getline(cin >> ws, name);
		cout << "Enter Age: ";
		cin >> age;
		cout << "Enter CNIC: ";
		getline(cin >> ws, cnic);
		cout << "Enter Phone Number: ";
		getline(cin >> ws, phone);
		cout << "Enter Address: ";
		getline(cin >> ws, address);
		cout << "Enter Gender: ";
		getline(cin >> ws, gender);
		cout << "Enter Emergency Contact: ";
		getline(cin >> ws, emgContact);


		////To Store Current Time and Date
		//auto time = std::chrono::system_clock::now();
		//std::time_t now_c = std::chrono::system_clock::to_time_t(time);

		//
		//struct tm timeInfo;
		//localtime_s(&timeInfo, &now_c);

		//stringstream ss;
		//ss << std::put_time(&timeInfo, "%Y-%m-%d %H:%M:%S");
		//getline(ss, check_in);

	}



	void Registration()
	{
		ofstream file;
		file.open("Guest.txt", ios::app);
		file << cnic + "~" + name + "~" + phone + "~" + address + "~" + gender + "~" + emgContact + "~" + email << endl;
		cout << "Registration Successful";
		file.close();
	}
	void update_details()
	{

	}
};
