#include "Manager.h"


void Manager::initGame() {
	string name;
	cout << "����������!\n������� ��� 1-�� ������ 1-�� �������:" << endl << endl;

	getline(cin, name);
	player1 = new HumanPlayer(name);
	table.givingCards(player1);
	

	cout << "������� ��� 2-�� ������ 1-�� �������:" << endl << endl;

	getline(cin, name);
	player3 = new HumanPlayer(name);
	table.givingCards(player3);


	cout << "������� ��� 1-�� ������ 2-�� �������:" << endl << endl;

	getline(cin, name);
	player2 = new HumanPlayer(name);
	table.givingCards(player2);


	cout << "������� ��� 2-�� ������ 2-�� �������:" << endl << endl;
	
	getline(cin, name);
	player4 = new HumanPlayer(name);
	table.givingCards(player4);
	
	system("cls");
	cout << "�����: " << player1->name << endl;
	printPack(player1);
	
	cout << endl << endl << "�����: " << player2->name << endl;
	printPack(player2);

	cout << endl << endl << "�����: " << player3->name << endl;
	printPack(player3);

	cout << endl << endl << "�����: " << player4->name << endl;
	printPack(player4);

	cout << "  *���������!*\n";
	cout << "  *�����: c, ����: p, ����: b, ������: k*\n  *��������: 6, 8, 9, 10, J, Q, K, A*\n  *��� ����� ���:\n  k10 - 10 ������,\n  bA - ��� ����*\n";
	
	currentPlayer = player1;

	system("pause");
	system("cls");	

	while (!player4->hand.empty()) {
		
		makeMove();
		/*for (int i = 0; i < table.pack.size(); i++) {
			printCard(table.pack[i]);
		}*/	
	}
}

void Manager::makeMove() {
	
	switch (mode)
	{
	case Start:
		if(mainMast())
			mode = Game;
		/*for (int i = 0; i < hand.size(); i++) {
			if (hand[i].mast == mMast) {
				hand[i].isMain = true;
			}
		}*/
		break;
	case Game:
		cout << "\n********["; printMast(mMast); cout << "]********|"; printCard(lastCard); cout << "|*******["; printMast(mMast); cout << "]*******\n";
		cout << "�����: " << currentPlayer->name << " ����!\n";
		printPack(currentPlayer);
		
		cout << "���: ";
		cin >> hod;

		if (currentPlayer->makeMove(hod, lastCard)) {
			table.pack.push_back(lastCard);
		}
		else
		{
			system("cls");
			cout << "  *�������� ���!*\n";
			return;
		}
		cout << "\n\n";

		changePlayer();
		break;
	case ChoseDeal:
		break;
	case ChoseMain:
		break;
	}



	
	
	

	
}

void Manager::changePlayer() {
	if (currentPlayer == player1) {
		currentPlayer = player2;
	}
	else if (currentPlayer == player2) {
		currentPlayer = player3;
	}
	else if (currentPlayer == player3) {
		currentPlayer = player4;
	}
	else {
		currentPlayer = player1;
		system("cls");
	}
}

void Manager::printPack(Player* player) {
	cout << "--------------------------------------------\n";
	cout << " | ";
	for (int i = 0; i < player->hand.size(); i++) {
		SetConsoleOutputCP(originalCP);
		cout << player->hand[i].view;
		SetConsoleOutputCP(1251);
		cout << " | ";
	}
	cout << "\n--------------------------------------------\n";
}

void Manager::printCard(Cards card) {
	SetConsoleOutputCP(originalCP);
	cout << card.view;
	SetConsoleOutputCP(1251);
}

void Manager::printMast(Mast mast) {
	SetConsoleOutputCP(originalCP);
	switch (mast)
	{
	case bubi:
		cout << "\033[31m\x04\x04\x04\033[0m";
		break;
	case cervi:
		cout << "\033[31m\x03\x03\x03\033[0m";
		break;
	case piki:
		cout << "\033[30m\x06\x06\x06\033[0m";
		break;
	case kresti:
		cout << "\033[30m\x05\x05\x05\033[0m";
		break;
	}
	SetConsoleOutputCP(1251);
}

bool Manager::mainMast() {
	string mast;
	cout << "�����: " << player1->name << " �������� ������:" << endl;
	cin >> mast;
	if (mast == "b") {
		mMast = bubi;
		system("cls");
		return false;
	}
	else if (mast == "c") {
		mMast = cervi;
		system("cls");
		return true;
	}	
	else if (mast == "p") {
		mMast = piki;
		system("cls");
		return true;
	}
	else if (mast == "k") {
		mMast = kresti;
		system("cls");
		return true;
	}	
	else {
		system("cls");
		cout << "�������� �����!\n";
		return false;
	}
}
