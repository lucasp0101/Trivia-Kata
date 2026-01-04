#pragma once

#include <iostream>
#include <list>
#include <vector>

#include "Player.h"
#include "QuestionManager.h"

#define WINNING_N_COINS 6
#define MAX_PLACE_PLAYER 12
#define REWARD_FOR_CORRECT_ANSWER 1

// * An unlimited players vector and statically-defined sized places/purses... arrays
// * present a contradictary idea for how many players should be allowed to play.
// * Because the fixed size was defined with a magic number, and in a real situation I
// * wouldn't be sure if unlimited players could have other side effects, I chose to keep
// * the maximum number of players.
#define MAX_N_PLAYERS 6

class Game
{
  public:
    Game() : currentPlayerIndex(0)
    {
    }

    void initGameLoop();

    int rollDice();

    bool doesPlayerGetOutOfPenaltyBox(int diceResult);

    void addPlayer(std::string playerName);

    void updateCurrentPlayersPositionAfterRoll(int roll);

    void advanceCurrentPlayer();

  private:
    std::vector<Player> players;

    QuestionManager questionManager;

    size_t currentPlayerIndex;

    bool didPlayerWin();
};