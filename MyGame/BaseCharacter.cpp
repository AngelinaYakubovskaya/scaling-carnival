#include "BaseCharacter.hpp"

namespace my_game
{

BaseCharacter::BaseCharacter(std::string name, size_t id)
    : mName(name)
    , mId(id)
{
}

bool BaseCharacter::go(const Position & pos)
{
    std::cout << name() << " goes to " << pos << std::endl;
    mPosition = pos;
    return true;
}

Position BaseCharacter::getPosition() const
{
    return mPosition;
}

void BaseCharacter::kill()
{
    mIsDead = true;
}

std::string BaseCharacter::name() const
{
    return mName;
}

size_t BaseCharacter::id() const
{
    return mId;
}

} // namespace my_game
