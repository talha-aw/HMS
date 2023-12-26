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
	virtual void setInfo() {}; //virtual
};

class Guest :public basicInfo
{
private:
	bool isRegistered;
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
			Guest gUser;
			gUser.setInfo();
			gUser.Registration(gUser);
			cout << "Registration Successful..";
			Sleep(1000);
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
			cin >> option;
			if (option == 1)
			{
				displayInfo();
				break;
			}
			else if (option == 2)
			{
				//updateInfo();
			}

			break;
		}
		default:
			break;
		}



	}

	void displayInfo()
	{
		Guest temp;
		ifstream rfile;
		rfile.open("Guest.txt",ios::binary);
		if(rfile.read(reinterpret_cast<char*>(&temp), sizeof(temp)))
		{
			if (rfile.is_open())
			{
				while (!rfile.eof())
				{
					rfile.read(reinterpret_cast<char*>(&temp), sizeof(temp));
					cout << "\t\t\t\t CNIC: " << temp.cnic << endl;
					cout << "\t\t\t\t Name: " << temp.name << endl;
					cout << "\t\t\t\t Phone: " << temp.phone << endl;
					cout << "\t\t\t\t Address: " << temp.address << endl;
					cout << "\t\t\t\t Gender: " << temp.gender << endl;
					cout << "\t\t\t\t Emergency Contact: " << temp.emgContact << endl;
					cout << "\t\t\t\t Email Id: " << temp.email << endl;
					cout << endl;
				}
			}
		}
		rfile.close();
		cout << "\t\t\t\t Press Any key to Continue...."<<endl;
		_getch();
		GuestMenu();
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
		cout << "Enter Email: ";
		getline(cin >> ws, email);
		cout << "Enter Amount in Your Hotel's Wallet: ";
		cin >> wallet;
		isRegistered = true;

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



	void Registration(Guest& temp)
	{
		ofstream file;
		file.open("Guest.txt", ios::app|ios::binary);
		file.write(reinterpret_cast<char*>(&temp), sizeof(temp));
		file.close();
	}
	void update_details()
	{

	}
};

class Staff :public basicInfo {
private:
	string staffId;
	string Role;
	double Salary;
	string Shift;
	string password;
	friend void addStaff();
public:
	string getstaffId()
	{
		return staffId;
	}
	string getpassword()
	{
		return password;
	}

	void displayInfo()
	{
		Staff temp;
		ifstream rfile;
		rfile.open("Staff.txt", ios::binary);
		if (rfile.read(reinterpret_cast<char*>(&temp), sizeof(temp)))
		{
			if (rfile.is_open())
			{
				while (!rfile.eof())
				{
					rfile.read(reinterpret_cast<char*>(&temp), sizeof(temp));
					cout << "\t\t\t\t Id: " << temp.staffId << endl;
					cout << "\t\t\t\t CNIC: " << temp.cnic << endl;
					cout << "\t\t\t\t Name: " << temp.name << endl;
					cout << "\t\t\t\t Phone: " << temp.phone << endl;
					cout << "\t\t\t\t Address: " << temp.address << endl;
					cout << "\t\t\t\t Gender: " << temp.gender << endl;
					cout << "\t\t\t\t Role: " << temp.Role << endl;
					cout << "\t\t\t\t Salary: " << temp.Salary << endl;
					cout << "\t\t\t\t Shift: " << temp.Shift << endl;
				}
			}
		}
		rfile.close();
		cout << "\t\t\t\t Press Any key to Continue...." << endl;
		system("pause");
	}
	void Registration(Staff& temp)
	{
		ofstream file;
		file.open("Staff.txt", ios::app | ios::binary);
		file.write(reinterpret_cast<char*>(&temp), sizeof(temp));
		file.close();
	}

