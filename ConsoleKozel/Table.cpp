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

void Table::givingCards(Player* player) {
    for (int i = 0; i < 8; i++) {
        CardsType card = pack.back();
        player->hand.push_back(card);
        pack.pop_back();
    }
}


