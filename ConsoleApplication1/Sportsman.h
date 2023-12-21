#pragma once
#include "Player.h"

class Sportsman : public Player {
private:
    std::string name;
    std::string profession;
    int age;

public:
    Sportsman(std::string sportsmanName, std::string sportsmanProfession, int sportsmanAge);
};