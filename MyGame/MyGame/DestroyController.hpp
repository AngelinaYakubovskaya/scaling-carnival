#pragma once

#include "Position.hpp"
#include "BaseCharacter.hpp"

#include <memory>
#include <vector>
#include <map>

namespace my_game
{

class DestroyController
{
public:
    void check(const std::map<Position, bool> & mineMap, std::shared_ptr<BaseCharacter> character);
};

} // namespace my_game
