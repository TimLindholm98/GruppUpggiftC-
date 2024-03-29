#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <time.h>
#include<Windows.h>
#include "AdServingEngine.h"


using namespace std;

string returnStringFunction()
{

	cout << "-> ";
	string name;
	cin.ignore();
	getline(cin, name);
	return name;

}
int returnIntFunction()
{
	cout << "->";
	int id;
	cin >> id;
	return id;
}
float returnFloatFunction()
{
	cout << "->";
	float cost;
	cin.ignore();
	cin >> cost;
	return cost;
}
string ConvertToString(char* a, int size)
{
	int i;
	string s = "";
	for (i = 0; i < size; i++) {
		s = s + a[i];
	}
	return s;
}
time_t SetTime()
{
	int year;
	int mon;
	int day;

	cout << "--- Create a custom time_t ---" << endl;
	cout << "Type the year you want yyyy: ";
	cin >> year;

	cout << "Type the mon you want 1-12 : ";
	cin >> mon;

	cout << "Type the day you want 1~31 : ";
	cin >> day;

	struct tm structTime = { 0 };  // Initalize to all 0's
	structTime.tm_year = year -1900;  // This is year-1900, so 112 = 2012
	structTime.tm_mon = mon -1;
	structTime.tm_mday = day;

	time_t time = mktime(&structTime);
	return time;
}
string ShowTime(time_t timeToShow)
{
	time_t timet = timeToShow;
	char buff[15];
	struct tm* time;
	time = localtime(&timet);
	strftime(buff, sizeof(buff), "%Y-%m-%d", time );
	string formatedTime = ConvertToString(buff, strlen(buff));
	return formatedTime;
}
vector<Customer> CreateAdmin(AdServingEngine a)
{
	string name = "Admin";
	int id = 1;


	//      fel hantering

	Customer m(name, id);
	vector<Customer> list = a.GetCustomerList();
	list.push_back(m);

	return list;
}

//---Customer Functions------------------------------------------------------------------------------
vector<Customer> EraseACustomer(vector <Customer> list)
{
	int id;
	cout << "---Kill menu---" << endl;
	cout << "Customer ID: ";
	cin >> id;
	for (int i = 0; i < list.size(); i++)
	{
		if (list[i].GetCustomerId() == id)
		{
			list.erase(list.begin() + i);
			cout << endl << "Customer deleted..." << endl;

			return list;
		}

	}
	cout << "Customer not found..." << endl;
	return list;
}
vector<Customer> CustomerUpdate(vector<Customer>CustomerList)
{
	string CustomerName, CustomersNewName;
	int newCustomerId;
	char answer;
	cout << "---Login---" << endl;
	cout << "Customer ID: ";
	cin >> newCustomerId;;
	for (int i = 0; i < CustomerList.size(); i++)
	{
		if (CustomerList[i].GetCustomerId() == newCustomerId)
		{
			cout << "New Customer ID: " << endl;
			cin >> CustomersNewName;
			CustomerList[i].SetCustomerName(CustomersNewName);
			cout << "Do you want to change name?(y/n)" << endl;
			cin >> answer;
			if (answer == 'y')
			{
				cout << "New name: ";
				cin >> CustomerName;
				CustomerList[i].SetCustomerName(CustomerName);
			}
			else
			{
				break;
			}
		}
	}
	return CustomerList;
}
void DisplayAllCustomers(vector <Customer>list)
{
	for (int i = 0; i < list.size(); i++)
	{
		cout << "Customer name: " << list[i].GetCustomerName() << endl << "Customer ID: " << list[i].GetCustomerId() << endl;
	}
}
vector<Customer> CreateCustomer(AdServingEngine a)
{
	string name;
	int id;
	vector<Customer> newlist = a.GetCustomerList();
	
	while (true)
	{
		bool noDuplicates = true;
		
		cin.ignore();
		cout << "Customer name: ";
		getline(cin, name);
		cout << "ID: ";
		cin >> id;

		for (int i = 0; i < a.GetCustomerList().size(); i++)
		{
			if (newlist[i].GetCustomerId() == id)
			{
				cout << "this customer with this id already exists" << endl;
				noDuplicates = false;
			}
			else if (newlist[i].GetCustomerName() == name)
			{
				cout << "this customer with this name already exists" << endl;
				noDuplicates = false;;
			}
		}
		if (noDuplicates == true)
		{
			Customer m(name, id);
			newlist.push_back(m);
			return newlist;
		}
	}
}

