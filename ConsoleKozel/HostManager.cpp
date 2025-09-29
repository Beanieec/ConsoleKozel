#include "HostManager.h"


void HostManager::initGame() {
	string name;

	cout << "*������� ��� 1-�� ������ 1-�� ����:\n* ";

	cout << "\033[40m";
	cin.ignore();
	getline(cin, name);
	cout << "\033[0m";
	player1 = new HumanPlayer(name);	

	cout << "\n*������� ��� 2-�� ������ 1-�� ����:\n* ";

	cout << "\033[40m";
	getline(cin, name);
	cout << "\033[0m";
	player3 = new HumanPlayer(name);

	cout << "\n*������� ��� 1-�� ������ 2-�� �������:\n* ";

	cout << "\033[40m";
	getline(cin, name);
	cout << "\033[0m";
	player2 = new HumanPlayer(name);

	cout << "\n*������� ��� 2-�� ������ 2-�� �������:\n* ";

	cout << "\033[40m";
	getline(cin, name);
	cout << "\033[0m";
	player4 = new HumanPlayer(name);

	online.outPlayer("p1", player1->name, table.givingCards(player1));
	online.outPlayer("p2", player2->name, table.givingCards(player2));
	online.outPlayer("p3", player3->name, table.givingCards(player3));
	online.outPlayer("p4", player4->name, table.givingCards(player4));
	
	table.init();

	playerChose();

	system("pause");
	system("cls");


	while (true) {
		makeMove();
		/*for (int i = 0; i < table.pack.size(); i++) {
			printCard(table.pack[i]);
		}*/
	}
}

void HostManager::makeMove() {
	
	switch (mode)
	{
	case Start:
		cout << "  *�����: \033[40m" << iamPlayer->name << "\033[0m\n";
		printPack(iamPlayer);

		cout << "                *���������!*\n";
		cout << "  *�����: c, ����: p, ����: b, ������: k*\n  *��������: 6, 8, 9, 10, J, Q, K, A*\n  *��� ����� ���:*\n  *k10 - 10 ������,*\n  *bA - ��� ����*\n";

		choseFirstPlayer();

		online.outMes("fp", currentPlayer->name, "player");
		online.outMes("h", "", "hod");

		system("pause");
		system("cls");

		if (iamPlayer == currentPlayer) {
			mode = ChoseMain;
		}
		else {
			mode = First;
		}
		break;
	case First:
		getCurrentPlayer();
		printInfo();
		if (currentPlayer == iamPlayer) {
			cout << "*�����: \033[40m" << iamPlayer->name << "\033[0m ����!\n";
			printPack(iamPlayer);
			cout << "*���: ";
			cin >> hod;
			lasthod = hod;
		}
		else {
			cout << "*�����: \033[40m" << currentPlayer->name << "\033[0m �����!\n";
			while (true) {
				if (lasthod == online.inMes("h", "hod")) {				
					Sleep(2000);	
				}
				else {	
					lasthod = online.inMes("h", "hod");
					cout << "*���: " << lasthod << "\n\n";
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
			Sleep(600);

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
			cout << "  *�������� ���!*\n\n";
			return;
		}
		cout << "\n";

		changePlayer();
		online.outMes("fp", currentPlayer->name, "player");
		break;
	case bigTits:

		printInfo();
		cout << "*�����: \033[40m" << currentPlayer->name << "\033[0m ����!\n";
		printPack(currentPlayer);

		cout << "*���: ";
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
			cout << "  *�������� ���!*\n\n";
			return;
		}
		cout << "\n";

		changePlayer();
		break;

	case ChoseDeal:

		changeDealChooser();
		int deals;
		cout << "�������� �������\n";
		cin >> deals;
		choseDeal(deals);
		mode = ChoseMain;
		break;

	case ChoseMain:
		if (choseMainMast())

			/*online.outMes("mast", mast);*/

			mode = deal;
		break;
	}
}

void HostManager::playerChose() {
	int name;
	bool isName = true;
	while (isName) {
		
		cout << "*[1]. " << player1->name << "\n"
			<< "*[2]. " << player2->name << "\n"
			<< "*[3]. " << player3->name << "\n"
			<< "*[4]. " << player4->name << "\n"
			<< "*�������� ��� ������: ";

		cin >> name;

		switch (name) {
		case 1:
			if (online.inMes("p1", "Closed") == "true") {
				system("cls");
				cout << "*���� ����� ��� �����!\n";
				continue;
			}
			else {
				iamPlayer = player1;
				online.outMes("p1", "true", "Closed");
				isName = false;
			}
			break;
		case 2:
			if (online.inMes("p2", "Closed") == "true") {
				system("cls");
				cout << "*���� ����� ��� �����!\n";
				continue;
			}
			else {
				iamPlayer = player2;
				online.outMes("p2", "true", "Closed");
				isName = false;
			}
			break;
		case 3:
			if (online.inMes("p3", "Closed") == "true") {
				system("cls");
				cout << "*���� ����� ��� �����!\n";
				continue;
			}
			else {
				iamPlayer = player3;
				online.outMes("p3", "true", "Closed");
				isName = false;
			}
			break;
		case 4:
			if (online.inMes("p4", "Closed") == "true") {
				system("cls");
				cout << "*���� ����� ��� �����!\n";
				continue;
			}
			else {
				iamPlayer = player4;
				online.outMes("p4", "true", "Closed");
				isName = false;
			}
			break;
		}
		continue;
	}

	cout << "�� ������� ��� ������: " << iamPlayer->name << "\n";
}


void HostManager::getCurrentPlayer() {
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