#include "Out.h"

void Out::outMes(string message) {

    // ��������� �������
    cpr::Parameters params = {
        {"chat_id", chat_id},
        {"text", message}
    };

    // ���������� POST-������
    cpr::Response response = cpr::Post(cpr::Url{ url }, params);

    //// ��������� ���������
    //if (response.status_code == 200) {
    //    std::cout << "��������� ������� ����������!" << std::endl;
    //    std::cout << "����� �������: " << response.text << std::endl;
    //}
    //else {
    //    std::cout << "������ �������� ���������!" << std::endl;
    //    std::cout << "��� ������: " << response.status_code << std::endl;
    //    std::cout << "����� ������: " << response.text << std::endl;
    //}

    /*return 0;*/
}