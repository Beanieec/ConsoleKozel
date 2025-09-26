#pragma once
#include <iostream>
#include <string>
#include <cpr/cpr.h>
#include <nlohmann/json.hpp>

using namespace std;
using namespace cpr;
using json = nlohmann::json;

class Firebase {
private:
	string database = "https://ckozel-3f285-default-rtdb.europe-west1.firebasedatabase.app/";
	
public:
	bool outPlayer(string channel, string name, string cards);
	bool outMes(string channel, string message, string type);
	string inMes(string channel, string type);
};