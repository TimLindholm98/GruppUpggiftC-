#include "Campaign.h"
#include <vector>

vector<Ad> adsList;

Campaign::Campaign(string name, int id, time_t fromDateTime, time_t toDateTime)
{
	this->name = name;
	this->id = id;
	this->fromDateTime = fromDateTime;
	this->toDateTime = toDateTime;
}

int Campaign::GetID()
{
	return id;
}

vector<Ad> Campaign::GetAllAdsForCampaign()
{
	return ads;
}
