#pragma once
#include "Player.h"

class Scientist : public Player {

public:
    Scientist(std::string scientistName, Profession profession, int scientistAge);
    bool canAnswerOnQuistion(Tasktheme theme) override;

};