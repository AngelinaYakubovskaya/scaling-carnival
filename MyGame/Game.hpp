#pragma once

#include "BaseCharacter.hpp"
#include "Object.hpp"

#include <vector>
#include <memory>

namespace my_game
{

class Game
{
public:
    ~Game() = default;
    void addCharacter(const std::shared_ptr<BaseCharacter> character);
    std::vector<std::shared_ptr<BaseCharacter>> & characters();

    void addObject(const std::shared_ptr<Object> obj);
    std::vector<std::shared_ptr<Object>> objects() const;

    inline bool isHeroDead()
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



protected:
    std::vector<std::shared_ptr<BaseCharacter>> mCharacters;
    std::vector<std::shared_ptr<Object>> mObjects;
};

} // namespace my_game
