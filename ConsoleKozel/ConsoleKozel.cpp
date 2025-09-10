#include <Windows.h>
#include <iostream>
#include "Manager.h"


int main()
{
    UINT originalCP = GetConsoleOutputCP();
    
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Manager manager(originalCP);
    while (true) {

        manager.initGame();
    };
}
