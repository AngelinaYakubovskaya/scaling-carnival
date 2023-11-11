#include "Engine.hpp"
#include "MineFieldGameBuilder.hpp"
#include "Position.hpp"

#include <iostream>
#include <vector>

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
    std::vector<std::vector<std::size_t>> mineMap(gWidthGameField, std::vector<std::size_t>(gHeightGameField));
    for (int i = 0; i < gWidthGameField; ++i)
    {
        for (int j = 0; j < gHeightGameField; ++j)
        {
            int num = rand() % 2;
            Position pos{i, j, 0};
            mineMap[i][j] =  num;
            //std::cout << "x = " << i << "y = " << j << ((num == 1) ? ": Mine" : ": No mine") << std::endl;
        }
    }

    while (mIsStarted)
    {
        std::cout << "------------------------ main loop is working ..." << std::endl;
        auto & characters(mGame->characters());

        for (int i = characters.size() - 1; i >= 0; --i)
        {
            auto character = characters[i];
            character->go({Position{rand() % 100, rand() % 100, 0}});
            mDestroyController.check(mineMap, character);
            std::cout << character->name() << (character->isDead() ? " was blown" : " is still alive") << std::endl;
        }

        if (mGame->isHeroDead())
        {
            std::cout << "Game over!!!" << std::endl;
            mIsStarted = false;
        }

        characters.erase(std::remove_if(characters.begin(),
                                        characters.end(),
                                        [](const std::shared_ptr<BaseCharacter> & c) { return c->isDead(); }),
                         characters.end());
    }
}

} // namespace my_game
