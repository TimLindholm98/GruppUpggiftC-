#include "AdServingEngine.h"
#include <vector>
#include <iostream>

void AdServingEngine::UpdateCustomerList(vector<Customer> CustomerList)
{
	this->CustomerList = CustomerList;
}
vector<Customer> AdServingEngine::GetCustomerList()
{
	return CustomerList;
}
void AdServingEngine::AddCustomerToCustomerList(Customer c, AdServingEngine a)
{
	for (Customer x : a.GetCustomerList())
	{
		if (c.GetCustomerId() == x.GetCustomerId())
		{
			AdServingEngine::UpdateCustomer(c, a);
			return;
		}

	}
	CustomerList.push_back(c);
	
}
void AdServingEngine::UpdateCustomer(Customer c, AdServingEngine a)
{
	int index = 0;
	for (Customer x : a.GetCustomerList())
	{
		if (c.GetCustomerId() == x.GetCustomerId())
		{
			CustomerList.at(index) = c;
			return;
		}
		index++;
	}
}
void AdServingEngine::GetNextAd(Campaign camp)
{
	string answer;
	cout << "Do you want to get one specific ad or all ads" << endl << " Please enter 1 to print all ads or 2 to print a specific ad: ";
	cin >> answer;
	if (answer == "1")
	{
		vector<Ad>list = camp.GetAllAdsForCampaign();
		for (int i = 0; i < camp.GetAllAdsForCampaign().size(); i++)
		{
			cout << list[i].GetAdText() << endl;
		}
	}
	else if (answer == "2")
	{
		int adId;
		cout << "Please enter ad id you want to print: ";
		cin >> adId;
		vector<Ad>list = camp.GetAllAdsForCampaign();
		for (int i = 0; i < camp.GetAllAdsForCampaign().size(); i++)
		{
			if (list[i].GetAdID() == adId)
			{
				cout << list[i].GetAdText() << endl;

			}
		}
	}
}