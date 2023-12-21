#pragma once
#include "Player.h"

class Scientist : public Player {
private:
    std::string name;
    std::string profession;
    int age;

public:
    Scientist(std::string scientistName, std::string scientistProfession, int scientistAge);
};