#include <iostream>
#include "../include/CardADT.h"
#include "../catch/catch.h"
using namespace std;

CardT:: CardT(string rank, string suit) {
		this -> r = rank;
		this -> s = suit;
}

string CardT:: rank() {
		return this-> r;
}

string CardT:: suit() {
		return this-> s;
}

string CardT:: getCard() {
		return rank() + " " + suit();
}

// int main(int argc, char const *argv[]) {
// 	CardT card("K", "SPADES");
// 	std::cout << "\ncard:  " << card.getCard() << "\n";
// 	return 0;
// }