	void updateinfo()
	{
		Staff user, temp;
		int size = sizeof(temp);
		fstream file("Staff.txt", ios::binary | ios::in | ios::out);
		cout << "Enter Staff ID you want to Update: ";
		getline(cin >> ws, user.staffId);
		if (file.is_open())
		{
			file.read(reinterpret_cast<char*>(&temp), sizeof(temp));
			if (temp.staffId == user.staffId)
			{
				cout << "Enter Updated Name: ";
				getline(cin >> ws, user.name);
				cout << "Enter Updated Age: ";
				cin >> user.age;
				cout << "Enter Updated CNIC: ";
				getline(cin >> ws, user.cnic);
				cout << "Enter Updated Phone Number: ";
				getline(cin >> ws, user.phone);
				cout << "Enter Updated Address: ";
				getline(cin >> ws, user.address);
				cout << "Enter Updated Gender: ";
				getline(cin >> ws, user.gender);
				cout << "Enter Updated Role: ";
				getline(cin >> ws, user.Role);
				cout << "Enter Updated Shift: ";
				getline(cin >> ws, user.Shift);
				cout << "Enter Updated Password: ";
				getline(cin >> ws, user.password);

				user.Salary = 50000;
				file.seekp(-size, ios::cur);
				file.write(reinterpret_cast<char*>(&user), sizeof(user));
				file.close();
				cout << "\t\t\t\t Staff info Updated Successfully";
				_getch();
			}
		}
	}
};
class Manager :public basicInfo {
private:
	string ManId;
	double Salary;
	string password;
public:
	string getManId()
	{
		return ManId;
	}
	string getpassword()
	{
		return password;
	}

	friend void addManager();
	
	void displayInfo()
	{
		Manager temp;
		ifstream rfile;
		rfile.open("Manager.txt", ios::binary);


		if (rfile.read(reinterpret_cast<char*>(&temp), sizeof(temp)))
		{
			if (rfile.is_open())
			{
				while (!rfile.eof())
				{
					rfile.read(reinterpret_cast<char*>(&temp), sizeof(temp));
					cout << "\t\t\t\t CNIC: " << temp.cnic << endl;
					cout << "\t\t\t\t Name: " << temp.name << endl;
					cout << "\t\t\t\t Phone: " << temp.phone << endl;
					cout << "\t\t\t\t Address: " << temp.address << endl;
					cout << "\t\t\t\t Gender: " << temp.gender << endl;
					cout << "\t\t\t\t Id: " << temp.ManId << endl;
					cout << "\t\t\t\t Salary: " << temp.Salary << endl;
				}
			
			}

		}
				rfile.close();
				cout << "\t\t\t\t Press Any key to Continue...." << endl;
				_getch();
		//managerMenu();
	}
	void Registration(Manager& temp)
	{
		ofstream file;
		file.open("Manager.txt", ios::app | ios::binary);
		file.write(reinterpret_cast<char*>(&temp), sizeof(temp));
		file.close();
		cout << "Registration Successful..";
	}

	void updateinfo()
	{
		Manager user, temp;
		int size = sizeof(temp);
		fstream file("Manager.txt", ios::binary | ios::in | ios::out);
		cout << "Enter Manager ID you want to Update: ";
		getline(cin >> ws, user.ManId);
		if (file.is_open())
		{
			file.read(reinterpret_cast<char*>(&temp), sizeof(temp));
			if (temp.ManId == user.ManId)
			{
				cout << "Enter Updated Name: ";
				getline(cin >> ws, user.name);
				cout << "Enter Updated Age: ";
				cin >> user.age;
				cout << "Enter Updated CNIC: ";
				getline(cin >> ws, user.cnic);
				cout << "Enter Updated Phone Number: ";
				getline(cin >> ws, user.phone);
				cout << "Enter Updated Address: ";
				getline(cin >> ws, user.address);
				cout << "Enter Updated Gender: ";
				getline(cin >> ws, user.gender);
				cout << "Enter Updated Password: ";
				getline(cin>>ws, user.password);
				user.Salary = 300000;
				file.seekp(-size,ios::cur);
				file.write(reinterpret_cast<char*>(&user), sizeof(user));
				file.close();
				cout << "\t\t\t\t Manager info Updated Successfully";
				_getch();
			}
		}

	}


};