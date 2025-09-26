#include "ClientManager.h"


void ClientManager::initGame() {
	string name;
	cout << "               *Приветсвую вас!*\n"
		"       *Вы попали в самую лучшую в мире*\n"
		"            *версию карточной игры*\n"
		"                 ***КОЗЁЛ***\n\n";

	name = name;
	player1 = new HumanPlayer(name);
	//table.givingCards(player1);

	name = name;
	player3 = new HumanPlayer(name);
	//table.givingCards(player3);

	name = name;
	player2 = new HumanPlayer(name);
	//table.givingCards(player2);

	name = name;
	player4 = new HumanPlayer(name);
	//table.givingCards(player4);

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
		cout << "  *Игрок: \033[40m" << player1->name << "\033[0m\n";
		printPack(player1);

		cout << endl << endl << "  *Игрок: \033[40m" << player2->name << "\033[0m\n";
		printPack(player2);

		cout << endl << endl << "  *Игрок: \033[40m" << player3->name << "\033[0m\n";
		printPack(player3);

		cout << endl << endl << "  *Игрок: \033[40m" << player4->name << "\033[0m\n";
		printPack(player4);

		cout << "                *Подсказка!*\n";
		cout << "  *Черви: c, Пики: p, Буби: b, Крести: k*\n  *Номиналы: 6, 8, 9, 10, J, Q, K, A*\n  *Ход имеет вид:*\n  *k10 - 10 крести,*\n  *bA - туз буби*\n";

		choseFirstPlayer();

		system("pause");
		system("cls");

		mode = ChoseMain;
		break;
	case First:
		printInfo();
		cout << "*Игрок: \033[40m" << currentPlayer->name << "\033[0m Ходи!\n";
		printPack(currentPlayer);

		cout << "*Ход: ";
		cin >> hod;

		if (currentPlayer->makeMove(hod, lastCard, mMast)) {

			online.outMes(currentPlayer->name + ":" + lastCard.hod);

			table.pack.push_back(lastCard);
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
			mode = deal;
		break;
	}
}