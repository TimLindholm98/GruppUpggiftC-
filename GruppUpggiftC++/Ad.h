#pragma once
#include<vector>
#include<string>
#include"adType.h"
using namespace std;

class Ad
{
private:
	string name;
	int id;
	string adText;
	AdType adType;

public:
	Ad(string name, int id, string adText, AdType adType);

	string GetName();
	int GetAdID();
	string GetAdText();
	AdType GetAdType();

	void ChangeAdName(string name);
	void ChangeAdID(int id);
	void ChangeAdText(string adText);
	void ChangeAdType(AdType adType);

};
