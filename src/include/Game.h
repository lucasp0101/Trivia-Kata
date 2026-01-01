#pragma once

#include <iostream>
#include <list>
#include <vector>

#define MAX_N_QUESTIONS_PER_CATEGORY 50
#define MAX_QUESTION_LENGTH 127
class Game
{

  public:
    Game();
    std::string createPopQuestion(int index);
    std::string createScienceQuestion(int index);
    std::string createSportsQuestion(int index);
    void initGameLoop();

    std::string createRockQuestion(int index);
    bool addPlayer(std::string playerName);

    void roll(int roll);

    void updateCurrentPlayersPositionAfterRoll(int roll);

    bool wasCorrectlyAnswered();
    void advanceCurrentPlayer();
    bool wrongAnswer();

  private:
    std::vector<std::string> players;

    int places[6];
    int purses[6];

    bool inPenaltyBox[6];

    std::list<std::string> popQuestions;
    std::list<std::string> scienceQuestions;
    std::list<std::string> sportsQuestions;
    std::list<std::string> rockQuestions;
    
    unsigned int currentPlayer;
    bool isGettingOutOfPenaltyBox;

    void askQuestion();
    std::string currentCategory();
    bool didPlayerWin();
};