#include "Ad.h"

Ad::Ad(string name, int id, string adText, AdType adType)
{
	this->name = name;
	this->id = id;
	this->adText = adText;
	this->adType = adType;
}

string Ad::GetName()
{
	return name;
}
int Ad::GetAdID()
{
	return id;
}
string Ad::GetAdText()
{
	return adText;
}
AdType Ad::GetAdType()
{
	return adType;
}

void Ad::ChangeAdName(string name)
{
	this->name = name;
}
void Ad::ChangeAdID(int id)
{
	this->id = id;
}
void Ad::ChangeAdText(string adText)
{
	this->adText = adText;
}
void Ad::ChangeAdType(AdType adType)
{
	this->adType = adType;
}
