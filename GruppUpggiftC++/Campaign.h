#pragma once
#include<string>
#include<vector>
#include<time.h>
#include"Ad.h"

using namespace std;

class Campaign
{
private:
	string name;
	int id;
	time_t  fromDateTime, toDateTime;
	float CampaignCost;
	vector<Ad> ads;

public:
	Campaign(string name,
		int id,
		time_t fromDateTime,
		time_t toDateTime);

	int GetCampaignId();
	string GetCampaignName();
	void ChangeCampaignName(string name);
	void ChangeCampaignId(int id);
	void ChangeCampaignCost(float);
	void ChangeToDateTime(time_t toDateTime);
	void ChangeFromDateTime(time_t fromDateTime);
	time_t GetToDateTime();
	time_t GetFromDateTime();
	vector<Ad> GetAllAdsForCampaign();


};
