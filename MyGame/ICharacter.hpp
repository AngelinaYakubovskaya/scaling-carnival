#pragma once

namespace my_game
{

class Position;

/** 
* @brief class ICharacter is interface for characters classes.
*/
class ICharacter
{
public:
    ~ICharacter() = default;
    virtual bool go(const Position & pos) = 0;
};

} // namespace my_game
