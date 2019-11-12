#include<iostream>
#include"Customer.h"

Customer::Customer(string name, int id)
{
	this->name = name;
	this->id = id;
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