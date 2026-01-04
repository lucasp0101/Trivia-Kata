#pragma once
#include <string>
#include <list>

#define MAX_N_QUESTIONS_PER_CATEGORY 50
#define MAX_QUESTION_LENGTH 127
#define MAX_N_CATEGORIES 4

class QuestionManager
{
  public:
    QuestionManager() : popQuestionIndex(0), scienceQuestionIndex(0), sportsQuestionIndex(0), rockQuestionIndex(0)
    {
    }

    bool questionWasAnsweredCorrectly();

    std::string currentCategory(int playerPlace);

    void askQuestion(int playerPlace);
    
  private:
    unsigned int popQuestionIndex;
    unsigned int scienceQuestionIndex;
    unsigned int sportsQuestionIndex;
    unsigned int rockQuestionIndex;
};