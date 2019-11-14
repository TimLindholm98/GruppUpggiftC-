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
void Customer::AddCampaignToCampaignList(Customer c, Campaign campaign)
{
	for (Campaign x : c.GetCampaignList())
	{
		if (x.GetCampaignId() == campaign.GetCampaignId())
		{
			Customer::UpdateCampaign(c, campaign);
			return;
		}

	}
	CampaignList.push_back(campaign);

}
void Customer::UpdateCampaign(Customer c, Campaign campaign)
{
	int index = 0;
	for (Campaign x : c.GetCampaignList())
	{
		if (campaign.GetCampaignId() == x.GetCampaignId())
		{
			CampaignList.at(index) = campaign;
			return;
		}
		index++;
	}
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