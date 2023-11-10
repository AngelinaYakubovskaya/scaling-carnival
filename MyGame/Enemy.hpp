#pragma once

#include "BaseCharacter.hpp"

namespace my_game
{

class Position;

class Enemy : public BaseCharacter
{
public:
    explicit Enemy(std::string name, size_t id);
    ~Enemy() = default;
};

} // namespace my_game