//---Campaign Functions------------------------------------------------------------------------------
void DisplayAllCampaigns(vector <Campaign>list)
{
	cout << "----------------------------" << endl;
	for (Campaign x : list)
	{
		cout << "Campaign name: " << x.GetCampaignName() << endl
			<< "Campaign ID: " << x.GetCampaignId() << endl
			<< "Campaign start date: " << ShowTime(x.GetFromDateTime()) << endl
			<< "Campaign end date: " << ShowTime(x.GetToDateTime()) << endl;
	}
	cout << "----------------------------" << endl;
}
void DisplayAllCampaignIDs(vector <Campaign>list)
{
	cout << "----------------------------" << endl;
	for (int i = 0; i < list.size(); i++)
	{
		cout << "Campaign name: " << list[i].GetCampaignName() << endl
			<< "Campaign ID: " << list[i].GetCampaignId() << endl;
	}
	cout << "----------------------------" << endl;
}
Campaign ChooseCampaign(vector<Campaign>CampaignList)
{
	int id;
	DisplayAllCampaignIDs(CampaignList);
	cout << "Type the campaign id you want to change: " << endl;
	while (1) 
	{
		cin >> id;
		for (int i = 0; i < CampaignList.size(); i++)
		{
			if (id == CampaignList[i].GetCampaignId())
			{
				return CampaignList[i];
			}
		}
		cout << "No campaign with that id..." << endl;
	}
	

}
Campaign GetCampaign(vector<Campaign> list)
{
	while (true)
	{
		int id;
		cout << "Which campaign would you like to add ads to?" << endl << "Enter Campaign ID -> ";
		cin >> id;
		for (int i = 0; i < list.size(); i++)
		{
			if (list[i].GetCampaignId() == id)
				return list[i];
		}
		cout << "No such ID found...\n";
		continue;
	}
}
vector<Campaign> UpdateCampaign(vector<Campaign>CampaignList,Campaign campaign)
{
	//Function chagne the object and replacing it on the right index and then returning the changed updatedlist
	int i;
	for (i = 0; i < CampaignList.size(); i++)
	{
		if (campaign.GetCampaignName() == CampaignList[i].GetCampaignName() )
		{
			break;
		}
	}

	int selection;
	cout << "1: Update campaign name" << endl;
	cout << "2: Update campaign ID" << endl;
	cout << "3: Change/Add campaign cost" << endl;
	cout << "4: Change from datetime" << endl;
	cout << "5: Change to datetime" << endl;
	cout << "6: Exit" << endl;

	cin >> selection;
	switch (selection)
	{
	case 1:
		campaign.ChangeCampaignName(returnStringFunction());
		CampaignList.at(i) = campaign;
		break;
	case 2:
		//	Update campaign ID()
		campaign.ChangeCampaignId(returnIntFunction());
		CampaignList.at(i) = campaign;
		break;
	case 3:
		//	Change/Add campaign cost()
		campaign.ChangeCampaignCost(returnFloatFunction());
		CampaignList.at(i) = campaign;
		break;
	case 4:
		campaign.ChangeFromDateTime(SetTime());
		CampaignList.at(i) = campaign;
		break;
	case 5:
		//	Change to datetime()
		campaign.ChangeToDateTime(SetTime());
		CampaignList.at(i) = campaign;
		break;
	case 6:
		break;
	}
	return CampaignList;
}
Campaign CreateCampaign(Customer c)
{
	string name;
	int id;
	vector<Campaign> newlist = c.GetCampaignList();

	while (true)
	{
		bool noDuplicates = true;
		cin.ignore();
		cout << "Campaign name: ";
		getline(cin, name);
		cout << "ID: ";
		cin >> id;

		for (int i = 0; i < c.GetCampaignList().size(); i++)
		{
			if (newlist[i].GetCampaignId() == id)
			{
				cout << "this campaign with this id already exists" << endl;
				noDuplicates = false;
			}
			else if (newlist[i].GetCampaignName() == name)
			{
				cout << "this campaign with this name already exists" << endl;
				noDuplicates = false;;
			}
		}
		if (noDuplicates == true)
		{
			break;
		}
	}
	

	cout << "--- from datetime ---" << endl << endl;
	time_t fromDateTime = SetTime();
	cout << "--- To datetime ---" << endl << endl;
	time_t toDateTime = SetTime();

	Campaign campaign(name, id, fromDateTime, toDateTime);
	return campaign;
}
Customer CampaignMenu(Customer c)
{
	int selection;

	Customer &refrencetoc = c;
	
	while (true)
	{
		cout << endl << "1: Create new campaign" << endl;
		cout << "2: Update campaign" << endl;
		cout << "3: Read customer campaigns" << endl;
		cout << "4: Exit" << endl;
		cin >> selection;
		switch (selection)
		{
		case 1:
			c.AddCampaignToCampaignList(c,CreateCampaign(c));
			break;
		case 2:
			//refrencetoc.AddCampaignToCampaignList(UpdateCampaign(ChooseCampaign(c.GetCampaignList()))); kommer se ut exakt s� h�r
			refrencetoc.UpdateCampaignList(UpdateCampaign(c.GetCampaignList(), ChooseCampaign(c.GetCampaignList()))); // CASE 1 kanske klar! OBS m�ste g�ra om vad den skickar tillbaka, m�ste skicka tillbaka ett customer objekt
			break;
		case 3:
			DisplayAllCampaigns(c.GetCampaignList());
			break;
		case 4:
			// Going back to CustomerMenu
			return c;
		}
	}
}

