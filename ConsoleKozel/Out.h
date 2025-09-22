#pragma once
#include <iostream>
#include <string>
#include <cpr/cpr.h>

using namespace std;

class Out {
private:
	string bot_token = "8378586642:AAEJmiJprKroe90BD-ZUPGru8Ec-r65ghbI";
	string chat_id = "-1002969079725";
	string url = "https://api.telegram.org/bot" + bot_token + "/sendMessage";
public:
	void outMes(string message);
};