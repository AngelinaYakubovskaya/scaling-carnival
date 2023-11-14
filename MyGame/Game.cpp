#include "Game.hpp"

namespace my_game
{

void Game::addCharacter(const std::shared_ptr<BaseCharacter> character)
{
    mCharacters.push_back(character);
}

std::vector<std::shared_ptr<BaseCharacter>> & Game::characters()
{
    return mCharacters;
}

void Game::addObject(const std::shared_ptr<Object> obj)
{
    mObjects.push_back(obj);
}

std::vector<std::shared_ptr<Object>> Game::objects() const
{
    return mObjects;
}

bool Game::isHeroDead() const
{
    if (mCharacters.empty())
        return true;

    for (const auto & character : mCharacters)
    {
        if (character->isHero() && character->isDead())
        {
            return true;
        }
    }

    return false;
}

} // namespace my_game
