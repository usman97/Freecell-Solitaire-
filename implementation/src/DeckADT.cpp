#include <iostream>
#include "../include/DeckADT.h"
#include "../catch/catch.h"

#include <cstdlib>
using namespace std;

int MAX_CARDS = 52;

DeckT:: DeckT() {
    string ranks[] = {"A","2","3","4","5","6","7","8","9","10","J","Q","K"};
    string suits[] = {"SPADES", "DIAMONDS", "CLUBS", "HEARTS"};

    for(int i = 0; i < MAX_CARDS; i++){
      this->deck.push_back(CardT(ranks[i %13], suits[i/13]));
    }
}

void DeckT:: shuffle() {
  for(int i = 0; i < MAX_CARDS; i++) {
    int j = (rand() + time(0)) % MAX_CARDS;
    CardT temp = this->deck[i];
    this->deck[i] = this->deck[j];
    this->deck[j] = temp;
  }
}

string DeckT:: get(int i) {
    return this->deck[i].getCard();
}

CardT DeckT:: returnCard(int i) {
    return this->deck[i];
}