////---Ad Functions------------------------------------------------------------------------------
vector<Ad> EraseAnAd(vector <Ad> list)
{
	int id;
	cout << "---Kill menu---" << endl;
	cout << "Ad ID to erase: ";
	cin >> id;
	for (int i = 0; i < list.size(); i++)
	{
		if (list[i].GetAdID() == id)
		{
			list.erase(list.begin() + i);
			cout << endl << "Ad deleted..." << endl;

			return list;
		}

	}
	cout << "Ad not found..." << endl;
	return list;
}
AdType ChangeAdTypeFunction()
{
	AdType adType = AdType_plain;
	cout << "-> ";
	int adTypeInput;
	cin >> adTypeInput;
	if (adTypeInput == 0)
		adType = AdType::AdType_scroll;
	else if (adTypeInput == 1)
		adType = AdType::AdType_blink;
	else if (adTypeInput == 2)
		adType = AdType::AdType_plain;
	return adType;
}
string ShowAdType(AdType adType)
{
	string text;
	if (adType == 0)
		text = "Scrolling Text";
	else if (adType == 1)
		text = "Blinking Text";
	else if (adType == 2)
		text = "Plain Text";
	return text;
}
void PrintAds(vector<Ad>ListOfAds)
{
	for (auto x : ListOfAds)
	{
		cout << "Name -> " << x.GetName() << endl;
		cout << "Id -> " << x.GetAdID() << endl;
		cout << "AdType -> " << ShowAdType(x.GetAdType()) << endl; // nice!!! x.
		cout << "AdText -> " << x.GetAdText() << endl;
		cout << endl;
	}
}
vector<Ad> CreateNewAd(Campaign& campaign)
{

	string name, adText;
	int id;
	AdType adType = AdType::AdType_plain;

	cout << "Enter name of your Ad "; // G�R INTE ATT G�RA MELLANSLAG
	name = returnStringFunction();

	cout << "Enter ID number ";
	id = returnIntFunction();

	cout << "Enter Your adtype \n0. for Scroll \n1. for Blinking \n2. For Plain \n";
	ChangeAdTypeFunction();

	cout << "Enter text for your ad to be displayed ";
	adText = returnStringFunction();

	Ad newAd(name, id, adText, adType); // BEH�VS PEKARE H�R???? fr�ga steffe

	vector<Ad> lista = campaign.GetAllAdsForCampaign();
	lista.push_back(newAd);

	return lista;
}
vector<Ad> ChangeCampaignAd(vector<Ad>ListOfAds)
{
	int i;
	int adIDinput;
	cout << "Enter Ad ID to change -> ";
	cin >> adIDinput;
	for (i = 0; i < ListOfAds.size(); i++)
	{
		if (adIDinput == ListOfAds[i].GetAdID())
		{
			break;
		}
	}

	for (auto x : ListOfAds)
	{
		if (adIDinput == x.GetAdID())
		{
			cout << "Enter you new Ad Name ";
			x.ChangeAdName(returnStringFunction());
			cout << "Enter your new Ad ID ";
			x.ChangeAdID(returnIntFunction());
			cout << "Enter Your new adtype \n0. for Scroll \n1. for Blinking \n2. For Plain \n";
			x.ChangeAdType(ChangeAdTypeFunction());
			cout << "Enter your new Ad Text ";
			x.ChangeAdText(returnStringFunction());
			ListOfAds.at(i) = x;
		}
	}
	return ListOfAds;
}
Campaign AdMenu(Campaign campaign)
{
	while (true)
	{
		int selection;
		cout << "1: Create new Ad" << endl;
		cout << "2: Update Ad" << endl;
		cout << "3: Show campaign Ads" << endl;
		cout << "4: Delete Ad" << endl;
		cout << "5: Exit" << endl;

		cin >> selection;
		switch (selection)
		{
		case 1:
			campaign.UpdateAdsList(CreateNewAd(campaign));
			break;
		case 2:
			campaign.UpdateAdsList(ChangeCampaignAd(campaign.GetAllAdsForCampaign()));
			break;
		case 3:
			PrintAds(campaign.GetAllAdsForCampaign());
			break;
		case 4:
			campaign.UpdateAdsList(EraseAnAd(campaign.GetAllAdsForCampaign()));
			break;
		case 5:
			cout << "Exiting...\n";
			return campaign;
		}
	}
}

