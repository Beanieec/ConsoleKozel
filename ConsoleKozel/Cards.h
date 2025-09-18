#pragma once
#include <string>

using namespace std;

enum CardsType {
	bA, cA, pA, kA,
	b10, c10, p10, k10,
	bK, cK, pK, kK,
	bQ, cQ, pQ, kQ,
	bJ, cJ, pJ, kJ,
	b9, c9, p9, k9,
	b8, c8, p8, k8,
	b6, c6, p6, k6,
	ukncard
};

enum Mast {
	bubi, cervi, piki, kresti
};

class Cards {
public:
	CardsType card;
	int point;
	string view;
	string hod;
	Mast mast;
	int level;
	Cards(CardsType card);
private:

	void initbA();
	void initcA();
	void initpA();
	void initkA();
	void initb10();
	void initc10();
	void initp10();
	void initk10();
	void initbK();
	void initcK();
	void initpK();
	void initkK();
	void initbQ();
	void initcQ();
	void initpQ();
	void initkQ();
	void initbJ();
	void initcJ();
	void initpJ();
	void initkJ();
	void initb9();
	void initc9();
	void initp9();
	void initk9();
	void initb8();
	void initc8();
	void initp8();
	void initk8();
	void initb6();
	void initc6();
	void initp6();
	void initk6();
	void initukncard();
};