#pragma once

#include "Game.hpp"

#include <map>

namespace my_game
{

class MineFieldGame : public Game
{
public:
    ~MineFieldGame() = default;

    void addMineMap(const std::map<Position, bool> & mineMap);

private:

};

} // namespace my_game
