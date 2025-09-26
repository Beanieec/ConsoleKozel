#include "Firebase.h"


bool Firebase::outMes(string channel, string message, string type) {
    string url = database + channel + ".json";
    json json_body;

    json_body[type] = message;


    Response response = cpr::Patch(Url{ url }, Body{ json_body.dump()}, Header{ {"Content-Type", "application/json"} });

    if (response.status_code == 200) {
        return true;
    }
    else {
        std::cout <<"Ошибка отправки: " << response.status_code << std::endl;
        return false;
    }
}

bool Firebase::outPlayer(string channel, string name, string cards) {
    string url = database + channel + ".json";
    json json_body;

    json_body["Player_name"] = name;
    json_body["Cards"] = cards;
    json_body["Closed"] = "false";

    Response response = cpr::Put(Url{ url }, Body{ json_body.dump() }, Header{ {"Content-Type", "application/json"} });

    if (response.status_code == 200) {
        return true;
    }
    else {
        std::cout << "Ошибка отправки: " << response.status_code << std::endl;
        return false;
    }
}

//string Firebase::getCards(string channel, string type)


string Firebase::inMes(string channel, string type) {
    string url = database + channel + ".json";

    Response response = cpr::Get(cpr::Url{ url });

    if (response.status_code == 200 && response.text != "null") {

        json data = json::parse(response.text);
        
        string message = data[type];

        /*deleteMessage(channel);*/
        return message;      
    }
    else {
        cout << "Нет сообщений или ошибка" << std::endl;
        return "";
    }
}