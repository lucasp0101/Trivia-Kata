#pragma once

#include <iostream>
#include <list>
#include <vector>

#define MAX_N_QUESTIONS_PER_CATEGORY 50
#define MAX_QUESTION_LENGTH 127
#define MAX_N_CATECORIES 4
#define MAX_PLACE_PLAYER 12 

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

    bool processCorrectAnswer();

    void processIncorrectAnswer();

    int rollDice();

    bool playerGetsOutOfPenaltyBox(int diceResult);

    bool questionWasAnsweredCorrectly();

    std::string createRockQuestion(int index);
    void addPlayer(std::string playerName);

    void updateCurrentPlayersPositionAfterRoll(int roll);

    void advanceCurrentPlayer();

  private:
    std::vector<std::string> players;

    int places[6];
    int purses[6];

    bool inPenaltyBox[6];

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