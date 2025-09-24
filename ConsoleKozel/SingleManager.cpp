#include "SingleManager.h"


void SingleManager::initGame() {
	string name;
	cout << "               *���������� ���!*\n"
		"       *�� ������ � ����� ������ � ����*\n"
		"            *������ ��������� ����*\n"
		"                 ***��Ǩ�***\n\n"
		"*������� ��� 1-�� ������ 1-�� �������:\n* ";

	cout << "\033[40m";
	cin.get();
	getline(cin, name);
	cout << "\033[0m";
	player1 = new HumanPlayer(name);
	table.givingCards(player1);

	cout << "\n*������� ��� 2-�� ������ 1-�� ����:\n* ";


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

void SingleManager::makeMove() {

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
	case First:
		printInfo();
		cout << "*�����: \033[40m" << currentPlayer->name << "\033[0m ����!\n";
		printPack(currentPlayer);

		cout << "*���: ";
		cin >> hod;

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
			cout << "  *�������� ���!*\n\n";
			return;
		}
		cout << "\n";

		changePlayer();
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
			mode = deal;
		break;
	}
}