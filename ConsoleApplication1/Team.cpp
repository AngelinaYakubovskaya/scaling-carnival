#include "Team.h"

Team::Team(std::string name) : name(name) {

}

void Team::addPlayer(std::shared_ptr<Player> player) {
	players.push_back(player);
}

std::string Team::getName() {
	return name;
}

void Team::addNumberOfPoints(int numberOfPoints)
{
	this->numberOfPoints += numberOfPoints;
}

void Team::tryAnswer(Tasktheme theme)
{
	if (canAnswerOnQuistion(theme))
	{
		addNumberOfPoints(1);
	}
}

bool Team::canAnswerOnQuistion(Tasktheme theme)
{
	for (int i = 0; i < players.size(); ++i)
	{
		if (players[i]->canAnswerOnQuistion(theme))
			return true;
	}

	return false;
}

int Team:: getNumberOfPoints() const
{
	return numberOfPoints;
}

