#include "Player.h"
#include <iostream>

void Player::increaseCoinsBy(int quantity){
    this->purse += quantity;
    std::cout << this->name << " now has " << this->purse << " Gold Coins." << std::endl;
}
