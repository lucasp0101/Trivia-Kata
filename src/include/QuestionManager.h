#pragma once
#include <string>
#include <list>
#include <map>

#define MAX_N_QUESTIONS_PER_CATEGORY 50
#define MAX_QUESTION_LENGTH 127
#define MAX_N_CATEGORIES 4

class QuestionManager
{
  public:
    QuestionManager();

    bool questionWasAnsweredCorrectly();

    std::string currentCategory(int playerPlace);

    void askQuestion(int playerPlace);
    
  private:
    std::map<std::string, unsigned int> questionCategoryCounters;
};