#pragma once
#include <string>
#include <list>

#define MAX_N_QUESTIONS_PER_CATEGORY 50
#define MAX_QUESTION_LENGTH 127

class QuestionManager
{
  public:
    QuestionManager();

    bool questionWasAnsweredCorrectly();

    void askQuestion(std::string currentPlayerCategory);

    
  private:
    std::string createPopQuestion(int index);

    std::string createScienceQuestion(int index);

    std::string createSportsQuestion(int index);

    std::string createRockQuestion(int index);

    std::list<std::string> popQuestions;
    std::list<std::string> scienceQuestions;
    std::list<std::string> sportsQuestions;
    std::list<std::string> rockQuestions;
};