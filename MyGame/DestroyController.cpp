#include "DestroyController.hpp"

#include <memory>

namespace my_game
{

void DestroyController::check(const std::vector<std::vector<std::size_t>> & mineMap,
                              std::shared_ptr<BaseCharacter> character)
{
    if (mineMap[character->getPosition().x][character->getPosition().y] == 1)
        character->kill();
}

} // namespace my_game
