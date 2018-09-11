#ifndef DECK_H
#define DECK_H

#include <iostream>
#include "CardADT.h"
#include <string>
#include <vector>

using namespace std;

class DeckT {
private:
  vector<CardT> deck;

  vector<vector<CardT> > gameColumns;

public:
  /**
  * \param None
  * \brief Constructor for the class DeckT, creates a list of cards
  * \return self
  */
  DeckT();

  /**
  * \param None
  * \brief Takes in the deck of cards and shuffle it so the user will have a
  *        new set of cards every time the game starts
  */
  void shuffle();

  /**
  * \param i
  * \return displays the string representation at the ith index
  */
  string get(int i);

  /**
  * \param i
  * \return the card at the ith index in the deck array
  */
  CardT returnCard(int i);
};


/*

Using random for shuffle was implemened from this website:
 http://www.cplusplus.com/forum/general/163824/

 How to initialize vector to vector was learned from:
 https://www.youtube.com/watch?v=h5S1h8PWCm8
*/
#endif
