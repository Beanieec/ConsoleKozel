#include "HostManager.h"


void HostManager::initGame() {
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
	

	cout << "\n*������� ��� 2-�� ������ 1-�� ����:\n* ";


	cout << "\033[40m";
	getline(cin, name);
	cout << "\033[0m";
	player3 = new HumanPlayer(name);
	//table.givingCards(player3);

	cout << "\n*������� ��� 1-�� ������ 2-�� �������:\n* ";

	cout << "\033[40m";
	getline(cin, name);
	cout << "\033[0m";
	player2 = new HumanPlayer(name);
	//table.givingCards(player2);

	cout << "\n*������� ��� 2-�� ������ 2-�� �������:\n* ";

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
		cout << "  *�����: \033[40m" << iamPlayer->name << "\033[0m\n";
		printPack(iamPlayer);
		/*printPack(player2);
		printPack(player3);
		printPack(player4);*/

		cout << "                *���������!*\n";
		cout << "  *�����: c, ����: p, ����: b, ������: k*\n  *��������: 6, 8, 9, 10, J, Q, K, A*\n  *��� ����� ���:*\n  *k10 - 10 ������,*\n  *bA - ��� ����*\n";

		choseFirstPlayer();

		botOuter.outMes("fp:" + currentPlayer->name);

		system("pause");
		system("cls");

		mode = ChoseMain;
		break;
	case First:

		printInfo();
		if (currentPlayer == iamPlayer) {
			cout << "*�����: \033[40m" << iamPlayer->name << "\033[0m ����!\n";
			printPack(iamPlayer);
			cout << "*���: ";
			cin >> hod;
			botOuter.outMes("h:" + currentPlayer->name + ":" + hod);
		}
		else {
			cout << "*�����: \033[40m" << currentPlayer->name << "\033[0m �����!\n";
			cout << "*���: "; //�������� ���
			hod = hod; //��� �� ����
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

			botOuter.outMes(mast);

			mode = deal;
		break;
	}
}