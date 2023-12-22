#pragma once
#include "Player.h"
#include <vector>

class Team {
public:
	Team(std::string name);
	void addPlayer(std::shared_ptr<Player> player);
	std::string getName();

	void addNumberOfPoints(int numberOfPoints);
	void tryAnswer(Tasktheme theme);
	bool canAnswerOnQuistion(Tasktheme theme);
	int getNumberOfPoints() const;

private:
	void printInfo() {}

	std::vector<std::shared_ptr<Player>> players;
	std::string name;
	int numberOfPoints = 0;

};
