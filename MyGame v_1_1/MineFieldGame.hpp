#pragma once

#include "Game.hpp"

#include <map>
#include <vector>

namespace my_game
{

using MineMap = std::vector<std::vector<std::size_t>>;

/** 
* @brief class MineFieldGame defines game where charecters can be blown.
*/
class MineFieldGame : public Game
{
public:
    MineFieldGame();
    ~MineFieldGame() = default;
    bool play() override;

private:
    void check(std::shared_ptr<BaseCharacter> character);

private:
    MineMap mMineMap;
};

} // namespace my_game
