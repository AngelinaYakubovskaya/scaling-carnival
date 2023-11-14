#include "Engine.hpp"
#include "MineFieldGameBuilder.hpp"
#include "Position.hpp"

#include <iostream>
#include <vector>

namespace my_game
{

void Engine::start()
{
    mIsStarted = true;
    MineFieldGameBuilder builder;
    mGame = builder.buildGame();
}

void Engine::stop()
{
    mIsStarted = false;
}

void Engine::loop()
{
    while (mIsStarted)
    {
        std::cout << " --- main loop is working --- " << std::endl;
        if (!mGame->play())
        {
            mIsStarted = false;
            return;
        }
    }
}

} // namespace my_game
