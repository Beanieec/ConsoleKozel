#include "Cards.h"

Cards::Cards(CardsType card) {
	switch (card)
	{
	case bA:
		initbA();
		break;
	case cA:
		initcA();
		break;
	case pA:
		initpA();
		break;
	case kA:
		initkA();
		break;
	case b10:
		initb10();
		break;
	case c10:
		initc10();
		break;
	case p10:
		initp10();
		break;
	case k10:
		initk10();
		break;
	case bK:
		initbK();
		break;
	case cK:
		initcK();
		break;
	case pK:
		initpK();
		break;
	case kK:
		initkK();
		break;
	case bQ:
		initbQ();
		break;
	case cQ:
		initcQ();
		break;
	case pQ:
		initpQ();
		break;
	case kQ:
		initkQ();
		break;
	case bJ:
		initbJ();
		break;
	case cJ:
		initcJ();
		break;
	case pJ:
		initpJ();
		break;
	case kJ:
		initkJ();
		break;
	case b9:
		initb9();
		break;
	case c9:
		initc9();
		break;
	case p9:
		initp9();
		break;
	case k9:
		initk9();
		break;
	case b8:
		initb8();
		break;
	case c8:
		initc8();
		break;
	case p8:
		initp8();
		break;
	case k8:
		initk8();
		break;
	case b6:
		initb6();
		break;
	case c6:
		initc6();
		break;
	case p6:
		initp6();
		break;
	case k6:
		initk6();
		break;
	case ukncard:
		initukncard();
		break;
	}
}

void Cards::initbA() {
	this->card = bA;
	this->point = 11;
	this->view = "A\033[31m\x04\033[0m";
	this->hod = "bA";
	this->mast = bubi;
	this->level = 6;
}

