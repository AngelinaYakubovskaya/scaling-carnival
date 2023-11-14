#pragma once

#include "ICharacter.hpp"
#include "Position.hpp"

#include <string>

namespace my_game
{

/** 
* @brief class BaseCharacter is base class that defines character.
*/
class BaseCharacter : public ICharacter
{
public:
    BaseCharacter(std::string name, size_t id);
    ~BaseCharacter() = default;
    bool go(const Position & pos) override;
    Position getPosition() const;
    void kill();
    inline bool isDead() const
    {
        return mIsDead;
    }

    inline bool isHero() const
    {
        return mIsHero;
    }

    inline void setHero()
    {
        mIsHero = true;
    }

    std::string name() const;


protected:

    size_t id() const;

private:
    std::string mName;
    size_t mId;
    Position mPosition;
    bool mIsDead = false;
    bool mIsHero = false;
};

} // namespace my_game
