#include "Team.h"

Team::Team(std::string name) : name(name) {

}

void Team::addPlayer(Player& player) {
	players.push_back(player);
}

std::string Team::getName() {
	return name;
}

void Team::addNumberOfPoints(int numberOfPoints)
{
	this->numberOfPoints += numberOfPoints;
}

bool Team::hasSpecialistByTaskTheme(Tasktheme theme)
{
	for (int i = 0; i < players.size(); ++i)
	{
		if (players[i].getTaskTheme() == theme)
			return true;
	}

	return false;
}

int Team:: getNumberOfPoints() const
{
	return numberOfPoints;
}

