#pragma once
#include <iostream>
#include <string>
#include <cpr/cpr.h>

using namespace std;

class Firebase {
private:
	string database = "https://ckozel-3f285-default-rtdb.europe-west1.firebasedatabase.app/";
	string channel = "test_channnel";
	string url = database + channel + ".json";
public:
	bool outMes(string message);
	string inMes();
};