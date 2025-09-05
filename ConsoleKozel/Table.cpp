#include "Table.h"

Table::Table() {
    pack = { bA, cA, pA, kA,
            b10, c10, p10, k10,
            bK, cK, pK, kK,
            bQ, cQ, pQ, kQ,
            bJ, cJ, pJ, kJ,
            b9, c9, p9, k9,
            b8, c8, p8, k8,
            b6, c6, p6, k6 };
    packShuffle();
}

void Table::packShuffle() {
    srand(time(0));
    shuffle(pack.begin(), pack.end(), mt19937(rand()));
}

void Table::printPack(Player* player) {
    for (int i = 0; i < player->hand.size(); i++) {
        cout << cardToString(player->hand[i]);
        cout << " | ";
    }
    cout << endl << endl;
}

void Table::givingCards(Player* player) {
    for (int i = 0; i < 8; i++) {
        CardsType card = pack.back();
        player->hand.push_back(card);
        pack.pop_back();
    }
}

string Table::cardToString(CardsType card) {
    switch (card) {
    case bA: return "A\x04";
    case cA: return "A\x03";
    case pA: return "A\x06";
    case kA: return "A\x05";
    case b10: return "10\x04";
    case c10: return "10\x03";
    case p10: return "10\x06";
    case k10: return "10\x05";
    case bK: return "K\x04";
    case cK: return "K\x03";
    case pK: return "K\x06";
    case kK: return "K\x05";
    case bQ: return "Q\x04";
    case cQ: return "Q\x03";
    case pQ: return "Q\x06";
    case kQ: return "Q\x05";
    case bJ: return "J\x04";
    case cJ: return "J\x03";
    case pJ: return "J\x06";
    case kJ: return "J\x05";
    case b9: return "9\x04";
    case c9: return "9\x03";
    case p9: return "9\x06";
    case k9: return "9\x05";
    case b8: return "8\x04";
    case c8: return "8\x03";
    case p8: return "8\x06";
    case k8: return "8\x05";
    case b6: return "6\x04";
    case c6: return "6\x03";
    case p6: return "6\x06";
    case k6: return "6\x05";
    }
}