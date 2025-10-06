#include "HumanPlayer.h"


bool HumanPlayer::makeMove(string hod, Cards& card, Mast mast)
{

	for (int i = 0; i < hand.size(); i++) 
	{
		if (hod == hand[i].hod) 
		{
			card = hand[i];
			hand.erase(hand.cbegin() + i);
			return true;
		}
	}
	return false;
}

bool HumanPlayer::HonestlyMakeMove(string hod, Cards firstCard, Cards& card, Mast mast)
{
	bool FlagTrump = false;
	bool FlagSimple = false;
	for (int i = 0; i < hand.size(); i++)
	{
		if (hand[i].level >= 7 || hand[i].mast == mast)
		{
			FlagTrump = true;
		}
		if (hand[i].mast == firstCard.mast && hand[i].level < 7)
		{
			FlagSimple = false;
		}
		if (hod == hand[i].hod)
		{
			firstCard = hand[i];

			if (firstCard.level >= 7 || firstCard.mast == mast)
			{
				if (hand[i].level >= 7 || hand[i].mast == mast)
				{
					card = hand[i];
					hand.erase(hand.cbegin() + i);
					return true;
				}
				else
				{
					if (!FlagTrump)
					{
						card = hand[i];
						hand.erase(hand.cbegin() + i);
						return true;
					}
					return false;
				}
			}
			else
			{
				if (hand[i].mast == firstCard.mast && hand[i].level < 7)
				{
					card = hand[i];
					hand.erase(hand.cbegin() + i);
					return true;
				}
				else
				{
					if (!FlagSimple)
					{
						card = hand[i];
						hand.erase(hand.cbegin() + i);
						return true;
					}
				}

			}
		}
	}
	return false;
}
