#include "Engine.hpp"

#include <iostream>

int main()
{
    my_game::Engine engine;
    engine.start();
    engine.loop();

    return 0;
}

