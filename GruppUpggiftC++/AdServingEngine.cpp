#include "AdServingEngine.h"
#include <vector>

void AdServingEngine::UpdateCustomerList(vector<Customer> CustomerList)
{
	this->CustomerList = CustomerList;
}
vector<Customer> AdServingEngine::GetCustomerList()
{
	return CustomerList;
}
void AdServingEngine::AddCustomerToCustomerList(Customer c, AdServingEngine a)
{
	for (Customer x : a.GetCustomerList())
	{
		if (c.GetCustomerId() == x.GetCustomerId())
		{
			AdServingEngine::UpdateCustomer(c, a);
			return;
		}

	}
	CustomerList.push_back(c);
	
}
void AdServingEngine::UpdateCustomer(Customer c, AdServingEngine a)
{
	int i = 0;
	for (Customer x : a.GetCustomerList())
	{
		if (c.GetCustomerId() == x.GetCustomerId())
		{
			CustomerList.at(i) = x;
			return;
		}
		i++;
	}

}