#include "QuestionManager.h"
#include <iostream>

QuestionManager::QuestionManager()
{
    for (std::string category : AVAILABLE_CATEGORIES)
    {
        questionData.push_back({category, 0});
    }
}

bool QuestionManager::questionWasAnsweredCorrectly()
{
    return rand() % 9 != 7;
}

int QuestionManager::getCategoryFromPlayerPlace(int playerPlace)
{
    return playerPlace % questionData.size();
}

void QuestionManager::askQuestion(int playerPlace)
{
    int questionCategoryIndex = getCategoryFromPlayerPlace(playerPlace);
    std::cout << "The category is " << questionData[questionCategoryIndex].categoryName << std::endl;

    std::cout << questionData[questionCategoryIndex].categoryName << " Question " << questionData[questionCategoryIndex].currentQuestionCounter << std::endl;
    questionData[questionCategoryIndex].currentQuestionCounter++;
}