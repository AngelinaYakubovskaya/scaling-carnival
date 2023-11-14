#pragma once

#include "Game.hpp"

#include <memory>

namespace my_game
{

/** 
* @brief class Engine contains game's main loop.
*/
class Engine
{
public:
    ~Engine() = default;
    void start();
    void stop();
    void loop();

private:
    bool mIsStarted;
    std::unique_ptr<Game> mGame;
};

} // namespace my_game
