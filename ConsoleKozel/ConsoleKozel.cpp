#include <Windows.h>
#include <iostream>
#include "Manager.h"


int main()
{

    /*SetConsoleOutputCP(1251);*/
    setlocale(LC_ALL, "RU");
    Manager manager;
    while (true) {

        manager.initGame();
    }
}
