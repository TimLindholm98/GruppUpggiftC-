#include "Campaign.h"
#include <vector>

Campaign::Campaign(string name, int id, time_t fromDateTime, time_t toDateTime)
{
	this->name = name;
	this->id = id;
	this->fromDateTime = fromDateTime;
	this->toDateTime = toDateTime;
}

int Campaign::GetCampaignId()
{
	return id;
}
string Campaign::GetCampaignName()
{
	return name;
}
void Campaign::ChangeCampaignName(string name) 
{
	this->name = name;
}
void Campaign::ChangeCampaignId(int id)
{
	this->id = id;
}
void Campaign::ChangeCampaignCost(float CampaignCost)
{
	this->CampaignCost = CampaignCost;
}
void Campaign::ChangeToDateTime(time_t toDateTime)
{
	this->toDateTime = toDateTime;
}
void Campaign::ChangeFromDateTime(time_t fromDateTime)
{
	this->fromDateTime = fromDateTime;
}
time_t Campaign::GetToDateTime()
{
	return toDateTime;
}
time_t Campaign::GetFromDateTime()
{
	return fromDateTime;
}

