#pragma once
#include <string>
#include <list>
#include <vector>

#define MAX_N_QUESTIONS_PER_CATEGORY 50
#define MAX_QUESTION_LENGTH 127
#define MAX_N_CATEGORIES 4

const std::string AVAILABLE_CATEGORIES[] = {"Pop", "Science", "Sports", "Rock"};

struct QuestionCategoryGameInfo
{
  std::string categoryName;
  unsigned int currentQuestionCounter;
};

class QuestionManager
{
  public:
    QuestionManager();

    bool questionWasAnsweredCorrectly();
    
    void askQuestion(int playerPlace);
    
  private:
    std::vector<QuestionCategoryGameInfo> questionData;

    int getCategoryFromPlayerPlace(int playerPlace);
};