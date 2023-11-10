#pragma once

#include "Game.hpp"
#include "DestroyController.hpp"

#include <memory>

namespace my_game
{

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
    DestroyController mDestroyController;
};

} // namespace my_game
