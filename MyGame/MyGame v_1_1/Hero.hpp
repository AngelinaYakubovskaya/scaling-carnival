#pragma once

#include "BaseCharacter.hpp"

namespace my_game
{

/** 
* @brief class Hero defines main game's character.
*/
class Hero : public BaseCharacter
{
public:
    Hero(std::string name, size_t id);
    ~Hero() = default;
};

} // namespace my_game
