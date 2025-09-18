#include "Manager.h"


void Manager::initGame() {
	string name;
	cout << "               *���������� ���!*\n" 
			"       *�� ������ � ����� ������ � ����*\n"
			"            *������ ��������� ����*\n"
			"                 ***��Ǩ�***\n\n"
			"*������� ��� 1-�� ������ 1-�� �������:\n* ";
	
	cout << "\033[40m";
	getline(cin, name);
	cout << "\033[0m";
	player1 = new HumanPlayer(name);
	table.givingCards(player1);
	
	cout << "\n*������� ��� 2-�� ������ 1-�� �������:\n* ";
	
	cout << "\033[40m";
	getline(cin, name);
	cout << "\033[0m";
	player3 = new HumanPlayer(name);
	table.givingCards(player3);

	cout << "\n*������� ��� 1-�� ������ 2-�� �������:\n* ";

	cout << "\033[40m";
	getline(cin, name);
	cout << "\033[0m";
	player2 = new HumanPlayer(name);
	table.givingCards(player2);

	cout << "\n*������� ��� 2-�� ������ 2-�� �������:\n* ";
	
	cout << "\033[40m";
	getline(cin, name);
	cout << "\033[0m";
	player4 = new HumanPlayer(name);
	table.givingCards(player4);
	
	system("cls");	

	while (true) {	
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
		cout << "  *�����: \033[40m" << player1->name << "\033[0m\n";
		printPack(player1);

		cout << endl << endl << "  *�����: \033[40m" << player2->name << "\033[0m\n";
		printPack(player2);

		cout << endl << endl << "  *�����: \033[40m" << player3->name << "\033[0m\n";
		printPack(player3);

		cout << endl << endl << "  *�����: \033[40m" << player4->name << "\033[0m\n";
		printPack(player4);

		cout << "                *���������!*\n";
		cout << "  *�����: c, ����: p, ����: b, ������: k*\n  *��������: 6, 8, 9, 10, J, Q, K, A*\n  *��� ����� ���:*\n  *k10 - 10 ������,*\n  *bA - ��� ����*\n";
		
		choseFirstPlayer();

		system("pause");
		system("cls");

		mode = ChoseMain;
		break;
	case Game:
		printInfo();
		cout << "*�����: \033[40m" << currentPlayer->name << "\033[0m ����!\n";
		printPack(currentPlayer);
		
		cout << "*���: ";
		cin >> hod;

		if (currentPlayer->makeMove(hod, lastCard, mMast)) {
			
			table.pack.push_back(lastCard);
			if (checkAndCodition()) {
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

		if (getWinDeal()) {
			mode = ChoseDeal;
		}

		break;
	case ChoseDeal:
		//������� ��� �����
		mode = Game;
		break;
	case ChoseMain:
		if (choseMainMast())
			mode = ChoseDeal;
		break;
	}	
}

bool Manager::getWinDeal() {
	if (player1->hand.empty() && player2->hand.empty() && player3->hand.empty() && player4->hand.empty()) {
		if (scoreT1 > 90) {
			endScoreT2 += 4;
			return true;
		}
		else if (scoreT1 > 60) {
			endScoreT2 += 2;
			return true;
		}
		if (scoreT2 > 90) {
			endScoreT1 += 4;
			return true;
		}
		else if (scoreT2 > 60) {
			endScoreT1 += 2;
			return true;
		}
		if (scoreT1 == scoreT2) {
			isWasEggs = true;
			return true;
		}
	}
	return false;
}

bool Manager::checkAndCodition() {
	stepCounter++;
	if (stepCounter <= 4) {
		realScore += lastCard.point;


		if (lastCard.level > 16) { // J Q
			if (lastCard.level > winCard.level) {
				winCard = lastCard;
				winPlayer = currentPlayer;
			}
		}
		else if (lastCard.mast == mMast) { // ������
			if (lastCard.level > winCard.level) { //������������ ��������
				winCard = lastCard;
				winPlayer = currentPlayer;
			}
		}
		else if (lastCard.level > winCard.level) { // ���������
			winCard = lastCard;
			winPlayer = currentPlayer;
		}
	}
	if (stepCounter == 4) {
		system("cls");
		cout << "*�����: \033[40m" << winPlayer->name << "\033[0m ������ ������� �� " << realScore << " ����(�/��)!\n";
		printCard(winCard);
		cout << endl;
		if (winPlayer == player1 || winPlayer == player3)
			scoreT1 += realScore;
		else
			scoreT2 += realScore;
		currentPlayer = winPlayer;
		stepCounter = 0;
		realScore = 0;
		lastCard = ukncard;
		winCard = ukncard;
		return true;
	}
	return false;
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
	}
}

void Manager::printInfo() {
	cout << "********[";
	if (scoreT1 < 10)
		cout << "0";
	cout << scoreT1 << "]********"; 
	printMast(mMast); 
	cout << "|"; printCard(lastCard); cout << "|"; 
	printMast(mMast); 
	cout << "*******[";
	if (scoreT2 < 10)
		cout << "0";
	cout << scoreT2 << "]*******\n";
}

void Manager::printPack(Player* player) {
	cout << "---------------------------------------------\n";
	cout << " | ";
	for (int i = 0; i < player->hand.size(); i++) {
		SetConsoleOutputCP(originalCP);
		cout << player->hand[i].view;
		SetConsoleOutputCP(1251);
		cout << " | ";
	}
	cout << "\n---------------------------------------------\n";
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
		cout << "\033[31m\x04\033[0m";
		break;
	case cervi:
		cout << "\033[31m\x03\033[0m";
		break;
	case piki:
		cout << "\033[30m\x06\033[0m";
		break;
	case kresti:
		cout << "\033[30m\x05\033[0m";
		break;
	}
	SetConsoleOutputCP(1251);
}

bool Manager::choseMainMast() {
	string mast;
	cout << "*�����: \033[40m" << currentPlayer->name << "\033[0m �������� ������!\n*(b, c, p, k):  ";
	cin >> mast;
	if (mast == "b") {
		mMast = bubi;
		system("cls");
		return true;
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
		cout << "*����� ����� ���!\n";
		return false;
	}
}

bool Manager::choseFirstPlayer() {
	while (true) {
		changePlayer();
		for (int i = 0; i < currentPlayer->hand.size(); i++) {
			if (currentPlayer->hand[i].card == bA) {
				return true;
			}
		}	
	}
}
