#include "ClientManager.h"


void ClientManager::initGame() {
	
	cout << "*Подключение... 99%\n";

	player1 = new HumanPlayer(online.inMes("p1", "Player_name"));

	player3 = new HumanPlayer(online.inMes("p3", "Player_name"));

	player2 = new HumanPlayer(online.inMes("p2", "Player_name"));

	player4 = new HumanPlayer(online.inMes("p4", "Player_name"));

	system("cls");

	cout << "*Подключение установлено...\n";
	
	playerChose();

	getCards();
	

	system("pause");
	system("cls");

	while (true) {
		makeMove();
		/*for (int i = 0; i < table.pack.size(); i++) {
			printCard(table.pack[i]);
		}*/
	}
}

void ClientManager::makeMove() {

	switch (mode)
	{
	case Start:
		cout << "  *Игрок: \033[40m" << iamPlayer->name << "\033[0m\n";
		printPack(iamPlayer);

		cout << "                *Подсказка!*\n";
		cout << "  *Черви: c, Пики: p, Буби: b, Крести: k*\n  *Номиналы: 6, 8, 9, 10, J, Q, K, A*\n  *Ход имеет вид:*\n  *k10 - 10 крести,*\n  *bA - туз буби*\n";

		getCurrentPlayer();

		system("pause");
		system("cls");

		if (iamPlayer == currentPlayer) {
			mode = ChoseMain;
		}
		else {
			mast = online.inMes("mast", "Mainmast");
			findMainMast();
			mode = First;
		}
		break;
	case First:
		getCurrentPlayer();

		printInfo();
		if (currentPlayer == iamPlayer) {
			cout << "*Игрок: \033[40m" << iamPlayer->name << "\033[0m Ходи!\n";
			printPack(iamPlayer);
			cout << "*Ход: ";
			cin >> hod;
			lasthod = hod;
		}
		else {
			cout << "*Игрок: \033[40m" << currentPlayer->name << "\033[0m Ходит!\n";
			while (true) {
				if (lasthod == online.inMes("h", "hod")) {
					Sleep(1000);
				}
				else {
					lasthod = online.inMes("h", "hod");
					cout << "*Ход: " << lasthod << "\n\n";
					for (int i = 0; i < table.pack.size(); i++) {
						if (table.pack[i].hod == lasthod)
							lastCard = table.pack[i];
					}
					return;
				}
			}
		}

		if (currentPlayer->makeMove(hod, lastCard, mMast)) {
			online.outMes("h", hod, "hod");
			/*Sleep(600);*/

			if (findShaha()) {
				mode = ChoseDeal;
				return;
			}

			if (checkAndCodition()) {
				if (getWinDeal()) {
					mode = ChoseDeal;
				}
				return;
			}
		}
		else
		{
			system("cls");
			cout << "  *Неверный ход!*\n\n";
			return;
		}
		cout << "\n";

		changePlayer();
		online.outMes("fp", currentPlayer->name, "player");
		break;
	case bigTits:
		printInfo();
		cout << "*Игрок: \033[40m" << currentPlayer->name << "\033[0m Ходи!\n";
		printPack(currentPlayer);

		cout << "*Ход: ";
		cin >> hod;

		if (currentPlayer->makeMove(hod, lastCard, mMast)) {
			if (findShaha()) {
				mode = ChoseDeal;
				return;
			}
			if (checkAndCodition()) {
				if (countRound(4))
				{
					if (getWinDeal()) {

						mode = ChoseDeal;
					}

				}
				return;
			}
		}
		else
		{
			system("cls");
			cout << "  *Неверный ход!*\n\n";
			return;
		}
		cout << "\n";

		changePlayer();
		break;

	case ChoseDeal:
		changeDealChooser();
		int deals;
		cout << "Выберите хвалёнку\n";
		cin >> deals;
		choseDeal(deals);
		mode = ChoseMain;
		break;
	case ChoseMain:
		if (choseMainMast())
			online.outMes("mast", mast, "Mainmast");
			mode = deal;
		break;
	}
}

void ClientManager::playerChose() {
	int name;
	bool isName = true;
	
	while (isName) {

		cout << "*[1]. " << player1->name << "\n"
			<< "*[2]. " << player2->name << "\n"
			<< "*[3]. " << player3->name << "\n"
			<< "*[4]. " << player4->name << "\n"
			<< "*Выберите имя игрока: ";
		cin >> name;

		switch (name) {
		case 1:
			if (online.inMes("p1", "Closed") == "true") {
				system("cls");
				cout << "*Этот игрок уже занят!\n";
				continue;
			}
			else {
				iamPlayer = player1;
				online.outMes("p1", "true", "Closed");
				isName = false;
				curPlayer = "p1";
			}
			break;
		case 2:
			if (online.inMes("p2", "Closed") == "true") {
				system("cls");
				cout << "*Этот игрок уже занят!\n";
				continue;
			}
			else {
				iamPlayer = player2;
				online.outMes("p2", "true", "Closed");
				isName = false;
				curPlayer = "p2";
			}
			break;
		case 3:
			if (online.inMes("p3", "Closed") == "true") {
				system("cls");
				cout << "*Этот игрок уже занят!\n";
				continue;
			}
			else {
				iamPlayer = player3;
				online.outMes("p3", "true", "Closed");
				isName = false;
				curPlayer = "p3";
			}
			break;
		case 4:
			if (online.inMes("p4", "Closed") == "true") {
				system("cls");
				cout << "*Этот игрок уже занят!\n";
				continue;
			}
			else {
				iamPlayer = player4;
				online.outMes("p4", "true", "Closed");
				isName = false;
				curPlayer = "p4";
			}
			break;
		}
	}

	cout << "Вы играете под именем: " << iamPlayer->name << "\n";
}

void ClientManager::getCards() {
	string c;
	stringstream s(online.inMes(curPlayer, "Cards"));

	while (getline(s, c, ':')) {
		for (int i = 0; i < table.pack.size(); i++) {
			if (c == table.pack[i].hod) {
				iamPlayer->hand.push_back(table.pack[i]);
			}
		}
	}
}

void ClientManager::getCurrentPlayer() {
	string curPlayerName;
	curPlayerName = online.inMes("fp", "player");
	if (player1->name == curPlayerName)
		currentPlayer = player1;
	if (player2->name == curPlayerName)
		currentPlayer = player2;
	if (player3->name == curPlayerName)
		currentPlayer = player3;
	if (player4->name == curPlayerName)
		currentPlayer = player4;
}

