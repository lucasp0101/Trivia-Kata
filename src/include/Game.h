#pragma once

#include <iostream>
#include <list>
#include <vector>

#include "Player.h"
#include "Question.h"

#define MAX_N_QUESTIONS_PER_CATEGORY 50
#define MAX_QUESTION_LENGTH 127
#define WINNING_N_COINS 6
#define MAX_PLACE_PLAYER 12

// * An unlimited players vector and statically-defined sized places/purses... arrays
// * present a contradictary idea for how many players should be allowed to play.
// * Because the fixed size was defined with a magic number, and in a real situation I
// * wouldn't be sure if unlimited players could have other side effects, I chose to keep
// * the maximum number of players.
#define MAX_N_PLAYERS 6

class Game
{
  public:
    Game();

    std::string createPopQuestion(int index);

    std::string createScienceQuestion(int index);

    std::string createSportsQuestion(int index);

    void initGameLoop();

    void increaseCurrentPlayersCoins();

    bool canPlayerAct(int diceResult);

    int rollDice();

    bool doesPlayerGetOutOfPenaltyBox(int diceResult);

    bool questionWasAnsweredCorrectly();

    std::string createRockQuestion(int index);

    void addPlayer(std::string playerName);

    void updateCurrentPlayersPositionAfterRoll(int roll);

    void advanceCurrentPlayer();

  private:
    std::vector<Player> players;

    std::list<std::string> popQuestions;
    std::list<std::string> scienceQuestions;
    std::list<std::string> sportsQuestions;
    std::list<std::string> rockQuestions;

    size_t currentPlayerIndex;

    void askQuestion();

    bool didPlayerWin();
};