#include "Manager.h"

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


		if (lastCard.level >= 16) { // J Q
			if (lastCard.level > winCard.level) {
				winCard = lastCard;
				winPlayer = currentPlayer;
			}
		}
		else if (lastCard.mast == mMast && winCard.level < 16) { // козыри
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
		if (mode == First) {
			currentPlayer = winPlayer;
		}
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
	}
	else if (dealChooser == player2) {
		currentPlayer = player3;
	}
	else if (dealChooser == player3) {
		currentPlayer = player4;
	}
	else {
		currentPlayer = player1;
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

	cout << "*Игрок: \033[40m" << currentPlayer->name << "\033[0m выберите козырь!\n*(bubi, cervi, piki, kresti):  ";
	cin >> mast;
	if (findMainMast()) {
		return true;
	}
	else {
		system("cls");
		cout << "*Такой масти нет!\n";
		return false;
	}

}
	
bool Manager::findMainMast() {

	if (mast == "bubi") {
		mMast = bubi;
		system("cls");
		return true;
	}
	else if (mast == "cervi") {
		mMast = cervi;
		system("cls");
		return true;
	}	
	else if (mast == "piki") {
		mMast = piki;
		system("cls");
		return true;
	}
	else if (mast == "kresti") {
		mMast = kresti;
		system("cls");
		return true;
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

void Manager::choseDeal(int deal) {
	switch (deal) {
	case 1:
		table.packShuffle();
		table.givingCards(player1);
		table.givingCards(player2);
		table.givingCards(player3);
		table.givingCards(player4);
		break;
	case 2:
		deal = bigTits;
		table.packShuffle();
		table.givingBigTits(player1);
		table.givingBigTits(player2);
		table.givingBigTits(player3);
		table.givingBigTits(player4);
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
	countRounder++;
	if(countRounder == count)
	{
		table.givingBigTits(player1);
		table.givingBigTits(player2);
		table.givingBigTits(player3);
		table.givingBigTits(player4);
		return true;
	}
	return false;
}