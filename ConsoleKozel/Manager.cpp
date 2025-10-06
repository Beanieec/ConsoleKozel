﻿#include "Manager.h"


void Manager::initGame() {
	string name;
	cout << "               *Приветсвую вас!*\n" 
			"       *Вы попали в самую лучшую в мире*\n"
			"            *версию карточной игры*\n"
			"                 ***КОЗЁЛ***\n\n"
			"*Введите имя 1-го игрока 1-ой команды:\n* ";
	
	cout << "\033[40m";
	getline(cin, name);
	cout << "\033[0m";
	player1 = new HumanPlayer(name);
	table.givingCards(player1);
	
	cout << "\n*Введите имя 2-го игрока 1-ой тимы:\n* ";
	
	
	cout << "\033[40m";
	getline(cin, name);
	cout << "\033[0m";
	player3 = new HumanPlayer(name);
	table.givingCards(player3);

	cout << "\n*Введите имя 1-го игрока 2-ой команды:\n* ";

	cout << "\033[40m";
	getline(cin, name);
	cout << "\033[0m";
	player2 = new HumanPlayer(name);
	table.givingCards(player2);

	cout << "\n*Введите имя 2-го игрока 2-ой команды:\n* ";
	
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

		if (currentPlayer->HonestlyMakeMove(hod, firstCard, lastCard, mMast)) {
			
			botOuter.outMes(currentPlayer->name + ":" + lastCard.hod);

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

	case SimpleDeals:
		printInfo();
		cout << "*Игрок: \033[40m" << currentPlayer->name << "\033[0m Ходи!\n";
		printPack(currentPlayer);

		cout << "*Ход: ";
		cin >> hod;

		if (currentPlayer->HonestlyMakeMove(hod,firstCard, lastCard, mMast))
		{
			if (findShaha()) 
			{
				mode = ChoseDeal;
				return;
			}
			if (checkAndCodition()) 
			{
				if (countRound(8))
				{
					if (getWinDeal())
					{
						//обновить карты
						mode = ChoseDeal;
						return;
					}
				}
				if (player1->hand.empty() && player2->hand.empty() && player3->hand.empty() && player4->hand.empty())
				{
					table.givingSimpleDeals(player1, choseDeal(deals));
					table.givingSimpleDeals(player2, choseDeal(deals));
					table.givingSimpleDeals(player3, choseDeal(deals));
					table.givingSimpleDeals(player4, choseDeal(deals));
					mode = ChoseMain;
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
		cout << "Выберите хвалёнку\n";
		cin >> deals;
		countRounder = 0;
		choseDeal(deals);
		mode = ChoseMain;
		break;

	case ChoseMain:
		if (choseMainMast())
			mode = deal;
		break;
	}
}

bool Manager::getWinDeal() {
	if (player1->hand.empty() && player2->hand.empty() && player3->hand.empty() && player4->hand.empty()) {
		if (scoreT1 >= 90) {
			endScoreT2 += 4 + Eggs;
			Eggs = 0;
			scoreT1 = 0;
			scoreT2 = 0;
			return true;
		}
		else if (scoreT1 > 60) {
			endScoreT2 += 2 + Eggs;
			Eggs = 0;
			scoreT1 = 0;
			scoreT2 = 0;
			return true;
		}
		if (scoreT2 >= 90) {
			endScoreT1 += 4 + Eggs;
			Eggs = 0;
			scoreT1 = 0;
			scoreT2 = 0;
			return true;
		}
		else if (scoreT2 > 60) {
			endScoreT1 += 2 + Eggs;
			Eggs = 0;
			scoreT1 = 0;
			scoreT2 = 0;
			return true;
		}
		if (scoreT1 == scoreT2) { //Яйца
			Eggs = 2;
			scoreT1 = 0;
			scoreT2 = 0;
			return true;
		}
		
	}
	return false;
}

bool Manager::checkAndCodition() {
	stepCounter++;
	if (stepCounter == 1) {
		gameMast = lastCard.mast;
	}
	if (stepCounter <= 4) {
		realScore += lastCard.point;


		if (lastCard.level >= 7) { // J Q
			if (lastCard.level > winCard.level) {
				winCard = lastCard;
				winPlayer = currentPlayer;
			}
		}
		else if (lastCard.mast == mMast && winCard.level < 7) { // козыри
			if (winCard.mast == mMast) {
				if (lastCard.level > winCard.level) { 
					winCard = lastCard;
					winPlayer = currentPlayer;
				}
			}
			else {
				winCard = lastCard;
				winPlayer = currentPlayer;
			}
		}
		else if (lastCard.level > winCard.level && winCard.level < 16 && winCard.mast != mMast && lastCard.mast == gameMast) { // остальные
			winCard = lastCard;
			winPlayer = currentPlayer;
		}
	}
	if (stepCounter == 4) {
		system("cls");
		cout << "*Игрок: \033[40m" << winPlayer->name << "\033[0m забрал раздачу на " << realScore << " очко(а/ов)!\n";
		printCard(winCard);
		cout << endl;
		if (winPlayer == player1 || winPlayer == player3)
			scoreT1 += realScore;
		else
			scoreT2 += realScore;
		if(mode == First) 
		{
			currentPlayer = winPlayer;
		}
		if(mode == SimpleDeals)
		{
			currentPlayer = dealChooser;
		}
		countRounder++;
		defValue();
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

void Manager::changeDealChooser() {
	if (dealChooser == player1) {
		currentPlayer = player2;
		dealChooser = player2;
	}
	else if (dealChooser == player2) {
		currentPlayer = player3;
		dealChooser = player3;
	}
	else if (dealChooser == player3) {
		currentPlayer = player4;
		dealChooser = player4;
	}
	else {
		currentPlayer = player1;
		dealChooser = player1;
	}
}

void Manager::printInfo() {
	cout << "*{";
	if (endScoreT1 < 10)
		cout << "0";
	cout << endScoreT1 << "}***[";
	if (scoreT1 < 10)
		cout << "0";
	cout << scoreT1 << "]*******"; 
	printMast(mMast); 
	cout << "|"; printCard(lastCard); cout << "|"; 
	printMast(mMast); 
	cout << "*******[";
	if (scoreT2 < 10)
		cout << "0";
	cout << scoreT2 << "]***{";
	if (endScoreT1 < 10)
		cout << "0";
	cout << endScoreT2 << "}*\n";
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
	system("cls");
	cout << "*Игрок: \033[40m" << currentPlayer->name << "\033[0m выберите козырь!\n*(b, c, p, k):  \n";
	printPack(currentPlayer);
	cin >> mast;
	
	if (mast == "b") {
		mMast = bubi;
		botOuter.outMes("mMast:bubi");
		system("cls");
		return true;
	}
	else if (mast == "c") {
		mMast = cervi;
		botOuter.outMes("mMast:cervi");
		system("cls");
		return true;
	}	
	else if (mast == "p") {
		mMast = piki;
		botOuter.outMes("mMast:piki");
		system("cls");
		return true;
	}
	else if (mast == "k") {
		mMast = kresti;
		botOuter.outMes("mMast:kresti");
		system("cls");
		return true;
	}	
	else {
		system("cls");
		cout << "*Такой масти нет!\n";
		return false;
	}
}

bool Manager::choseFirstPlayer() {
	while (true) {
		changePlayer();
		for (int i = 0; i < currentPlayer->hand.size(); i++) {
			if (currentPlayer->hand[i].card == bA) {
				dealChooser = currentPlayer;
				return true;
			}
		}	
	}
}

int Manager::choseDeal(int Deal) {
	switch (Deal) {
	case 1:
		if(countRounder == 0)
		{
			cout << table.pack.size();
			table.packShuffle();
			table.givingSimpleDeals(player1, 2);
			table.givingSimpleDeals(player2, 2);
			table.givingSimpleDeals(player3, 2);
			table.givingSimpleDeals(player4, 2);
			deal = SimpleDeals;
		}
		return 2;
		break;
	case 2:
		if (countRounder == 0)
		{
			table.packShuffle();
			table.givingSimpleDeals(player1, 4);
			table.givingSimpleDeals(player2, 4);
			table.givingSimpleDeals(player3, 4);
			table.givingSimpleDeals(player4, 4);
			deal = SimpleDeals;
		}
		return 4;
		break;
	case 3:
		if (countRounder == 0)
		{
			table.packShuffle();
			table.givingSimpleDeals(player1, 8);
			table.givingSimpleDeals(player2, 8);
			table.givingSimpleDeals(player3, 8);
			table.givingSimpleDeals(player4, 8);
			deal = SimpleDeals;
		}
		return 8;
		break;
	}
}

bool Manager::findShaha() {
	
	if (lastCard.card == k6) {
		shaha = true;
		shahaPlayer = currentPlayer;
	}
	if (lastCard.card == kQ) {
		Q = true;
		qPlayer = currentPlayer;
	}
	if (shaha && Q) {
		if ((shahaPlayer == player1 && qPlayer == player3) || (shahaPlayer == player3 && qPlayer == player1)) {
			return false;
		}
		if ((shahaPlayer == player2 && qPlayer == player4) || (shahaPlayer == player4 && qPlayer == player2)) {
			return false;
		}
		table.clearHand(player1);
		table.clearHand(player2);
		table.clearHand(player3);
		table.clearHand(player4);
		winPlayer = shahaPlayer;

		if (winPlayer == player1 || winPlayer == player3)
			endScoreT1 += 4;
		else
			endScoreT2 += 4;

		cout << winPlayer->name << " поймал даму крести!\n";
		scoreT1 = 0;
		scoreT2 = 0;
		defValue();
		return true;
	}	
	return false;
}

void Manager::defValue() {
	stepCounter = 0;
	realScore = 0;
	lastCard = ukncard;
	winCard = ukncard;
	shaha = false;
	Q = false;
}
bool Manager::countRound(int count)
{
	if (countRounder == count)
	{
		return true;
	}
	return false;
}