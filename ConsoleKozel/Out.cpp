#include "Out.h"

void Out::outMes(string message) {

    // Параметры запроса
    cpr::Parameters params = {
        {"chat_id", chat_id},
        {"text", message}
    };

    // Отправляем POST-запрос
    cpr::Response response = cpr::Post(cpr::Url{ url }, params);

    //// Проверяем результат
    //if (response.status_code == 200) {
    //    std::cout << "Сообщение успешно отправлено!" << std::endl;
    //    std::cout << "Ответ сервера: " << response.text << std::endl;
    //}
    //else {
    //    std::cout << "Ошибка отправки сообщения!" << std::endl;
    //    std::cout << "Код ошибки: " << response.status_code << std::endl;
    //    std::cout << "Текст ошибки: " << response.text << std::endl;
    //}

    /*return 0;*/
}