#include <iostream>
#include "../include/BoardADT.h"
#include "../catch/catch.h"

#include <vector>
#include <string>

using namespace std;
const unsigned int MAX_CELL_SIZE = 4;

BoardT:: BoardT(int cellSize) {
      string a;
     //initialize the free Cell as empty
     for(int i = 0; i < cellSize; i++) {
       this->freeRow.push_back(CardT("", ""));
     }

     //cout << this->freeRow[0].suit().empty() << '\n';
     //initialize the foundation Cell as empty
     for(int i = 0; i < cellSize; i++) {
       vector<CardT> temp;
        for(int j = 0; j < 13; j++)
            temp.push_back(CardT("", ""));
        this->foundationRow.push_back(temp);
      }
  }


void BoardT:: dealGameCards() {
  DeckT deck;
  //deck.shuffle();
  for(int i = 0; i < 8; i++) {
    vector<CardT> temp;
    if(i == 0) {
      for(int j = 0; j < 7; j++)
        temp.push_back(deck.returnCard(j));
    }
    if(i == 1) {
      for(int j = 7; j < 14; j++)
        temp.push_back(deck.returnCard(j));
    }
    if(i == 2) {
      for(int j = 14; j < 21; j++)
        temp.push_back(deck.returnCard(j));
    }
    if(i == 3) {
      for(int j = 21; j < 28; j++)
        temp.push_back(deck.returnCard(j));
    }
    if(i == 4) {
      for(int j = 28; j < 34; j++)
        temp.push_back(deck.returnCard(j));
    }
    if(i == 5) {
      for(int j = 34; j < 40; j++)
        temp.push_back(deck.returnCard(j));
    }
    if(i == 6) {
      for(int j = 40; j < 46; j++)
        temp.push_back(deck.returnCard(j));
    }
    if(i == 7) {
      for(int j = 46; j < 52; j++)
        temp.push_back(deck.returnCard(j));
    }
    this->gameColumns.push_back(temp);
  }
}

void BoardT:: displayCards() {
   for(int i = 0; i < this->gameColumns.size(); i++) {
      cout << "Column" << i << ":  ";
    for(int j = 0; j < this->gameColumns[i].size(); j++)
      cout << this->gameColumns[i][j].getCard()<< "   ";
    cout << endl;
  }
}


void BoardT:: displayColumn(int column) {
  for(int j = 0; j < this->gameColumns[column].size(); j++)
    cout<< this->gameColumns[column][j].getCard()<< '\n';
}


int BoardT:: assignIndex(CardT card) {
  if(card.rank().compare("A") == 0)
    return 1;

  for(int i = 2; i <= 10; i++) {
    auto s = to_string(i);

    if(card.rank().compare(s) == 0)
      return i;
  }

  if(card.rank().compare("J") == 0)
    return 11;
  else if(card.rank().compare("Q") == 0)
    return 12;
  else if(card.rank().compare("K") == 0)
    return 13;
  else
    return 0;
}

bool BoardT:: isAscendingToT(int column1, int column2) {
  int lastIndex1 =  this->gameColumns[column1].size();
  int lastIndex2 =  this->gameColumns[column2].size();
  CardT card1 = this->gameColumns[column1][lastIndex1-1];
  CardT card2 = this->gameColumns[column2][lastIndex2-1];

  int a = assignIndex(card1);
  int b = assignIndex(card2);
  if(a+1 == b)
    return true;
  else
    return false;
}

bool BoardT:: isAscendingToF(int column1, int column2) {
  int lastIndex1 =  this->gameColumns[column1].size();
  int lastIndex2 =  this->foundationRow[column2].size();
  CardT card1 = this->gameColumns[column1][lastIndex1-1];
  CardT card2 = this->foundationRow[column2][lastIndex2-1];

  //Initially the cell is empty, and the first card can only be A

  //card1 to be inserted
  int a = assignIndex(card1);
  //card2 that is already in the cell
  int b = assignIndex(card2);
  if(a == b+1)
    return true;
  else
    return false;
}

bool BoardT:: valiFreetoT(int column1, int column2) {
  int lastIndex1 =  this->gameColumns[column2].size();

  CardT card1 = this->freeRow[column1];
  CardT card2 = this->gameColumns[column2][lastIndex1 - 1];
  //a is the card from freeRow, a must be small to be placed at b
  int a = assignIndex(card1);
  //b is the card from the column
  int b = assignIndex(card2);

  bool first_condition = (card1.suit().compare("SPADES") == 0 || card1.suit().compare("CLUBS") == 0)  && (card2.suit().compare("HEARTS") == 0 || card2.suit().compare("DIAMONDS") == 0);
  bool second_condition = (card1.suit().compare("HEARTS") == 0 || card1.suit().compare("DIAMONDS") == 0)  && (card2.suit().compare("SPADES") == 0 || card2.suit().compare("CLUBS") == 0);

  if((a+1 == b) && first_condition ) {
    return true;
  }
  else if((a+1 == b) && second_condition ) {
    return true;
  }
  return false;
}

void BoardT:: moveCardFreetoT(int column1, int column2) {
  if(valiFreetoT(column1, column2)) {
    CardT card = this->freeRow[column1];
    this->gameColumns[column2].push_back(card);
    this->freeRow[column1] = CardT("", "");
  }
}

