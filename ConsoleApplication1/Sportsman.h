#pragma once
#include "Player.h"

class Sportsman : public Player {

public:
    Sportsman(std::string sportsmanName, Profession profession, int sportsmanAge);
    bool canAnswerOnQuistion(Tasktheme theme);
};