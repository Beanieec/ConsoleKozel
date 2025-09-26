#include "Firebase.h"


bool Firebase::outMes(string message) {
    string json_body =
        "{\"message\":\"" + message + "\"}";

    cpr::Response response = cpr::Put(
        cpr::Url{ url },
        cpr::Body{ json_body },
        cpr::Header{ {"Content-Type", "application/json"} }
    );

    if (response.status_code == 200) {
        std::cout << "��������� ����������: " << message << std::endl;
        return true;
    }
    else {
        std::cout <<"������ �������� : " << response.status_code << std::endl;
        return false;
    }
}

string Firebase::inMes() {

    cpr::Response response = cpr::Get(cpr::Url{ url });

    if (response.status_code == 200 && response.text != "null") {

        std::string message = response.text;
        std::cout << "��������� �������� : " << message << std::endl;

        /*deleteMessage(channel);*/

        return message;      
    }
    else {
        std::cout << "��� ��������� ��� ������" << std::endl;
        return "";
    }
}