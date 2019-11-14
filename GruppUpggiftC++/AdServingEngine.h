#pragma once
#include "Customer.h"

class AdServingEngine
{
private:

	vector<Customer>CustomerList;

public:
	void UpdateCustomerList(vector<Customer>CustomerList);
	void UpdateCustomer(Customer c, AdServingEngine a);
	void AddCustomerToCustomerList(Customer c, AdServingEngine a);
	vector<Customer> GetCustomerList();
	void GetNextAd(Campaign camp);
};

