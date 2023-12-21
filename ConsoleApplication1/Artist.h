#pragma once

#include "Player.h"

class Artist : public Player {
private:
    std::string name;
    std::string profession;
    int age;

public:
    Artist(std::string artistName, std::string artistProfession, int artistAge);
};