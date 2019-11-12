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

	AdType GetAdType();
	int GetAdID();
	void ChangeAdText(string adText);

};