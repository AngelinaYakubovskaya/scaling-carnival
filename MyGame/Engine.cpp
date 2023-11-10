#include "Engine.hpp"
#include "MineFieldGameBuilder.hpp"
#include "Position.hpp"

#include <iostream>

namespace my_game
{

namespace
{

size_t gWidthGameField = 100;
size_t gHeightGameField = 100;

} // namespace

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
    std::map<Position, bool> mineMap;
    std::cout << "minemap";
    for (int i = 0; i < gWidthGameField; ++i)
    {
        for (int j = 0; j < gHeightGameField; ++j)
        {
            int num = rand() % 2;
            Position pos{i, j, 0};
            mineMap.insert_or_assign(pos, (bool)num);
            std::cout << "Position = " << pos << (((bool)num) ? "Mine" : " No mine") << std::endl;
            
        }
    }

    while (mIsStarted)
    {
        std::cout << "------------------------ main loop is working ..." << std::endl;
        auto & characters(mGame->characters());
        for (int it = characters.size() - 1; it >= 0; --it)
        {
            auto character = characters[it];
            character->go({Position{rand() % 100, rand() % 100, 0}});

            mDestroyController.check(mineMap, character);

            if (character->isDead())
            {
                std::cout << character->name() << " was killed" << std::endl;
                characters.erase(characters.begin() + it);

            }
        }

        if (characters.size() == 0)
            mIsStarted = false;
    }
}

} // namespace my_game
