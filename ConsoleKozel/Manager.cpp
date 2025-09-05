#include "Manager.h"

void Manager::initGame() {
	string name;
	cout << "����������! ������� ��� 1-�� ������ 1-�� �������:" << endl << endl;
	cin >> name;
	player1 = new HumanPlayer(name);
	table.givingCards(player1);
	table.printPack(player1);

	cout << "����������! ������� ��� 2-�� ������ 1-�� �������:" << endl << endl;
	cin >> name;
	player3 = new HumanPlayer(name);
	table.givingCards(player3);
	table.printPack(player3);

	cout << "����������! ������� ��� 1-�� ������ 2-�� �������:" << endl << endl;
	cin >> name;
	player2 = new HumanPlayer(name);
	table.givingCards(player2);
	table.printPack(player2);

	cout << "����������! ������� ��� 2-�� ������ 2-�� �������:" << endl << endl;
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