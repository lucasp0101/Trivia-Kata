#include "Player.h"
#include "Question.h"
#include <iostream>

std::string Player::currentCategory()
{
    switch (place % MAX_N_CATECORIES)
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

void Player::increaseCoinsBy(int quantity){
    this->purse += quantity;
    std::cout << this->name << " now has " << this->purse << " Gold Coins." << std::endl;
}
