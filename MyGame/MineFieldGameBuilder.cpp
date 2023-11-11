#include "MineFieldGameBuilder.hpp"
#include "Hero.hpp"
#include "Enemy.hpp"
#include "Mine.hpp"

namespace my_game
{

std::unique_ptr<Game> MineFieldGameBuilder::buildGame()
{
    auto game = std::make_unique<MineFieldGame>();

    auto hero = std::make_shared<Hero>("hero", 1);
    game->addCharacter(hero);

    auto enemy = std::make_shared<Enemy>("enemy1", 2);
    game->addCharacter(enemy);
    auto enemy2 = std::make_shared<Enemy>("enemy2", 3);
    game->addCharacter(enemy2);

    return game;
}

} // namespace my_game
