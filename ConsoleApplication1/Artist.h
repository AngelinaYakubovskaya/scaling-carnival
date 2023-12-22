#pragma once

#include "Player.h"

class Artist : public Player {

public:
    Artist(std::string artistName, Profession profession, int artistAge);
    bool canAnswerOnQuistion(Tasktheme theme);
};