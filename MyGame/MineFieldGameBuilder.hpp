#pragma once

#include "MineFieldGame.hpp"
#include "GameBuilder.hpp"

#include <memory>

namespace my_game
{

class MineFieldGameBuilder : public GameBuilder
{
public:
    ~MineFieldGameBuilder() = default;
    std::unique_ptr<Game> buildGame() override;
};

} // namespace my_game
