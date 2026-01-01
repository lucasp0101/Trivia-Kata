#include "Game.h"
#include <iostream>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>

Game::Game() : places{}, purses{}, currentPlayer(0)
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

bool Game::addPlayer(std::string playerName)
{
    players.push_back(playerName);
    places[players.size()] = 0;
    purses[players.size()] = 0;
    inPenaltyBox[players.size()] = false;

    std::cout << playerName << " was added" << std::endl;
    std::cout << "They are player number " << players.size() << std::endl;
    return true;
}

void Game::roll(int roll)
{
    std::cout << players[currentPlayer] << " is the current player" << std::endl;
    std::cout << "They have rolled a " << roll << std::endl;

    if (inPenaltyBox[currentPlayer])
    {
        if (roll % 2 != 0)
        {
            isGettingOutOfPenaltyBox = true;

            std::cout << players[currentPlayer] << " is getting out of the penalty box" << std::endl;

            updateCurrentPlayersPositionAfterRoll(roll);
            
            
            askQuestion();
        }
        else
        {
            std::cout << players[currentPlayer] << " is not getting out of the penalty box" << std::endl;
            isGettingOutOfPenaltyBox = false;
        }
    }
    else
    {

        updateCurrentPlayersPositionAfterRoll(roll);

        
        askQuestion();
    }
}

void Game::updateCurrentPlayersPositionAfterRoll(int roll)
{
    places[currentPlayer] = places[currentPlayer] + roll;
    if (places[currentPlayer] > 11)
        places[currentPlayer] = places[currentPlayer] - 12;

    std::cout << players[currentPlayer] << "'s new location is " << places[currentPlayer] << std::endl;
}

void Game::askQuestion()
{
    std::cout << "The category is " << currentCategory() << std::endl;

    if (currentCategory() == "Pop")
    {
        std::cout << popQuestions.front() << std::endl;
        popQuestions.pop_front();
    }
    if (currentCategory() == "Science")
    {
        std::cout << scienceQuestions.front() << std::endl;
        scienceQuestions.pop_front();
    }
    if (currentCategory() == "Sports")
    {
        std::cout << sportsQuestions.front() << std::endl;
        sportsQuestions.pop_front();
    }
    if (currentCategory() == "Rock")
    {
        std::cout << rockQuestions.front() << std::endl;
        rockQuestions.pop_front();
    }
}

std::string Game::currentCategory()
{
    switch (places[currentPlayer] % 4)
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

bool Game::wasCorrectlyAnswered()
{
    if (inPenaltyBox[currentPlayer] && !isGettingOutOfPenaltyBox)
    {
        advanceCurrentPlayer();
        return true;
    }

    std::cout << "Answer was correct!!!!" << std::endl;
    purses[currentPlayer]++;
    std::cout << players[currentPlayer] << " now has " << purses[currentPlayer] << " Gold Coins." << std::endl;

    bool winner = didPlayerWin();
    advanceCurrentPlayer();

    return winner;
}

void Game::advanceCurrentPlayer()
{
    currentPlayer += 1;
    if (currentPlayer == players.size())
        currentPlayer = 0;
}

bool Game::wrongAnswer()
{
    std::cout << "Question was incorrectly answered" << std::endl;
    std::cout << players[currentPlayer] + " was sent to the penalty box" << std::endl;
    inPenaltyBox[currentPlayer] = true;

    advanceCurrentPlayer();
    return true;
}

bool Game::didPlayerWin()
{
    return !(purses[currentPlayer] == 6);
}

void Game::initGameLoop()
{
    bool notAWinner;
    do
    {

        roll(rand() % 5 + 1);

        if (rand() % 9 == 7)
        {
            notAWinner = wrongAnswer();
        }
        else
        {
            notAWinner = wasCorrectlyAnswered();
        }

    } while (notAWinner);
}