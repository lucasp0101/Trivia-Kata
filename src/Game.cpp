#include "Game.h"
#include <iostream>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>

Game::Game() : places{}, purses{}, currentPlayerIndex(0)
{
    for (int i = 0; i < MAX_N_QUESTIONS_PER_CATEGORY; i++)
    {
        popQuestions.push_back(createPopQuestion(i));
        scienceQuestions.push_back(createScienceQuestion(i));
        sportsQuestions.push_back(createSportsQuestion(i));
        rockQuestions.push_back(createRockQuestion(i));
    }
}

std::string Game::createPopQuestion(int index)
{
    char indexStr[MAX_QUESTION_LENGTH];
    sprintf(indexStr, "Pop Question %d", index);
    return indexStr;
}

std::string Game::createScienceQuestion(int index)
{
    char indexStr[MAX_QUESTION_LENGTH];
    sprintf(indexStr, "Science Question %d", index);
    return indexStr;
}

std::string Game::createSportsQuestion(int index)
{
    char indexStr[MAX_QUESTION_LENGTH];
    sprintf(indexStr, "Sports Question %d", index);
    return indexStr;
}

std::string Game::createRockQuestion(int index)
{
    char indexStr[MAX_QUESTION_LENGTH];
    sprintf(indexStr, "Rock Question %d", index);
    return indexStr;
}

void Game::addPlayer(std::string playerName)
{
    players.push_back(playerName);
    places[players.size()] = 0;
    purses[players.size()] = 0;
    inPenaltyBox[players.size()] = false;

    std::cout << playerName << " was added" << std::endl;
    std::cout << "They are player number " << players.size() << std::endl;
}

void Game::updateCurrentPlayersPositionAfterRoll(int roll)
{
    places[currentPlayerIndex] += roll;
    places[currentPlayerIndex] %= 12;

    std::cout << players[currentPlayerIndex] << "'s new location is " << places[currentPlayerIndex] << std::endl;
}

void Game::askQuestion()
{
    std::cout << "The category is " << currentCategory() << std::endl;

    if (currentCategory() == "Pop")
    {
        std::cout << popQuestions.front() << std::endl;
        popQuestions.pop_front();
    }
    else if (currentCategory() == "Science")
    {
        std::cout << scienceQuestions.front() << std::endl;
        scienceQuestions.pop_front();
    }
    else if (currentCategory() == "Sports")
    {
        std::cout << sportsQuestions.front() << std::endl;
        sportsQuestions.pop_front();
    }
    else if (currentCategory() == "Rock")
    {
        std::cout << rockQuestions.front() << std::endl;
        rockQuestions.pop_front();
    }
}

std::string Game::currentCategory()
{
    switch (places[currentPlayerIndex] % MAX_N_CATECORIES)
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

void Game::advanceCurrentPlayer()
{
    currentPlayerIndex++;
    currentPlayerIndex %= players.size();
}

bool Game::didPlayerWin()
{
    return !(purses[currentPlayerIndex] == 6);
}

void Game::initGameLoop()
{
    bool thereIsNoWinner = true;

    while (thereIsNoWinner)
    {
        int diceResult = rollDice();

        if (inPenaltyBox[currentPlayerIndex] && !playerGetsOutOfPenaltyBox(diceResult))
        {
            std::cout << players[currentPlayerIndex] << " is not getting out of the penalty box" << std::endl;
            isGettingOutOfPenaltyBox = false;
        }
        else if (inPenaltyBox[currentPlayerIndex] && playerGetsOutOfPenaltyBox(diceResult))
        {
            std::cout << players[currentPlayerIndex] << " is getting out of the penalty box" << std::endl;
            isGettingOutOfPenaltyBox = true;

            updateCurrentPlayersPositionAfterRoll(diceResult);            
            askQuestion();
        }
        else if (!(inPenaltyBox[currentPlayerIndex]))
        {
            updateCurrentPlayersPositionAfterRoll(diceResult);
            askQuestion();
        }

        if (questionWasAnsweredCorrectly())
        {
            bool playerCanMove = inPenaltyBox[currentPlayerIndex] && !isGettingOutOfPenaltyBox;

            if (!playerCanMove)
            {
                std::cout << "Answer was correct!!!!" << std::endl;
                purses[currentPlayerIndex]++;
                std::cout << players[currentPlayerIndex] << " now has " << purses[currentPlayerIndex] << " Gold Coins." << std::endl;
                
                thereIsNoWinner = didPlayerWin();
            }
        }
        else
        {
            std::cout << "Question was incorrectly answered" << std::endl;
    
            std::cout << players[currentPlayerIndex] + " was sent to the penalty box" << std::endl;
            inPenaltyBox[currentPlayerIndex] = true;
    
        }
        advanceCurrentPlayer();
    }
}

int Game::rollDice()
{
    int diceResult = rand() % 5 + 1;
    std::cout << players[currentPlayerIndex] << " is the current player" << std::endl;
    std::cout << "They have rolled a " << diceResult << std::endl;

    return diceResult;
}

bool Game::playerGetsOutOfPenaltyBox(int diceResult)
{
    return diceResult % 2 != 0;
}

bool Game::questionWasAnsweredCorrectly()
{
    return rand() % 9 != 7;
}
