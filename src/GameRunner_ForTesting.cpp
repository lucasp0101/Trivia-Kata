#include "GameRunner_ForTesting.h"
#include "Game.h"
#include <sstream>
#include <stdlib.h>

static bool notAWinner;

// ! Changed "int main" to "void runMain"
void runMain(int seed)
{
    // srand(time(NULL)); Previous case. Changed for deterministic testing
    srand(seed);
    Game aGame;

    aGame.addPlayer("Chet");
    aGame.addPlayer("Pat");
    aGame.addPlayer("Sue");

    aGame.initGameLoop();
}

std::string wrapperForMain(int seed)
{
    std::stringstream stream;
    auto *old = std::cout.rdbuf(stream.rdbuf());

    runMain(seed);

    std::cout.rdbuf(old);

    return stream.str();
}