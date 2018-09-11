#include <iostream>
#include "catch.h"
#include "BoardADT.h"

using namespace std;

TEST_CASE("test for Free Cell solitaire", "[BoardT]") {

  //Initializing the CardTypes
  BoardT board(4);
  board.dealGameCards();
  SECTION("Invalid move between Columns") {
    REQUIRE_FALSE(board.validMove(3,0));
    REQUIRE_FALSE(board.validMove(7,1));
  }

  SECTION("Moving to the free cell, when one is avaialble") {
    board.moveCardTtoFree(3,0);
    board.moveCardTtoFree(4,1);
    board.moveCardTtoFree(2,2);

    //The third index is free, we will test over there
    REQUIRE(board.validMoveTtoFree(7,3));
    REQUIRE_FALSE(board.validMoveTtoFree(1,2));
  }

  SECTION("Moving to the free cell, when one is avaialble") {
    board.moveCardTtoFree(3,0);
    board.moveCardTtoFree(4,1);
    board.moveCardTtoFree(2,2);
    board.moveCardTtoFree(7,3);

    REQUIRE_FALSE(board.validMoveTtoFree(3,0));
    REQUIRE_FALSE(board.validMoveTtoFree(7,1));
  }

  SECTION("DETECTING WINNING GAME OVER") {
    board.moveCardTtoFoundation(3,1);
    REQUIRE_FALSE(board.isGameOver());
  }
}
