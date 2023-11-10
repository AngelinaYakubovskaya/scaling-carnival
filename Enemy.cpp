#include "Enemy.hpp"
#include "Position.hpp"

#include <iostream>

namespace my_game
{

Enemy::Enemy(std::string name, size_t id)
    : BaseCharacter(name, id)
{
}

} // namespace my_game