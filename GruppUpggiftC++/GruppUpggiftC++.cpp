#include <iostream>
#include <string.h>
#include <ctime>
#include<Windows.h>
#include "AdServingEngine.h"

using namespace std;

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
void ReadAllCustomers(vector <Customer>list)
{
	for (int i = 0; i < list.size(); i++)
	{
		cout << "Customer name: " << list[i].GetCustomerName() << endl << "Customer ID: " << list[i].GetCustomerId() << endl;
	}
};
// Bra måste lägga till felhantering
vector<Customer> CreateCustomer(AdServingEngine a)
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
Customer LoginToCustomer(vector<Customer>list, AdServingEngine a)
{
	if (sizeof(list) == 0)
	{
		cout << "No such user ID in system, Register a customer" << endl;
		a.UpdateCustomerList(CustomerUpdate(a.GetCustomerList()));
	}
	while (true)
	{

		int userIdLogin;
		cout << "Enter User Id: ";
		cin >> userIdLogin;
		for (auto x : list)
		{
			if (userIdLogin == x.GetCustomerId())
			{
				cout << "\nUser Id" << x.GetCustomerId() << " Logged in";
				return x;
			}

		}
		cout << "No such user ID in system.";
	}
}
void ManageCustomersMenu(AdServingEngine &a)
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
		ReadAllCustomers(a.GetCustomerList());
		break;
	case 4:
		a.UpdateCustomerList(EraseACustomer(a.GetCustomerList()));
		break;
	case 5:
		break;
	}
}



vector<Campaign> CreateCampaign(vector<Campaign> campaignList, Customer c)
{
	
	string name;
	int id;
	time_t fromDateTime;
	time_t toDateTime;

	cout << "Name: ";
	cin >> name;
	cout << "ID: ";
	cin >> id;

	//      fel hantering

	Campaign campaign(string name, int id, time_t fromDateTime, time_t toDateTime);
	vector<Campaign> list = c.GetCampaignList();
	list.push_back(campaign);

	return list;
}

void CampaignMenu(Customer c)
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
		CreateNewCampaign();
		break;
	case 2:
		break;
	case 3:
		break;
	case 4:
		break;
	}

}

void AdMenu(Customer c)
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

int main()
{
	AdServingEngine a;
	while(true)
	{
		int selection;

		cout << "1: Go to customer" << endl;
		cout << "2: Manage all customers" << endl;
		cout << "3: Exit" << endl;

		cout << "-> " << endl;
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
