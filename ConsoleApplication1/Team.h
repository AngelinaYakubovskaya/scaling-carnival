#pragma once
#include "Player.h"
#include <vector>

class Team {
public:
	Team(std::string name);
	void addPlayer(Player& player);
	std::string getName();

	void addNumberOfPoints(int numberOfPoints);

	bool hasSpecialistByTaskTheme(Tasktheme theme);
	int getNumberOfPoints() const;

private:
	void printInfo() {}

	std::vector<Player> players;
	std::string name;
	int numberOfPoints = 0;

};
