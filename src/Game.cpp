#include "Game.h"
#include "MoreThanMaximumPlayersException.h"
#include <iostream>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>

Game::Game() : currentPlayerIndex(0)
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
    if (players.size() >= MAX_N_PLAYERS)
        throw MoreThanMaximumPlayersException("There was an attempt to add more than six players to a Game instance");

    players.push_back(Player(playerName));

    std::cout << playerName << " was added" << std::endl;
    std::cout << "They are player number " << players.size() << std::endl;
}

void Game::updateCurrentPlayersPositionAfterRoll(int roll)
{
    int new_position = (players[currentPlayerIndex].getPlace() + roll) % MAX_PLACE_PLAYER;
    players[currentPlayerIndex].setPlace(new_position);

    std::cout << players[currentPlayerIndex].getName() << "'s new location is "
              << players[currentPlayerIndex].getPlace() << std::endl;
}

void Game::askQuestion()
{
    std::string currentPlayerCategory = players[currentPlayerIndex].currentCategory();

    std::cout << "The category is " << currentPlayerCategory << std::endl;

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

void Game::advanceCurrentPlayer()
{
    currentPlayerIndex++;
    currentPlayerIndex %= players.size();
}

bool Game::didPlayerWin()
{
    return players[currentPlayerIndex].getPurse() == WINNING_N_COINS;
}

void Game::initGameLoop()
{
    bool thereIsWinner = false;

    while (!thereIsWinner)
    {
        std::cout << players[currentPlayerIndex].getName() << " is the current player" << std::endl;
        
        int diceResult = rollDice();

        bool playerCanAct = true;
        if (players[currentPlayerIndex].getInPenalty())
        {
            playerCanAct =  doesPlayerGetOutOfPenaltyBox(diceResult);
        }

        if (playerCanAct)
        {
            updateCurrentPlayersPositionAfterRoll(diceResult);
            askQuestion();
        }

        if (questionWasAnsweredCorrectly())
        {
            if (playerCanAct)
            {
                std::cout << "Answer was correct!!!!" << std::endl;
                players[currentPlayerIndex].increaseCoinsBy(REWARD_FOR_CORRECT_ANSWER);

                thereIsWinner = didPlayerWin();
            }
        }
        else
        {
            std::cout << "Question was incorrectly answered" << std::endl;

            std::cout << players[currentPlayerIndex].getName() + " was sent to the penalty box" << std::endl;
            players[currentPlayerIndex].setInPenalty(true);
        }
        
        advanceCurrentPlayer();
    }
}

int Game::rollDice()
{
    int diceResult = rand() % 5 + 1;
    std::cout << "They have rolled a " << diceResult << std::endl;

    return diceResult;
}

bool Game::doesPlayerGetOutOfPenaltyBox(int diceResult)
{
    if (diceResult % 2 != 0)
    {
        std::cout << players[currentPlayerIndex].getName() << " is getting out of the penalty box" << std::endl;
        return true;
    }
    else
    {
        std::cout << players[currentPlayerIndex].getName() << " is not getting out of the penalty box" << std::endl;
        return false;
    }
}

bool Game::questionWasAnsweredCorrectly()
{
    return rand() % 9 != 7;
}
