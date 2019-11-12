#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <time.h>
#include<Windows.h>
#include "AdServingEngine.h"


using namespace std;

string ConvertToString(char* a, int size)
{
	int i;
	string s = "";
	for (i = 0; i < size; i++) {
		s = s + a[i];
	}
	return s;
}
time_t SetTime()
{
	int year;
	int mon;
	int day;
	int hour;

	cout << "--- Create a custom time_t ---" << endl;
	cout << "Type the year you want yy : ";
	cin >> year;

	cout << "Type the mon you want 1-12 : ";
	cin >> mon;

	cout << "Type the day you want 1~31 : ";
	cin >> day;
	
	cout << "Type the hour you want 1-23 // hours since midnight // : ";
	cin >> hour;

	struct tm structTime = { 0 };  // Initalize to all 0's
	structTime.tm_year = year + 100;  // This is year-1900, so 112 = 2012
	structTime.tm_mon = mon -1;
	structTime.tm_mday = day -1;
	structTime.tm_hour = hour -1;

	time_t time = mktime(&structTime);
	return time;
}
string ShowTime(time_t timeToShow)
{
	time_t timet = timeToShow;
	char buff[20];
	struct tm* time;
	time = localtime(&timet);
	strftime(buff, sizeof(buff), "%Y-%m-%d", time );
	string formatedTime = ConvertToString(buff, (sizeof(buff) / sizeof(char)));
	return formatedTime;
}

vector<Customer> CreateAdmin(AdServingEngine& a)
{
	string name = "Admin";
	int id = 1;


	//      fel hantering

	Customer m(name, id);
	vector<Customer> list = a.GetCustomerList();
	list.push_back(m);

	return list;
}
vector<Customer> EraseACustomer(vector <Customer> list)
{
	int id;
	cout << "---Kill menu---" << endl;
	cout << "Customer ID: ";
	cin >> id;
	for (int i = 0; i < list.size(); i++)
	{
		if (list[i].GetCustomerId() == id)
		{
			list.erase(list.begin() + i);
			cout << endl << "Customer deleted..." << endl;

			return list;
		}

	}
	cout << "Customer not found..." << endl;
	return list;
}
vector<Customer> CustomerUpdate(vector<Customer>CustomerList)
{
	string CustomerName, CustomersNewName;
	int newCustomerId;
	char answer;
	cout << "---Login---" << endl;
	cout << "Customer ID: ";
	cin >> newCustomerId;;
	for (int i = 0; i < CustomerList.size(); i++)
	{
		if (CustomerList[i].GetCustomerId() == newCustomerId)
		{
			cout << "New Customer ID: " << endl;
			cin >> CustomersNewName;
			CustomerList[i].SetCustomerName(CustomersNewName);
			cout << "Do you want to change name?(y/n)" << endl;
			cin >> answer;
			if (answer == 'y')
			{
				cout << "New name: ";
				cin >> CustomerName;
				CustomerList[i].SetCustomerName(CustomerName);
			}
			else
			{
				break;
			}
		}
	}
	return CustomerList;
}
void DisplayAllCustomers(vector <Customer>list)
{
	for (int i = 0; i < list.size(); i++)
	{
		cout << "Customer name: " << list[i].GetCustomerName() << endl << "Customer ID: " << list[i].GetCustomerId() << endl;
	}
}
// Bra m�ste l�gga till felhantering
vector<Customer> CreateCustomer(AdServingEngine &a)
{
	string name;
	int id;
	cout << "Name: ";
	cin >> name;
	cout << "ID: ";
	cin >> id;

	//      fel hantering

	Customer m(name, id);
	vector<Customer> list = a.GetCustomerList();
	list.push_back(m);

	return list;
}
Customer LoginToCustomer(vector<Customer>list, AdServingEngine &a)
{
	if (list.size() == 0)
	{
		cout << "No Customers created yet, pls create a customer" << endl;
		list = CreateCustomer(a);
	}
	

	int userIdLogin;
	cout << "--- Login ---" << endl;
	cout << "Enter User Id: ";
	cin >> userIdLogin;
	for (auto x : list)
	{
		if (userIdLogin == x.GetCustomerId())
		{
			cout << "User Id: " << x.GetCustomerId() << " Logged in" << endl << endl;
			return x;
		}
	}
	cout << "No such user ID in system." << endl;
}

