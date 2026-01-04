#include "QuestionManager.h"
#include <iostream>

QuestionManager::QuestionManager()
{
  for (int i = 0; i < MAX_N_QUESTIONS_PER_CATEGORY; i++)
    {
        popQuestions.push_back(createPopQuestion(i));
        scienceQuestions.push_back(createScienceQuestion(i));
        sportsQuestions.push_back(createSportsQuestion(i));
        rockQuestions.push_back(createRockQuestion(i));
    }
}

bool QuestionManager::questionWasAnsweredCorrectly()
{
    return rand() % 9 != 7;
}

void QuestionManager::askQuestion(std::string currentPlayerCategory)
{
    if (currentPlayerCategory == "Pop")
    {
        std::cout << popQuestions.front() << std::endl;
        popQuestions.pop_front();
    }
    else if (currentPlayerCategory == "Science")
    {
        std::cout << scienceQuestions.front() << std::endl;
        scienceQuestions.pop_front();
    }
    else if (currentPlayerCategory == "Sports")
    {
        std::cout << sportsQuestions.front() << std::endl;
        sportsQuestions.pop_front();
    }
    else if (currentPlayerCategory == "Rock")
    {
        std::cout << rockQuestions.front() << std::endl;
        rockQuestions.pop_front();
    }
}

std::string QuestionManager::createPopQuestion(int index)
{
    char indexStr[MAX_QUESTION_LENGTH];
    sprintf(indexStr, "Pop Question %d", index);
    return indexStr;
}

std::string QuestionManager::createScienceQuestion(int index)
{
    char indexStr[MAX_QUESTION_LENGTH];
    sprintf(indexStr, "Science Question %d", index);
    return indexStr;
}

std::string QuestionManager::createSportsQuestion(int index)
{
    char indexStr[MAX_QUESTION_LENGTH];
    sprintf(indexStr, "Sports Question %d", index);
    return indexStr;
}

std::string QuestionManager::createRockQuestion(int index)
{
    char indexStr[MAX_QUESTION_LENGTH];
    sprintf(indexStr, "Rock Question %d", index);
    return indexStr;
}
