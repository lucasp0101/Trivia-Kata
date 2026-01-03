#include "Game.h"
#include <stdlib.h>

//static bool notAWinner;

int main()
{
    // srand(time(NULL)); Previous case. Changed for deterministic testing
    srand(time(NULL));
    Game aGame;

    aGame.addPlayer("Chet");
    aGame.addPlayer("Pat");
    aGame.addPlayer("Sue");

    aGame.initGameLoop();
}