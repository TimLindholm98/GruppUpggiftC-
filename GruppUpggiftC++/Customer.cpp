#include<iostream>
#include"Customer.h"

Customer::Customer(string name, int id)
{
	this->name = name;
	this->id = id;
}
vector<Campaign> Customer::GetCampaignList()
{
	return CampaignList;
}
void Customer::UpdateCampaignList(vector<Campaign> CampaignList)
{
	this->CampaignList = CampaignList;
}

string Customer::GetCustomerName()
{
	return name;
}
void Customer::SetCustomerName(string name)
{
	this->name = name;
}

bool Customer::hasActiveCampaigns()
{
	return false;
}

int Customer::GetCustomerId()
{
	return id;
}
void Customer::SetCustomerId(int id)
{
	this->id = id;
}