#pragma once

#include <iostream>
#include <list>
#include <vector>

#define MAX_N_QUESTIONS_PER_CATEGORY 50
#define MAX_QUESTION_LENGTH 127
#define MAX_N_CATECORIES 4
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

    bool playerGetsOutOfPenaltyBox(int diceResult);

    bool questionWasAnsweredCorrectly();

    std::string createRockQuestion(int index);
    void addPlayer(std::string playerName);

    void updateCurrentPlayersPositionAfterRoll(int roll);

    void advanceCurrentPlayer();

  private:
    std::vector<std::string> players;

    int places[MAX_N_PLAYERS];
    int purses[MAX_N_PLAYERS];
    bool inPenaltyBox[MAX_N_PLAYERS];

    std::list<std::string> popQuestions;
    std::list<std::string> scienceQuestions;
    std::list<std::string> sportsQuestions;
    std::list<std::string> rockQuestions;
    
    unsigned int currentPlayerIndex;
    bool isGettingOutOfPenaltyBox;

    void askQuestion();
    std::string currentCategory();
    bool didPlayerWin();
};