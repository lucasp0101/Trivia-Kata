#include "Player.h"
#include "Question.h"

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