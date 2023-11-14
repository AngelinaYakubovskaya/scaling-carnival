#pragma once

#include "Game.hpp"

#include <memory>

namespace my_game
{

/** 
* @brief class GameBuilder is base builder class. There is added characters, objects to game.
*/
class GameBuilder
{
public:
    ~GameBuilder() = default;
    virtual std::unique_ptr<Game> buildGame();
};

} // namespace my_game
