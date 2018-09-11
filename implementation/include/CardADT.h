#ifndef CARD_H
#define CARD_H

#include <iostream>
#include <string>

using namespace std;
class CardT {

private:
	string r;
	string s;

public:
	/**
  * \param rank, suit
  * \brief Constructor for the class CardT, takes two input string and Constructor
	*				 a Card from the deck of cards
  * \return self
  */
	CardT(string rank, string suit);
	/**
  * \param None
  * \brief
  * \return returns the ranks of the card
  */
	string rank();

	/**
  * \param None
  * \brief
  * \return returns the suit of the card
  */
	string suit();

	/**
  * \param None
  * \brief
  * \return returns the ranks + suit of the card, making it easy for the user
  */
	string getCard();

};

#endif
