#include "MineFieldGame.hpp"

namespace my_game
{

namespace
{

size_t gWidthGameField = 100;
size_t gHeightGameField = 100;

} // namespace

my_game::MineFieldGame::MineFieldGame()
    : mMineMap(gWidthGameField, std::vector<std::size_t>(gHeightGameField))
{
    for (int i = 0; i < gWidthGameField; ++i)
    {
        for (int j = 0; j < gHeightGameField; ++j)
        {
            int num = rand() % 2;
            Position pos{i, j, 0};
            mMineMap[i][j] = num;
            //std::cout << "x = " << i << "y = " << j << ((num == 1) ? ": Mine" : ": No mine") << std::endl;
        }
    }
}

void MineFieldGame::check(std::shared_ptr<BaseCharacter> character)
{
    if (mMineMap[character->getPosition().x][character->getPosition().y] == 1)
        character->kill();
}

bool MineFieldGame::play()
{
    for (int i = mCharacters.size() - 1; i >= 0; --i)
    {
        auto character = mCharacters[i];
        character->go({Position{rand() % 100, rand() % 100, 0}});

        check(character);
        std::cout << character->name() << (character->isDead() ? " was blown" : " is still alive") << std::endl;
    }

    if (isHeroDead())
    {
        std::cout << "Game over!!!" << std::endl;
        return false;
    }

    mCharacters.erase(std::remove_if(mCharacters.begin(),
                                     mCharacters.end(),
                                     [](const std::shared_ptr<BaseCharacter> & c) { return c->isDead(); }),
                      mCharacters.end());

    return true;
}

} // namespace my_game
