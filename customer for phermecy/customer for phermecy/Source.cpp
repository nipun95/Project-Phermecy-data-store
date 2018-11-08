#include<iostream>
#include<fstream>
#include<iomanip>
#include<string>
#include<stdio.h>
using namespace std;

class Regular
{
private:
	int n;
	int choice;
	string mname, date;
	string u_name, cf_name, cl_name, c_name;
	char m_name;
	char ch;
	double piece;
	double price;
	double total_price;
	double final_price;
	friend void search(Regular &obj);
	friend void bill(Regular &obj);

public:
    Regular(){final_price=0;}

	void add()
	{
		cout << "Enter the name of Username for create a file" << endl; cin >> u_name;
		ofstream customdata;
		customdata.open(u_name, ios::out | ios::_Noreplace);
		if (!customdata)
		{
			cout << "File filename already exist";
		}
		else
		{
			cout << "Enter Customer's first name\n";
			cin >> cf_name;
			cout << "Enter Customer's last name\n";
			cin >> cl_name;
			c_name = cf_name + " " + cl_name;
			customdata << "Customer name:\t" << c_name << endl;
			customdata << "\nMedicine name:"<<endl;
			cout << "Enter Medicines name || Press # to stop add medicine"<<endl;
			while ((m_name = getchar()) != '#')
			{
				customdata << m_name;
			}
		}
		customdata.close();
		cout << "Information successfully created for " << c_name << ".....!!\n\n" << endl;
	}

	

	void edit()
	{
		cout << "Enter username for Add data\n\n"; cin >> u_name;
		ofstream customdata;
		customdata.open(u_name, ios::out | ios::app);
		cout << "\n\nAdd Medicines name || Press # to stop add medicine\n";
		while ((m_name = getchar()) != '#')
		{
			customdata << m_name;
		}
		customdata.close();
	}

	void cdelete();
};

void search(Regular &obj)
{
	cout << "Enter username for search\n\n"; cin >> obj.u_name;
	ifstream customdata;
	customdata.open(obj.u_name, ios::in);
	system("CLS");
	cout << "----------Customer information---------\n\n\n";
	if (customdata.fail())
	{
		cout << "There are no file named " << obj.u_name << endl;
	}
	else
	{
		while (getline(customdata, obj.u_name))
		{
			cout << obj.u_name << endl;
		}

			cout << endl << endl;
			cout << "Enter date like (day-month-year): "; cin >> obj.date;
			ofstream store;
			store.open(obj.date, ios::out | ios::app);
			cout << "\n\nHow many medicine you want?\n"; cin >> obj.n;
			for (int i = 1; i <= obj.n; i++)
			{
				cout << "Enter medicine name:\t";
				cin >> obj.mname;
				cout << "Enter piece:\t"; cin >> obj.piece;
				cout << "Enter price:\t"; cin >> obj.price;
				obj.total_price = obj.piece * obj.price;
				cout << "total:\t" << obj.total_price << endl;
				obj.final_price += obj.total_price;

			}
			store << obj.final_price<<"+";
			cout << "Final price:\t" << obj.final_price << endl;
			store.close();
		
	}
	customdata.close();
}

void bill(Regular &obj)
{
	cout << "Enter date(day-month-year):  "; cin >> obj.date;
	ifstream store;
	store.open(obj.date, ios::in);
	system("CLS");
	cout << "----------Total Bill---------\n\n\n";
	if (store.fail())
	{
		cout << "There are no bill this day " << obj.date << endl;
	}
	else
	{
		while (getline(store, obj.date))
		{
			cout << obj.date << endl;
		}
	}
	store.close();
}

void Regular :: cdelete()
{
	cout << "Enter username to delete: "; cin >> u_name;

	if (remove(u_name.c_str()) != 0)
	{
		cout << "Remove operation failed" << endl;
	}
	else
	{
		cout << u_name << " has been removed." << endl;
	}
}

/*void remove()
{
	string uname,line, mname, nname;
	cout << "Enter username" << endl; cin >> uname;
	cout << "Enter new username" << endl; cin >> nname;
	cout << "Medicine name to delete"<<endl; cin >> mname;

	ifstream file;
	file.open(uname);
	ofstream outfile;
	outfile.open(nname);
	while (getline(file, line))
		if (line != mname)
			outfile << line << endl;

	remove(uname);
	rename(uname, nname);
	outfile.close();
	file.close();
}*/

int main()
{
	Regular r1;
	char ch;
	int choice;

	while (choice != 0)
	{
	start:
		system("CLS");
		cout << "----------Welcome---------\n\n\n";
		cout << "Enter your choice\n\n\n";
		cout << "Press 1 for regular customers\n\n";
		cout << "Press 2 for irregular customers\n\n";
		cout << "Press 0 for exit\n\n" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:
		{
			while (choice != 0)
			{
				system("CLS");
				cout << "------------- Regular Customer--------------\n\n\n";
				cout << "Press 1 to create customer information\n\n";
				cout << "Press 2 to search customer by username\n\n";
				cout << "Press 3 to add information to file\n\n";
				cout << "Press 4 to remove medicine\n\n";
				cout << "Press 5 to delete customer data\n\n";
				cout << "Press 6 to see total bill\n\n";
				cout << "press 0 for exit\n\n";
				cin >> choice;
				switch (choice)
				{
				case 1:
					system("CLS");
					cout << "-------------Add customer information----------\n\n\n";
					r1.add();
					cout << "\nDo you want to continue?\t Yes(Y) or No(N)\n"; cin >> ch;
					if (ch == 'y')
					{
						continue;
					}
					else
					{
						break;
					}
					break;
				case 2:
					system("CLS");
					cout << "-------------Search customer information----------\n\n\n";
					search(r1);
					cout << "\nDo you want to continue?\t Yes(Y) or No(N)\n"; cin >> ch;
					if (ch == 'y')
					{
						continue;
					}
					else
					{
						break;
					}
					break;
				case 3:
					system("CLS");
					cout << "-------------Edit customer information----------\n\n\n";
					r1.edit();
					cout << "\nDo you want to continue?\t Yes(Y) or No(N)\n"; cin >> ch;
					if (ch == 'y')
					{
						continue;
					}
					else
					{
						break;
					}
					break;
				case 4:
					system("CLS");
					cout << "-------------Remove medicine----------\n\n\n";
					//remove();
					break;
				case 5:
					system("cls");
					cout << "--------------Delete customer------------\n\n\n";
					r1.cdelete();
					cout << "\nDo you want to continue?\t Yes(Y) or No(N)\n"; cin >> ch;
					if (ch == 'y')
					{
						continue;
					}
					else
					{
						break;
					}
					break;
				case 6:
					system("cls");
					cout << "----------------Total Bill------------------\n\n\n";
					bill(r1);
					cout << "\nDo you want to continue?\t Yes(Y) or No(N)\n"; cin >> ch;
					if (ch == 'y')
					{
						continue;
					}
					else
					{
						break;
					}
					break;
				case 0:
					goto start;
					break;

				}
				break;
			}
		}
		break;
		case 2: cout << "proccessing\n";
			break;
		case 0:
			break;
		default: cout << "You pressed wrong button, please press the right button" << endl;
		}
		break;
	}
	system("pause");
	return 0;
}
