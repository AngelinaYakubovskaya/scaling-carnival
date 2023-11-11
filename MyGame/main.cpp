#include "Engine.hpp"

#include <iostream>

int main()
{
    srand(time(0));
    my_game::Engine engine;
    engine.start();
    engine.loop();

    return 0;
}

