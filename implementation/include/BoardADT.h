#ifndef BOARDT_H
#define BOARDT_H

#include <iostream>
#include "DeckADT.h"
#include <vector>

using namespace std;

/**
* \file BoardADT.h
* \brief This class is the main essential programming for the game BoardADT
* \date April 9,2018
*/
class BoardT {
private:
  vector<vector<CardT> > gameColumns;
  vector<vector<CardT> > foundationRow;
  vector<CardT>  freeRow; //this row is for free Cell
  bool isAscendingToT(int column1, int column2);
  bool isAscendingToF(int column1, int column2);
  bool valiFreetoT(int column1, int column2);
  int assignIndex(CardT card);
  
public:
  /**
  * \param cellSize: The number of cells needed for FreeCell and Foundation Cell
  * \brief The constructor for the BoardT class
  */
  BoardT(int cellSize);

  /**
  * \param None
  * \brief Deals the deck, adding 7 cards into the first four columns
  *        and 6 cards in the last four gameColumns
  * \return None
  */
  void dealGameCards();
  void displayCards();
  /**
  * \param column1, column2
  * \brief Moves the last card from the gamingColumn[column1]
  *         to gamingColumn[column2]
  * \return None
  */
  void moveCardTtoT(int column1, int column2);
  /**
  * \param column1, column2
  * \brief Moves the last card from the gamingColumn[column1]
  *         to FreeCell[column2]
  * \return None
  */
  void moveCardTtoFree(int column1, int column2);
  /**
  * \param column1, column2
  * \brief Moves the card from the FreeCell[column1]
  *         to gamingColumn[column2]
  * \return None
  */
  void moveCardFreetoT(int column1, int column2);
  void displayColumn(int column);
  void displayFreeCell();
  /**
  * \param column1, column2
  * \brief Moves the last card from the gamingColumn[column1]
  *         to foundationRow[column2]
  * \return None
  */
  void moveCardTtoFoundation(int column1, int column2);
  void displayFoundationCell();

  /**
  * \param None
  * \brief Tests if All the cards in the Foundation Cell are from Ace to King
  *        and have the same type of suit
  * \return None
  */
  bool isGameOver();

  //The two functions were supposed to be private, because of Testing had to make
  // them local

  /**
  * \param column1, column2
  * \brief Tests if the card from one column can be moved to other column
  * \return true, false
  */
  bool validMove(int column1, int column2);

  /**
  * \param column1, column2
  * \brief Tests if the card from one column can be moved to the free cell
  * \return true, false
  */
  bool validMoveTtoFree(int column1, int column2);
};

/*
Learned how to convert an int to string
https://stackoverflow.com/questions/5590381/easiest-way-to-convert-int-to-string-in-c
*/

#endif
