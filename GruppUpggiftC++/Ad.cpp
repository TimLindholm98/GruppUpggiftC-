#include "Ad.h"

Ad::Ad(string name, int id, string adText, AdType adType)
{
	this->name = name;
	this->id = id;
	this->adText = adText;
	this->adType = adType;
}

AdType Ad::GetAdType()
{
	return adType;
}
void Ad::ChangeAdText(string adText)
{
	this->adText = adText;
}

