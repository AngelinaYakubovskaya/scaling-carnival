#include "Hero.hpp"
#include "Position.hpp"

#include <iostream>

namespace my_game
{

Hero::Hero(std::string name, size_t id)
    : BaseCharacter(name, id)
{
    setHero();
}

} // namespace my_game
