#include "Manager.h"

void Manager::initGame() {
	string name;
	cout << "Приветсвую! Введите имя 1-го игрока 1-ой команды:" << endl << endl;
	cin >> name;
	player1 = new HumanPlayer(name);
	table.givingCards(player1);
	table.printPack(player1);

	cout << "Приветсвую! Введите имя 2-го игрока 1-ой команды:" << endl << endl;
	cin >> name;
	player3 = new HumanPlayer(name);
	table.givingCards(player3);
	table.printPack(player3);

	cout << "Приветсвую! Введите имя 1-го игрока 2-ой команды:" << endl << endl;
	cin >> name;
	player2 = new HumanPlayer(name);
	table.givingCards(player2);
	table.printPack(player2);

	cout << "Приветсвую! Введите имя 2-го игрока 2-ой команды:" << endl << endl;
	cin >> name;
	player4 = new HumanPlayer(name);
	table.givingCards(player4);
	table.printPack(player4);

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
	name = currentPlayer->name;
	cout << name << endl << endl;
}