#pragma once
#include<string>
#include<vector>
#include"Campaign.h"
using namespace std;

class Customer
{
private:
	string name;
	int id;
	vector<Campaign> campaignList;

public:

	Customer(string name, int id);
	int GetCustomerId();
	void SetCustomerId(int id);

	string GetCustomerName();
	void SetCustomerName(string name);

	bool hasActiveCampaigns();

};
