#include "HumanPlayer.h"


bool HumanPlayer::makeMove(CardsType hod) {

	this->lastHod = hod;
	for (int i = 0; i < hand.size(); i++) {
		if (lastHod == hand[i]) {
			
			hand.erase(hand.cbegin() + i);
			return true;
		}
	}
	return false;
}