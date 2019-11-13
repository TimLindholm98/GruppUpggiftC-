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
	vector<Campaign> CampaignList;

public:

	Customer(string name, int id);
	int GetCustomerId();
	void SetCustomerId(int id);
	vector<Campaign> GetCampaignList();
	void UpdateCampaignList(vector<Campaign> CampaignList);
	void AddCampaignToCampaignList(Campaign campaign);


	string GetCustomerName();
	void SetCustomerName(string name);

	bool hasActiveCampaigns();

};
