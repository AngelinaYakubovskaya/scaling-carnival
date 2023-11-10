#pragma once

#include "Game.hpp"

#include <memory>

namespace my_game
{

class GameBuilder
{
public:
    ~GameBuilder() = default;
    virtual inline std::unique_ptr<Game> buildGame()
    {
        return std::make_unique<Game>();
    }
};

} // namespace my_game