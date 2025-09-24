#include "HostManager.h"


void HostManager::initGame() {
	string name;
	cout << "               *Приветсвую вас!*\n"
		"       *Вы попали в самую лучшую в мире*\n"
		"            *версию карточной игры*\n"
		"                 ***КОЗЁЛ***\n\n"
		"*Введите имя 1-го игрока 1-ой команды:\n* ";

	cout << "\033[40m";
	cin.get();
	getline(cin, name);
	cout << "\033[0m";
	player1 = new HumanPlayer(name);
	

	cout << "\n*Введите имя 2-го игрока 1-ой тимы:\n* ";


	cout << "\033[40m";
	getline(cin, name);
	cout << "\033[0m";
	player3 = new HumanPlayer(name);
	//table.givingCards(player3);

	cout << "\n*Введите имя 1-го игрока 2-ой команды:\n* ";

	cout << "\033[40m";
	getline(cin, name);
	cout << "\033[0m";
	player2 = new HumanPlayer(name);
	//table.givingCards(player2);

	cout << "\n*Введите имя 2-го игрока 2-ой команды:\n* ";

	cout << "\033[40m";
	getline(cin, name);
	cout << "\033[0m";
	player4 = new HumanPlayer(name);
	//table.givingCards(player4);

	botOuter.outMes("p1:" + player1->name + table.givingCards(player1) +
		";\np2:" + player2->name + table.givingCards(player2) + 
		";\np3:" + player3->name + table.givingCards(player3) + 
		";\np4:" + player4->name + table.givingCards(player4));

	iamPlayer = player1;

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
		cout << "  *Игрок: \033[40m" << iamPlayer->name << "\033[0m\n";
		printPack(iamPlayer);
		/*printPack(player2);
		printPack(player3);
		printPack(player4);*/

		cout << "                *Подсказка!*\n";
		cout << "  *Черви: c, Пики: p, Буби: b, Крести: k*\n  *Номиналы: 6, 8, 9, 10, J, Q, K, A*\n  *Ход имеет вид:*\n  *k10 - 10 крести,*\n  *bA - туз буби*\n";

		choseFirstPlayer();

		botOuter.outMes("fp:" + currentPlayer->name);

		system("pause");
		system("cls");

		mode = ChoseMain;
		break;
	case First:

		printInfo();
		if (currentPlayer == iamPlayer) {
			cout << "*Игрок: \033[40m" << iamPlayer->name << "\033[0m Ходи!\n";
			printPack(iamPlayer);
			cout << "*Ход: ";
			cin >> hod;
			botOuter.outMes("h:" + currentPlayer->name + ":" + hod);
		}
		else {
			cout << "*Игрок: \033[40m" << currentPlayer->name << "\033[0m Ходит!\n";
			cout << "*Ход: "; //получить ход
			hod = hod; //ход от бота
		}

		if (currentPlayer->makeMove(hod, lastCard, mMast)) {

			
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

			botOuter.outMes(mast);

			mode = deal;
		break;
	}
}