void Cards::initcA() {
	this->card = cA;
	this->point = 11;
	this->view = "A\033[31m\x03\033[0m";
	this->hod = "cA";
	this->mast = cervi;
	this->level = 6;
}
void Cards::initpA() {
	this->card = pA;
	this->point = 11;
	this->view = "A\033[30m\x06\033[0m";
	this->hod = "pA";
	this->mast = piki;
	this->level = 6;
}
void Cards::initkA() {
	this->card = kA;
	this->point = 11;
	this->view = "A\033[30m\x05\033[0m";
	this->hod = "kA";
	this->mast = kresti;
	this->level = 6;
}
void Cards::initb10() {
	this->card = b10;
	this->point = 10;
	this->view = "10\033[31m\x04\033[0m";
	this->hod = "b10";
	this->mast = bubi;
	this->level = 5;
}
void Cards::initc10() {
	this->card = c10;
	this->point = 10;
	this->view = "10\033[31m\x03\033[0m";
	this->hod = "c10";
	this->mast = cervi;
	this->level = 5;
}
void Cards::initp10() {
	this->card = p10;
	this->point = 10;
	this->view = "10\033[30m\x06\033[0m";
	this->hod = "p10";
	this->mast = piki;
	this->level = 5;
}
void Cards::initk10() {
	this->card = k10;
	this->point = 10;
	this->view = "10\033[30m\x05\033[0m";
	this->hod = "k10";
	this->mast = kresti;
	this->level = 5;
}
void Cards::initbK() {
	this->card = bK;
	this->point = 4;
	this->view = "K\033[31m\x04\033[0m";
	this->hod = "bK";
	this->mast = bubi;
	this->level = 4;
}
void Cards::initcK() {
	this->card = cK;
	this->point = 4;
	this->view = "K\033[31m\x03\033[0m";
	this->hod = "cK";
	this->mast = cervi;
	this->level = 4;
}
void Cards::initpK() {
	this->card = pK;
	this->point = 4;
	this->view = "K\033[30m\x06\033[0m";
	this->hod = "pK";
	this->mast = piki;
	this->level = 4;
}
void Cards::initkK() {
	this->card = kK;
	this->point = 4;
	this->view = "K\033[30m\x05\033[0m";
	this->hod = "kK";
	this->mast = kresti;
	this->level = 4;
}
void Cards::initbQ() {
	this->card = bQ;
	this->point = 3;
	this->view = "Q\033[31m\x04\033[0m";
	this->hod = "bQ";
	this->mast = bubi;
	this->level = 11;
}
void Cards::initcQ() {//
	this->card = cQ;
	this->point = 3;
	this->view = "Q\033[31m\x03\033[0m";
	this->hod = "cQ";
	this->mast = cervi;
	this->level = 12;
}
void Cards::initpQ() {
	this->card = pQ;
	this->point = 3;
	this->view = "Q\033[30m\x06\033[0m";
	this->hod = "pQ";
	this->mast = piki;
	this->level = 13;
}
void Cards::initkQ() {
	this->card = kQ;
	this->point = 3;
	this->view = "Q\033[30m\x05\033[0m";
	this->hod = "kQ";
	this->mast = kresti;
	this->level = 14;
}
void Cards::initbJ() {
	this->card = bJ;
	this->point = 2;
	this->view = "J\033[31m\x04\033[0m";
	this->hod = "bJ";
	this->mast = bubi;
	this->level = 7;
}
void Cards::initcJ() {
	this->card = cJ;
	this->point = 2;
	this->view = "J\033[31m\x03\033[0m";
	this->hod = "cJ";
	this->mast = cervi;
	this->level = 8;
}
void Cards::initpJ() {
	this->card = pJ;
	this->point = 2;
	this->view = "J\033[30m\x06\033[0m";
	this->hod = "pJ";
	this->mast = piki;
	this->level = 9;
}
void Cards::initkJ() {
	this->card = kJ;
	this->point = 2;
	this->view = "J\033[30m\x05\033[0m";
	this->hod = "kJ";
	this->mast = kresti;
	this->level = 10;
}
void Cards::initb9() {
	this->card = b9;
	this->point = 0;
	this->view = "9\033[31m\x04\033[0m";
	this->hod = "b9";
	this->mast = bubi;
	this->level = 3;
}
void Cards::initc9() {
	this->card = c9;
	this->point = 0;
	this->view = "9\033[31m\x03\033[0m";
	this->hod = "c9";
	this->mast = cervi;
	this->level = 3;
}
void Cards::initp9() {
	this->card = p9;
	this->point = 0;
	this->view = "9\033[30m\x06\033[0m";
	this->hod = "p9";
	this->mast = piki;
	this->level = 3;
}
void Cards::initk9() {
	this->card = k9;
	this->point = 0;
	this->view = "9\033[30m\x05\033[0m";
	this->hod = "k9";
	this->mast = kresti;
	this->level = 3;
}
void Cards::initb8() {
	this->card = b8;
	this->point = 0;
	this->view = "8\033[31m\x04\033[0m";
	this->hod = "b8";
	this->mast = bubi;
	this->level = 2;
}
void Cards::initc8() {
	this->card = c8;
	this->point = 0;
	this->view = "8\033[31m\x03\033[0m";
	this->hod = "c8";
	this->mast = cervi;
	this->level = 2;
}
void Cards::initp8() {
	this->card = p8;
	this->point = 0;
	this->view = "8\033[30m\x06\033[0m";
	this->hod = "p8";
	this->mast = piki;
	this->level = 2;
}
void Cards::initk8() {
	this->card = k8;
	this->point = 0;
	this->view = "8\033[30m\x05\033[0m";
	this->hod = "k8";
	this->mast = kresti;
	this->level = 2;
}
void Cards::initb6() {
	this->card = b6;
	this->point = 0;
	this->view = "6\033[31m\x04\033[0m";
	this->hod = "b6";
	this->mast = bubi;
	this->level = 1;
}
void Cards::initc6() {
	this->card = c6;
	this->point = 0;
	this->view = "6\033[31m\x03\033[0m";
	this->hod = "c6";
	this->mast = cervi;
	this->level = 1;
}
void Cards::initp6() {
	this->card = p6;
	this->point = 0;
	this->view = "6\033[30m\x06\033[0m";
	this->hod = "p6";
	this->mast = piki;
	this->level = 1;
}
void Cards::initk6() {
	this->card = k6;
	this->point = 0;
	this->view = "6\033[30m\x05\033[0m";
	this->hod = "k6";
	this->mast = kresti;
	this->level = 15;
}

void Cards::initukncard() {
	this->card = ukncard;
	this->point = 0;
	this->view = "\x01\x02";
	this->level = -1;
}