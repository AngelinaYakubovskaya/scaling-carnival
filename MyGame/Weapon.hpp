#pragma once

#include "Object.hpp"

namespace my_game
{

/** 
* @brief class Weapon defiles weapon for characters.
*/
class Weapon : public Object
{

private:
    size_t mAmmunition = 0;
};

} // namespace my_game
