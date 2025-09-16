#include "HumanPlayer.h"


bool HumanPlayer::makeMove(string hod, Cards& card, Mast mast) {

	for (int i = 0; i < hand.size(); i++) {
		if (hod == hand[i].hod) {
			card = hand[i];
			hand.erase(hand.cbegin() + i);
			return true;
		}
	}
	return false;
}