#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wctor-dtor-privacy"
#include <catch2/catch_all.hpp>
#pragma GCC diagnostic pop
#include "Game.h"
#include "MoreThanMaximumPlayersException.h"

/*
 * I pondered whether to use exceptions of error values to comunicate problems.
 * In the end I decided to use exceptions, because the only reason to not use them
 * is if the risk posed by the program crashing GREATLY outweights the legibility
 * gains, like in the satellite on-board software.
 * 
 * In most systems, that the program forces you to address the bug by crashing
 * is a good thing in the long run. A trivia game is such system. 
 */
TEST_CASE("should_throw_exception_when_adding_more_than_six_players")
{
  Game game;
  game.addPlayer("Alice");
  game.addPlayer("Jack");
  game.addPlayer("Sauron");
  game.addPlayer("Yoda");
  game.addPlayer("David");
  game.addPlayer("Trixie");

  REQUIRE_THROWS_AS(game.addPlayer("Uma"), MoreThanMaximumPlayersException);
}