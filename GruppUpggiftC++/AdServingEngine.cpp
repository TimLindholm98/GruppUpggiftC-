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