#pragma once
#include<iostream>
#include<conio.h>
#include<string>
#include<string.h>
#include<windows.h>
#include<fstream>
#include<sstream>
#include<ctime>
#include"Reservation.h";
#include"Rooms.h";
void MENU();
void ReserveMenu();
using namespace std;
extern bool isAdmin;
extern bool isLoggedin;
extern string loggedUser;
void managerMenu();
void AmanagerMenu();
void AstaffMenu();
void staffMenu();
void foodMenu();



template<class X>
class basicInfo //Abstract class
{
protected:
	X name;
	int age;
	X cnic;
	X address;
	X phone;
	X gender;
	X email;
public:
	virtual void displayInfo() = 0; // Pure virtual function
	virtual void setInfo() {}; //virtual
	virtual void updateInfo() {};
	X getcnic()
	{
		return cnic;
	}
};
template<class X,class Y>
class Guest :public basicInfo<X>
{
private:
	bool isRegistered;
	Y emgContact;
	long long int wallet;
protected:
	Y check_in;
	Y check_out;
	long double bill;
	long double fbill;

public:
	
	long double getbill()
	{
		return bill;
	}
	long double getfbill()
	{
		return fbill;
	}
	void setbill(int roombill,Guest<string,string>&G )
	{
		if (G.bill <  0)
		{
			G.bill = roombill;
		}
		else
		{
			G.bill += roombill;
		}
	}
	void setfbill(int roombill,Guest<string,string>& G)
	{
		if (G.fbill < 0)
		{
			G.fbill = roombill;
		}
		else
		{
			G.fbill += roombill;
		}
	}
	void GuestMenu()
	{
		int choice=0;
		system("cls");
		cout << "\t\t\t\t **********************************************" << endl;
		cout << "\t\t\t\t # ========================================== #" << endl;
		cout << "\t\t\t\t # |             ::GUEST MENU::             | #" << endl;
		cout << "\t\t\t\t # |                                        | #" << endl;
		cout << "\t\t\t\t # |            1. Make Reservation         | #" << endl;
		cout << "\t\t\t\t # |            2. Details                  | #" << endl;
		cout << "\t\t\t\t # |            3. Food Service             | #" << endl;
		cout << "\t\t\t\t # |            4. Check Out                | #" << endl;
		cout << "\t\t\t\t # |            5. Log out                  | #" << endl;
		cout << "\t\t\t\t # |                                        | #" << endl;
		cout << "\t\t\t\t # ========================================== #" << endl;
		cout << "\t\t\t\t **********************************************" << endl;
		start:
		cout << "Enter Your Choice: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
		{
			ReserveMenu();
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
			foodMenu();
			break;
		}
		case 4:
		{
			checkOut();
			break;
		}
		case 5:
		{
			isLoggedin = false;
			loggedUser.clear();
			MENU();
			break;
		}
		default:
			cout << "\t\t\t\t Invalid Choice" << endl;
			cout << "\t\t\t\t Try Again" << endl;
			cin.clear();
			while (cin.get() != '\n')
			{
				continue;
			}
			Sleep(1500);
			goto start;
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
		start:
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
			start2:
			cout << "\t\t\t\t Enter Choice: ";
			cin >> option;
			if (option == 1)
			{
				displayInfo();
				break;
			}
			else if (option == 2)
			{
				updateInfo();
			}
			else if (option == 3)
			{
				cout << "Returning to Guest Menu....";
				Sleep(1000);
				GuestMenu();
			}
			else
			{
				cout << "\t\t\t\t Invalid Choice" << endl;
				cout << "\t\t\t\t Try Again" << endl;
				cin.clear();
				while (cin.get() != '\n')
				{
					continue;
				}
				Sleep(1500);
				goto start;
			}

			break;
		}
		case 2:
		{
			Room<string> R;
			R.displayRoom();
			break;
		}
		default:
			cout << "\t\t\t\t Invalid Choice" << endl;
			cout << "\t\t\t\t Try Again" << endl;
			cin.clear();
			while (cin.get() != '\n')
			{
				continue;
			}
			Sleep(1500);
			goto start;
			break;
		}



	}
	void displayInfo()
	{
		Guest <string,string> temp;
		ifstream rfile;
		int count = 0;
		rfile.open("Guest.txt",ios::binary);
		if(rfile.read(reinterpret_cast<char*>(&temp), sizeof(temp)))
		{
			if (rfile.is_open())
			{
				while (!rfile.eof())
				{
					cout << "\t\t\t\t CNIC: " << temp.cnic << endl;
					cout << "\t\t\t\t Name: " << temp.name << endl;
					cout << "\t\t\t\t Phone: " << temp.phone << endl;
					cout << "\t\t\t\t Address: " << temp.address << endl;
					cout << "\t\t\t\t Gender: " << temp.gender << endl;
					cout << "\t\t\t\t Emergency Contact: " << temp.emgContact << endl;
					cout << "\t\t\t\t Email Id: " << temp.email << endl;
					cout << endl;
					rfile.read(reinterpret_cast<char*>(&temp), sizeof(temp));
				}
			}
		}
		rfile.close();
		cout << "\t\t\t\t Press Any key to Continue...."<<endl;
		_getch();
		GuestMenu();
	}
	void updateInfo()
	{
		Guest <string,string> user, temp;
		cout << "Enter CNIC you want to update: ";
		getline(cin >> ws, user.cnic);
		int size = sizeof(temp);
		fstream in_out_file("Guest.txt", ios::binary | ios::in|ios::out);
		if (in_out_file.is_open())
		{
			while (in_out_file.read(reinterpret_cast<char*>(&temp), sizeof(temp)))
			{
				if (temp.cnic == user.cnic)
				{
					cout << "Enter Updated Name: ";
					getline(cin >> ws, user.name);
					cout << "Enter Updated Age: ";
					cin >> user.age;
					cout << "Enter Updated Phone Number: ";
					getline(cin >> ws, user.phone);
					cout << "Enter Updated Address: ";
					getline(cin >> ws, user.address);
					cout << "Enter Updated Gender: ";
					getline(cin >> ws, user.gender);
					cout << "Enter Updated Emergency Contact: ";
					getline(cin >> ws, user.emgContact);
					cout << "Enter Updated Email: ";
					getline(cin >> ws, user.email);
					cout << "Enter Updated Amount in Your Hotel's Wallet: ";
					cin >> user.wallet;
					isRegistered = true;

					in_out_file.seekp(-size, ios::cur);
					in_out_file.write(reinterpret_cast<char*>(&user), sizeof(user));
					in_out_file.close();
					cout << "\t\t\t\t Guest info Updated Successfully";
					_getch();
				}
			}

		}

	}
	

	void setInfo()
	{
		cout << "Enter Name: ";
		getline(cin >> ws, this->name);
		cout << "Enter Age: ";
		cin >> this->age;
		cout << "Enter CNIC: ";
		getline(cin >> ws, this->cnic);
		cout << "Enter Phone Number: ";
		getline(cin >> ws, this->phone);
		cout << "Enter Address: ";
		getline(cin >> ws, this->address);
		cout << "Enter Gender: ";
		getline(cin >> ws, this->gender);
		cout << "Enter Emergency Contact: ";
		getline(cin >> ws, this->emgContact);
		cout << "Enter Email: ";
		getline(cin >> ws, this->email);
		cout << "Enter Amount in Your Hotel's Wallet: ";
		cin >> wallet;
		isRegistered = true;

		

	}



	void Registration(Guest<string,string> &temp)
	{
		
		ofstream file;
		file.open("Guest.txt", ios::app|ios::binary);
		file.write(reinterpret_cast<char*>(&temp), sizeof(temp));
		file.close();
	}
	void checkOut()
	{
		Guest <string,string> user, temp;
		cout << "\t\t\t\t **********************************************" << endl;
		cout << "\t\t\t\t # ========================================== #" << endl;
		cout << "\t\t\t\t # |             ::CHECK OUT ::             | #" << endl;
		cout << "\t\t\t\t # ========================================== #" << endl;
		cout << "\t\t\t\t **********************************************" << endl;
		cout << "Enter CNIC you want to update: ";
		getline(cin >> ws, user.cnic);
		int size = sizeof(temp);
		fstream in_out_file("Guest.txt", ios::binary | ios::in | ios::out);
		if (in_out_file.is_open())
		{
			while (in_out_file.read(reinterpret_cast<char*>(&temp), sizeof(temp)))
			{
				if (temp.cnic == user.cnic)
				{

					// Update Guest Info
					time_t now = time(0);
					// convert now to string form
					#pragma warning(suppress : 4996). // Exception for ctime
					char* date_time = ctime(&now);
					string c;
					c = date_time;
					cout << "\t\t\t\t Your Checkout Date was: " << c;
					cout << "\t\t\t\t Your Balance was: " << temp.wallet<<endl;
					cout << "\t\t\t\t Your Remaining Balance is: " << (temp.wallet-(temp.bill+temp.fbill)) <<endl;
					temp.wallet = (temp.wallet - (temp.bill + temp.fbill));
					in_out_file.seekp(-size, ios::cur);
					in_out_file.write(reinterpret_cast<char*>(&temp), sizeof(temp));
					in_out_file.close();
					cout << "\t\t\t\t Guest Checked Out Successfully";
					_getch();
				}
			}
					system("pause");

		}
		ReserveMenu();
	}


};