//---Main Menu Functions------------------------------------------------------------------------------
Customer CustomerMenu(AdServingEngine a,Customer c)
{
	while (true)
	{
		int selection;
		
		cout << "1: Campaign menu" << endl;
		cout << "2: Ad menu" << endl;
		cout << "3: Exit" << endl;

		cout << "-> " << endl;
		cin >> selection;

		Customer &refrencetoc = c;
		switch (selection)
		{
		case 1:
			 refrencetoc = CampaignMenu(refrencetoc);
			break;
		case 2:
			DisplayAllCampaignIDs(c.GetCampaignList());
			c.AddCampaignToCampaignList(c,AdMenu(GetCampaign(c.GetCampaignList())));
			break;
		case 3:
			return c;
		}

	}
	
}
void ManageCustomersMenu(AdServingEngine& a)
{
	int selection;

	cout << "1: Create new Customer" << endl;
	cout << "2: Update Customer" << endl;
	cout << "3: Read Customers" << endl;
	cout << "4: Delete Customer" << endl;
	cout << "5: Exit" << endl;

	cin >> selection;

	switch (selection)
	{
	case 1:
		a.UpdateCustomerList(CreateCustomer(a));
		break;
	case 2:
		a.UpdateCustomerList(CustomerUpdate(a.GetCustomerList()));
		break;
	case 3:
		DisplayAllCustomers(a.GetCustomerList());
		break;
	case 4:
		a.UpdateCustomerList(EraseACustomer(a.GetCustomerList()));
		break;
	case 5:
		break;
	}
}
Customer LoginToCustomer(vector<Customer>list, AdServingEngine& a)
{
	if (list.size() == 0)
	{
		cout << "No Customers in system" << endl;
		list = CreateCustomer(a);
	}

	while (true)
	{
		int userIdLogin;
		cout << "--- Login ---" << endl;
		cout << "Enter User Id";
		userIdLogin = returnIntFunction();
		for (auto x : list)
		{
			if (userIdLogin == x.GetCustomerId())
			{
				cout << "User Id: " << x.GetCustomerId() << " Logged in" << endl << endl;
				return x;
			}
		}
		cout << "No such user ID in system." << endl;
	}
	
}

int main()
{
	AdServingEngine ese;
	AdServingEngine &a = ese;
	//a.UpdateCustomerList(CreateAdmin(a));
	while(true)
	{
		int selection;

		
		cout << "1: Go to customer" << endl;
		cout << "2: Manage all customers" << endl;
		cout << "3: Show next ad" << endl;
		cout << "3: Exit" << endl;

		cout << "-> ";
		cin >> selection;

		switch (selection)
		{
		case 1:
		{
			 a.AddCustomerToCustomerList(
				 CustomerMenu(
					 a, LoginToCustomer(
						 a.GetCustomerList(), a)),a);
		}
			break;
		case 2:
			ManageCustomersMenu(a);
			break;
		case 3:
			cout << "Exiting program..." << endl << endl;
			return 0;
		}
	}
}
