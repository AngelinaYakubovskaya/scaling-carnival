#pragma once

#include "Game.hpp"

#include <memory>

namespace my_game
{

class GameBuilder
{
public:
    ~GameBuilder() = default;
    virtual std::unique_ptr<Game> buildGame();
};

} // namespace my_game