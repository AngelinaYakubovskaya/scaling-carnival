#pragma once

#include "Object.hpp"

namespace my_game
{

class Weapon : public Object
{

private:
    size_t mAmmunition = 0;
};

} // namespace my_game