bool BoardT:: validMove(int column1, int column2) {
  int lastIndex1 =  this->gameColumns[column1].size();
  int lastIndex2 =  this->gameColumns[column2].size();
  CardT card1 = this->gameColumns[column1][lastIndex1-1];
  CardT card2 = this->gameColumns[column2][lastIndex2-1];

  //testing Ascending order as well
  bool value = isAscendingToT(column1, column2);
  bool first_condition = (card1.suit().compare("SPADES") == 0 || card1.suit().compare("CLUBS") == 0)  && (card2.suit().compare("HEARTS") == 0 || card2.suit().compare("DIAMONDS") == 0);
  bool second_condition = (card1.suit().compare("HEARTS") == 0 || card1.suit().compare("DIAMONDS") == 0)  && (card2.suit().compare("SPADES") == 0 || card2.suit().compare("CLUBS") == 0);
  if( value && first_condition)
      return true;
  else if(value && second_condition)
      return true;
  return false;
}

void BoardT:: moveCardTtoT(int column1, int column2) {
  int lastIndex =  this->gameColumns[column1].size();
  CardT card =  this->gameColumns[column1][lastIndex-1];
  if(validMove(column1, column2)) {
  this->gameColumns[column1].pop_back();

  this->gameColumns[column2].push_back(card);
  }
}

bool BoardT:: validMoveTtoFree(int column1, int column2) {
  int lastIndex1 =  this->gameColumns[column1].size();
  CardT card1 = this->gameColumns[column1][lastIndex1-1];

  if(this->freeRow[column2].suit().empty() && this->freeRow[column2].rank().empty()) {
    return true;
  }
  return false;
}

void BoardT:: moveCardTtoFree(int column1, int column2) {
  int lastIndex1 =  this->gameColumns[column1].size();
  CardT card1 = this->gameColumns[column1][lastIndex1-1];

  if(validMoveTtoFree(column1, column2)) {
    this->gameColumns[column1].pop_back();

    this->freeRow[column2] = card1;
  }
}


void BoardT:: displayFreeCell() {
  for(int i = 0; i < this->freeRow.size(); i++) {
     cout << "Free Cell" << i << ":  " << this->freeRow[i].getCard() << '\n';
   }
}

void BoardT:: displayFoundationCell() {
  for(int i = 0; i < this->foundationRow.size(); i++) {
     cout << "Foundation Cell" << i << ":  ";
   for(int j = 0; j < this->foundationRow[i].size(); j++)
     cout << this->foundationRow[i][j].getCard()<< "   ";
   cout << endl;
 }
}

void BoardT:: moveCardTtoFoundation(int column1, int column2) {
  //The first argument represents the column of the game Cell
  //The second argumnent represents the column of the foundationCell
  int lastIndex1 =  this->gameColumns[column1].size();
  CardT card1 = this->gameColumns[column1][lastIndex1-1];

  //this->foundationRow[0] == will take only HEARTS
  if(card1.suit().compare("HEARTS") == 0 && isAscendingToF(column1, column2) ) {
    this->foundationRow[0].push_back(card1);
    this->gameColumns[column1].pop_back();
  }
  //this->foundationRow[1] == will take only DIAMONDS
  else if(card1.suit().compare("DIAMONDS") == 0 && isAscendingToF(column1, column2)) {
    this->foundationRow[1].push_back(card1);
    this->gameColumns[column1].pop_back();
  }
  //this->foundationRow[2] == will take only CLUBS
  else if(card1.suit().compare("CLUBS") == 0 && isAscendingToF(column1, column2)) {
    this->foundationRow[2].push_back(card1);
    this->gameColumns[column1].pop_back();
  }
  //this->foundationRow[3] == will take only SPADES
  else if(card1.suit().compare("SPADES") == 0 && isAscendingToF(column1, column2)) {
    this->foundationRow[3].push_back(card1);
    this->gameColumns[column1].pop_back();
  }
}


bool BoardT:: isGameOver() {
  for(int i = 0; i < this->foundationRow.size(); i++) {
   for(int j = 0; j < this->foundationRow[i].size(); j++)
     if(this->foundationRow[i][j].rank().compare("K") == 0)
       return true;
     }
  return false;
}

// int main(int argc, char const *argv[]) {
//   BoardT board(4);
//   board.dealGameCards();
//   board.displayCards();
//   cout << "*************************" << '\n';
//   board.displayFreeCell();
//   cout << "*************************" << '\n';
//   board.displayFoundationCell();
//   cout << "*************************" << '\n';
//   cout << board.isGameOver() << '\n';
//   board.moveCardTtoFree(1, 0);
//   cout << "*************************" << '\n';
//   board.displayFreeCell();
//   //board.moveCardFreetoT(0, 3);
//   cout << "*************************" << '\n';
//   board.moveCardFreetoT(0, 3);
//   cout << "*************************" << '\n';
//   board.displayCards();
//   cout << "*************************" << '\n';
//   board.displayFreeCell();
//   //board.displayCards();
//   // cout << "*************************" << '\n';
//   // board.moveCardTtoFoundation(5, 0);
//   // board.displayFoundationCell();
//   // cout << "*************************" << '\n';
//   //   board.displayCards();
//   //   cout << "*************************" << '\n';
//   //   board.moveCardTtoFoundation(6, 0);
//   //   board.displayFoundationCell();
//   // // board.displayColumn(2);
//   //  board.moveCardTtoT(5,3);
//   //  cout << "*************************" << '\n';
//   //  board.displayCards();
//   // // // // board.displayColumn(5);
//   // cout << "*************************" << '\n';
//   // //  board.displayColumn(7);
//   // //  cout << "*************************" << '\n';
//   // board.moveCardTtoFree(7,2);
//   // board.displayFreeCell(2);
//
//   return 0;
// }
