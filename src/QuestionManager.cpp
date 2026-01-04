#include "QuestionManager.h"
#include <iostream>

QuestionManager::QuestionManager()
{
    questionCategoryCounters = 
    {
        {"Pop", 0},
        {"Science", 0},
        {"Sports", 0},
        {"Rock", 0}
    };
}

bool QuestionManager::questionWasAnsweredCorrectly()
{
    return rand() % 9 != 7;
}

std::string QuestionManager::currentCategory(int playerPlace)
{
    switch (playerPlace % MAX_N_CATEGORIES)
    {
    case 0:
        return "Pop";
        break;
    case 1:
        return "Science";
        break;
    case 2:
        return "Sports";
        break;
    default:
        return "Rock";
    }
}

void QuestionManager::askQuestion(int playerPlace)
{
    std::string currentPlayerCategory = currentCategory(playerPlace);
    std::cout << "The category is " << currentPlayerCategory << std::endl;

    std::cout << currentPlayerCategory << " Question " << this->questionCategoryCounters.at(currentPlayerCategory) << std::endl;
    this->questionCategoryCounters.at(currentPlayerCategory)++;
}