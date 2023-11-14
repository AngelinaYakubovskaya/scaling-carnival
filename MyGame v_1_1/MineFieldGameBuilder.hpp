#pragma once

#include "MineFieldGame.hpp"
#include "GameBuilder.hpp"

#include <memory>

namespace my_game
{

/** 
* @brief class MineFieldGameBuilder creates game with mine field.
*/
class MineFieldGameBuilder : public GameBuilder
{
public:
    MineFieldGameBuilder() = default;
    ~MineFieldGameBuilder();
    std::unique_ptr<Game> buildGame() override;
};

} // namespace my_game
