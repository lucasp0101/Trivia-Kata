#include "QuestionManager.h"
#include <iostream>


bool QuestionManager::questionWasAnsweredCorrectly()
{
    return rand() % 9 != 7;
}

void QuestionManager::askQuestion(std::string currentPlayerCategory)
{
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