#pragma once

#include <iostream>

namespace my_game
{

/** 
* @brief struct Position is position in rectangular coordinate system. 'z' isn't used.
*/
struct Position
{
    int x;
    int y;
    int z;
};

inline std::ostream & operator<<(std::ostream & os, const Position & pos)
{
    os << "{" << pos.x << "," << pos.y << "," << pos.z << "}";
    return os;
}

inline bool operator<(const Position & lhs, const Position & rhs)
{
    return lhs.x < rhs.x && lhs.y < rhs.y;
}

inline bool operator==(const Position & lhs, const Position & rhs)
{
    return lhs.x == rhs.x && lhs.y == rhs.y /*&& lhs.z == rhs.z*/;
}

} // namespace my_game
