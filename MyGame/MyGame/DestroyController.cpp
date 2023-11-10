#include "DestroyController.hpp"

#include <memory>

namespace my_game
{

void DestroyController::check(const std::map<Position, bool> & mineMap, std::shared_ptr<BaseCharacter> character)
{
    auto foundPos = mineMap.find(character->getPosition());
    if (foundPos != mineMap.end())
    {
        if (foundPos->second)
            character->kill();
    }
}

} // namespace my_game
