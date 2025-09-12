#include "Manager.h"


void Manager::initGame() {
	string name;
	cout << "Приветсвую! Введите имя 1-го игрока 1-ой команды:" << endl << endl;

	getline(cin, name);
	player1 = new HumanPlayer(name);
	table.givingCards(player1);
	

	cout << "Приветсвую! Введите имя 2-го игрока 1-ой команды:" << endl << endl;

	getline(cin, name);
	player3 = new HumanPlayer(name);
	table.givingCards(player3);


	cout << "Приветсвую! Введите имя 1-го игрока 2-ой команды:" << endl << endl;

	getline(cin, name);
	player2 = new HumanPlayer(name);
	table.givingCards(player2);


	cout << "Приветсвую! Введите имя 2-го игрока 2-ой команды:" << endl << endl;
	
	getline(cin, name);
	player4 = new HumanPlayer(name);
	table.givingCards(player4);
	
	system("cls");
	cout << "Игрок: " << player1->name << endl;
	printPack(player1);
	
	cout << endl << endl << "Игрок: " << player2->name << endl;
	printPack(player2);

	cout << endl << endl << "Игрок: " << player3->name << endl;
	printPack(player3);

	cout << endl << endl << "Игрок: " << player4->name << endl;
	printPack(player4);

	cout << "  *Подсказка!*\n";
	cout << "  *Черви = c, Пики = p, Буби = b, Крести = k*\n  *Номиналы: 6, 8, 9, 10, J, Q, K, A*\n  *Ход имеет вид: k10 - 10 крести, bA - туз буби*\n";
	
	currentPlayer = player1;

	system("pause");
	system("cls");

	while (!player4->hand.empty()) {
		makeMove();
	}

}

void Manager::makeMove() {
	
	cout << "**********************|"; printCard(lastCard); cout << "|********************\n";
	cout << "Игрок: " << currentPlayer->name << " Ходи!\n";
	printPack(currentPlayer);
	string hod;
	cout << "Ход: ";
	cin >> hod;
	

	if (currentPlayer->makeMove(stringToCard(hod))) {
		table.pack.push_back(stringToCard(hod));
		lastCard = stringToCard(hod);
	}
	else
	{
		system("cls");
		cout << "Неверный ход!\n\n";
		return;
	}
	cout << "\n\n";


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
		cout << cardToString(player->hand[i]);
		SetConsoleOutputCP(1251);
		cout << " | ";
	}
	cout << "\n--------------------------------------------\n";
}

void Manager::printCard(CardsType card) {
	SetConsoleOutputCP(originalCP);
	cout << cardToString(card);
	SetConsoleOutputCP(1251);
}

string Manager::cardToString(CardsType card) {
	switch (card) {
	case bA: return "A\x04";
	case cA: return "A\x03";
	case pA: return "A\x06";
	case kA: return "A\x05";
	case b10: return "10\x04";
	case c10: return "10\x03";
	case p10: return "10\x06";
	case k10: return "10\x05";
	case bK: return "K\x04";
	case cK: return "K\x03";
	case pK: return "K\x06";
	case kK: return "K\x05";
	case bQ: return "Q\x04";
	case cQ: return "Q\x03";
	case pQ: return "Q\x06";
	case kQ: return "Q\x05";
	case bJ: return "J\x04";
	case cJ: return "J\x03";
	case pJ: return "J\x06";
	case kJ: return "J\x05";
	case b9: return "9\x04";
	case c9: return "9\x03";
	case p9: return "9\x06";
	case k9: return "9\x05";
	case b8: return "8\x04";
	case c8: return "8\x03";
	case p8: return "8\x06";
	case k8: return "8\x05";
	case b6: return "6\x04";
	case c6: return "6\x03";
	case p6: return "6\x06";
	case k6: return "6\x05";
	case ukncard: return "";
	}
}

CardsType Manager::stringToCard(string card) {
	if (card == "bA") return bA;
	else if (card == "cA") return cA;
	else if (card == "pA") return pA;
	else if (card == "kA") return kA;

	else if (card == "b10") return b10;
	else if (card == "c10") return c10;
	else if (card == "p10") return p10;
	else if (card == "k10") return k10;

	else if (card == "bK") return bK;
	else if (card == "cK") return cK;
	else if (card == "pK") return pK;
	else if (card == "kK") return kK;

	else if (card == "bQ") return bQ;
	else if (card == "cQ") return cQ;
	else if (card == "pQ") return pQ;
	else if (card == "kQ") return kQ;

	else if (card == "bJ") return bJ;
	else if (card == "cJ") return cJ;
	else if (card == "pJ") return pJ;
	else if (card == "kJ") return kJ;

	else if (card == "b9") return b9;
	else if (card == "c9") return c9;
	else if (card == "p9") return p9;
	else if (card == "k9") return k9;

	else if (card == "b8") return b8;
	else if (card == "c8") return c8;
	else if (card == "p8") return p8;
	else if (card == "k8") return k8;

	else if (card == "b6") return b6;
	else if (card == "c6") return c6;
	else if (card == "p6") return p6;
	else if (card == "k6") return k6;

	else return ukncard;
}