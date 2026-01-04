#include "QuestionManager.h"
#include <iostream>


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

    if (currentPlayerCategory == "Pop")
    {
        std::cout << "Pop Question " << popQuestionIndex << std::endl;
        popQuestionIndex++;
    }
    else if (currentPlayerCategory == "Science")
    {
        std::cout << "Science Question " << scienceQuestionIndex << std::endl;
        scienceQuestionIndex++;
    }
    else if (currentPlayerCategory == "Sports")
    {
        std::cout << "Sports Question " << sportsQuestionIndex << std::endl;
        sportsQuestionIndex++;
    }
    else if (currentPlayerCategory == "Rock")
    {
        std::cout << "Rock Question " << rockQuestionIndex << std::endl;
        rockQuestionIndex++;
    }
}