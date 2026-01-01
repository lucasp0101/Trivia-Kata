#include <stdlib.h>
#include <sstream>
#include "Game.h"
#include "GameRunner_ForTesting.h"

static bool notAWinner;

// ! Changed "int main" to "void runMain"
void runMain(int seed)
{
	// srand(time(NULL)); Previous case. Changed for deterministic testing
	srand(seed);
	Game aGame;

	aGame.add("Chet");
	aGame.add("Pat");
	aGame.add("Sue");

	do
	{

		aGame.roll(rand() % 5 + 1);

		if (rand() % 9 == 7)
		{
			notAWinner = aGame.wrongAnswer();
		}
		else
		{
			notAWinner = aGame.wasCorrectlyAnswered();
		}
	} while (notAWinner);

}

std::string wrapperForMain(int seed)
{
	std::stringstream stream;
    auto * old = std::cout.rdbuf(stream.rdbuf());
    
    runMain(seed);

    std::cout.rdbuf(old);

    return stream.str();
}