//Fr�ga stefan om hj�lp
void DisplayAllCampaigns(vector <Campaign>list)
{
	for (int i = 0; i < list.size(); i++)
	{
		cout << "Campaign name: " << list[i].GetCampaignName() << endl
			<< "Campaign ID: " << list[i].GetCampaignId() << endl
			<< "Campaign start date: " << ShowTime(list[i].GetFromDateTime()) << endl; // n�nting �r fel h�r fr�ga stefan!
	}
}
// Bra m�ste l�gga till felhantering
vector<Campaign> CreateCampaign(Customer &c)
{
	string name;
	cout << "Name: ";
	cin >> name;

	int id;
	cout << "ID: ";
	cin >> id;

	//      fel hantering

	time_t fromDateTime = SetTime();
	time_t toDateTime = SetTime();

	Campaign campaign(name, id, fromDateTime, toDateTime);

	vector<Campaign> newlist = c.GetCampaignList();
	newlist.push_back(campaign);

	return newlist;
}
void CampaignMenu(Customer &c)
{
	int selection;

	cout << "1: Create new campaign" << endl;
	cout << "2: Update campaign" << endl;
	cout << "3: Read customer campaigns" << endl;
	cout << "4: Exit" << endl;
	cin >> selection;

	switch (selection)
	{
	case 1:
		c.UpdateCampaignList(CreateCampaign(c));
		break;
	case 2:
		break;
	case 3:
		DisplayAllCampaigns(c.GetCampaignList());
		break;
	case 4:
		break;
	}

}

void AdMenu(Customer &c)
{
	int selection;
	cout << "1: Create new Ad" << endl;
	cout << "2: Update Ad" << endl;
	cout << "3: Read customer Ads" << endl;
	cout << "4: Exit" << endl;

	cin >> selection;
	switch (selection)
	{
	case 1:

		break;
	case 2:
		break;
	case 3:
		break;
	case 4:
		return;
	}
}
void CustomerMenu(Customer &c)
{
	while (true)
	{
		int selection;
		
		cout << "1: Customer settings" << endl;
		cout << "2: Campaign menu" << endl;
		cout << "3: Ad menu" << endl;
		cout << "4: Exit" << endl;

		cout << "-> " << endl;
		cin >> selection;

		switch (selection)
		{
		case 1:
			//CustomerSettingsMenu(c);
			break;
		case 2:
			CampaignMenu(c);
			break;
		case 3:
			AdMenu(c);
			break;
		case 4:
			return;
		}
	}
	
}
void ManageCustomersMenu(AdServingEngine& a)
{
	int selection;

	cout << "1: Create new Customer" << endl;
	cout << "2: Update Customer" << endl;
	cout << "3: Read Customers" << endl;
	cout << "4: Delete Customer" << endl;
	cout << "5: Exit" << endl;

	cin >> selection;

	switch (selection)
	{
	case 1:
		a.UpdateCustomerList(CreateCustomer(a));
		break;
	case 2:
		a.UpdateCustomerList(CustomerUpdate(a.GetCustomerList()));
		break;
	case 3:
		DisplayAllCustomers(a.GetCustomerList());
		break;
	case 4:
		a.UpdateCustomerList(EraseACustomer(a.GetCustomerList()));
		break;
	case 5:
		break;
	}
}

int main()
{
	AdServingEngine a;
	while(true)
	{
		int selection;

		a.UpdateCustomerList(CreateAdmin(a));
		cout << "1: Go to customer" << endl;
		cout << "2: Manage all customers" << endl;
		cout << "3: Exit" << endl;

		cout << "-> ";
		cin >> selection;

		switch (selection)
		{
		case 1:
		{
			Customer c = LoginToCustomer(a.GetCustomerList(), a);
			CustomerMenu(c);
		}
			break;
		case 2:
			ManageCustomersMenu(a);
			break;
		case 3:
			cout << "Exiting program........." << endl << endl;
			break;
		}
	}
	return 0;
}