template<class x,class z>
class Staff :public basicInfo<z>
{
private:
	z staffId;
	z Role;
	double Salary;
	z Shift;
	z password;
	friend void addStaff();
	friend void delStaff();
public:
	z getstaffId()
	{
		return staffId;
	}
	z getpassword()
	{
		return password;
	}
	void Registration(Staff<string,string>& temp)
	{
		ofstream file;
		file.open("Staff.txt", ios::app | ios::binary);
		file.write(reinterpret_cast<char*>(&temp), sizeof(temp));
		file.close();
		AstaffMenu();
	}
	
	void displayInfo()
	{
		Staff<string,string> temp;
		ifstream rfile;
		rfile.open("Staff.txt", ios::binary);
		if (rfile.read(reinterpret_cast<char*>(&temp), sizeof(temp)))
		{
			if (rfile.is_open())
			{
				if (isAdmin)
				{
					while (!rfile.eof())
					{
						cout << "\t\t\t\t Id: " << temp.staffId << endl;
						cout << "\t\t\t\t CNIC: " << temp.cnic << endl;
						cout << "\t\t\t\t Name: " << temp.name << endl;
						cout << "\t\t\t\t Phone: " << temp.phone << endl;
						cout << "\t\t\t\t Address: " << temp.address << endl;
						cout << "\t\t\t\t Gender: " << temp.gender << endl;
						cout << "\t\t\t\t Role: " << temp.Role << endl;
						cout << "\t\t\t\t Salary: " << temp.Salary << endl;
						cout << "\t\t\t\t Shift: " << temp.Shift << endl;
						rfile.read(reinterpret_cast<char*>(&temp), sizeof(temp));
					}
				}
				else
				{

					while (!rfile.eof())
					{
						if(temp.staffId==loggedUser)
						{

							cout << "\t\t\t\t Id: " << temp.staffId << endl;
							cout << "\t\t\t\t CNIC: " << temp.cnic << endl;
							cout << "\t\t\t\t Name: " << temp.name << endl;
							cout << "\t\t\t\t Phone: " << temp.phone << endl;
							cout << "\t\t\t\t Address: " << temp.address << endl;
							cout << "\t\t\t\t Gender: " << temp.gender << endl;
							cout << "\t\t\t\t Role: " << temp.Role << endl;
							cout << "\t\t\t\t Salary: " << temp.Salary << endl;
							cout << "\t\t\t\t Shift: " << temp.Shift << endl;
							break;
						}
						else
						{
							rfile.read(reinterpret_cast<char*>(&temp), sizeof(temp));
						}
					}
				}
			}
		}
		rfile.close();
		cout << "\t\t\t\t Press Any key to Continue...." << endl;
		_getch();
		if (isAdmin)
			AstaffMenu();
		else
			staffMenu();
	}
	void updateInfo()
	{
		Staff<string,string> user, temp;
		int size = sizeof(temp);
		fstream file("Staff.txt", ios::binary | ios::in | ios::out);
		cout << "Enter Staff ID you want to Update: ";
		getline(cin >> ws, user.staffId);
		if (file.is_open())
		{
			while (file.read(reinterpret_cast<char*>(&temp), sizeof(temp)))
			{
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
		if (isAdmin)
			AstaffMenu();
		else
			staffMenu();
	}
};







template<class x,class v>
class Manager :public basicInfo<x> 
{
private:
	v ManId;
	double Salary;
	v password;
public:
	friend void addManager();
	friend void delManager();
	v getManId()
	{
		return ManId;
	}
v getpassword()
	{
		return password;
	}
	void Registration(Manager<string,string>& temp)
	{
		ofstream file;
		file.open("Manager.txt", ios::app | ios::binary);
		file.write(reinterpret_cast<char*>(&temp), sizeof(temp));
		file.close();
		cout << "Registration Successful..";
		Sleep(1000);
		AmanagerMenu();
	}

	void displayInfo()
	{
		Manager<string,string> temp;
		ifstream rfile;
		rfile.open("Manager.txt", ios::binary);
		if (rfile.read(reinterpret_cast<char*>(&temp), sizeof(temp)))
		{
			if (rfile.is_open())
			{
				if (isAdmin)
				{
					while (!rfile.eof())
					{
						cout << "\t\t\t\t CNIC: " << temp.cnic << endl;
						cout << "\t\t\t\t Name: " << temp.name << endl;
						cout << "\t\t\t\t Phone: " << temp.phone << endl;
						cout << "\t\t\t\t Address: " << temp.address << endl;
						cout << "\t\t\t\t Gender: " << temp.gender << endl;
						cout << "\t\t\t\t Id: " << temp.ManId << endl;
						cout << "\t\t\t\t Salary: " << temp.Salary << endl;
						rfile.read(reinterpret_cast<char*>(&temp), sizeof(temp));
					}
				}
			else
			{

				while (!rfile.eof())
				{
					if (temp.ManId == loggedUser)
					{
						cout << "\t\t\t\t CNIC: " << temp.cnic << endl;
						cout << "\t\t\t\t Name: " << temp.name << endl;
						cout << "\t\t\t\t Phone: " << temp.phone << endl;
						cout << "\t\t\t\t Address: " << temp.address << endl;
						cout << "\t\t\t\t Gender: " << temp.gender << endl;
						cout << "\t\t\t\t Id: " << temp.ManId << endl;
						cout << "\t\t\t\t Salary: " << temp.Salary << endl;
						break;
					}
					else
					{
						rfile.read(reinterpret_cast<char*>(&temp), sizeof(temp));
					}
				}
			}
			
			}

		}
				rfile.close();
				cout << "\t\t\t\t Press Any key to Continue...." << endl;
				_getch();
				if (isAdmin)
					AmanagerMenu();
				else
					managerMenu();
	}
	void updateInfo()
	{
		Manager<string,string> user, temp;
		int size = sizeof(temp);
		fstream file("Manager.txt", ios::binary | ios::in | ios::out);
		cout << "Enter Manager ID you want to Update: ";
		getline(cin >> ws, user.ManId);
		if (file.is_open())
		{
			while (file.read(reinterpret_cast<char*>(&temp), sizeof(temp)))
			{
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
		if (isAdmin)
			AmanagerMenu();
		else
			managerMenu();
	}

};

void gMenu()
{
	Guest<string,string> a;
	a.GuestMenu();
}