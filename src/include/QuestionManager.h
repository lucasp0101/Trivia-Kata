#pragma once
#include <string>
#include <list>

#define MAX_N_QUESTIONS_PER_CATEGORY 50
#define MAX_QUESTION_LENGTH 127

class QuestionManager
{
  public:
    QuestionManager() : popQuestionIndex(0), scienceQuestionIndex(0), sportsQuestionIndex(0), rockQuestionIndex(0)
    {
    }

    bool questionWasAnsweredCorrectly();

    void askQuestion(std::string currentPlayerCategory);
    
  private:
    unsigned int popQuestionIndex;
    unsigned int scienceQuestionIndex;
    unsigned int sportsQuestionIndex;
    unsigned int rockQuestionIndex;
};