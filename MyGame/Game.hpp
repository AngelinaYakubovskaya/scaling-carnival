#pragma once

#include "BaseCharacter.hpp"
#include "Object.hpp"

#include <vector>
#include <memory>

namespace my_game
{

/** 
* @brief class Game is base class game.
*/
class Game
{
public:
    ~Game() = default;
    void addCharacter(const std::shared_ptr<BaseCharacter> character);
    std::vector<std::shared_ptr<BaseCharacter>> & characters();
    void addObject(const std::shared_ptr<Object> obj);
    std::vector<std::shared_ptr<Object>> objects() const;
    bool isHeroDead() const;
    virtual bool play() = 0;
 
protected:
    std::vector<std::shared_ptr<BaseCharacter>> mCharacters;
    std::vector<std::shared_ptr<Object>> mObjects;
};

} // namespace my_game
