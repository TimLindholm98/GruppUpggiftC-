#pragma once
#include "Customer.h"

class AdServingEngine
{
private:

	vector<Customer>CustomerList;

public:
	void UpdateCustomerList(vector<Customer>CustomerList);
	void AddCustomerToCustomerList(Customer c);
	vector<Customer> GetCustomerList();

};

