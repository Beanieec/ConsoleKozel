#include <Windows.h>
#include <iostream>
#include "Manager.h"
#include "SingleManager.h"
#include "ClientManager.h"
#include "HostManager.h"
#include "SOMode.h"

UINT originalCP = GetConsoleOutputCP();
SOMode somode;
Manager* manager;

bool choseMode();
void choseSOMode();

int main()
{    
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    choseMode();
    choseSOMode();

    system("cls");
    manager->initGame();
}

bool choseMode() {  
    int regim = -1;
    while (true) {
        cout << "Выберите режим игры:\n*1.Одиночная игра\n*2.Создать игру по сети\n*3.Подключиться к существующей игре\n* ";
        cin >> regim;

        switch (regim)
        {
        case 1:
            somode = Single;
            return true;
            break;
        case 2:
            somode = Host;
            return true;
            break;
        case 3:
            somode = Client;
            return true;
            break;
        }
        return false;
    }
}

void choseSOMode() {
    switch (somode)
    {
    case Host:
        manager = new HostManager(originalCP);
        break;
    case Client:
        manager = new ClientManager(originalCP);
        break;
    case Single:
        manager = new SingleManager(originalCP);
        break;
    }
}