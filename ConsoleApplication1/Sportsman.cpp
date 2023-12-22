#include "Sportsman.h"
#include "consts.h"

Sportsman::Sportsman(std::string sportsmanName, Profession profession, int sportsmanAge)
	: Player(sportsmanName, profession, sportsmanAge)
{
	tasktheme = Tasktheme::Sport;
}

bool Sportsman::canAnswerOnQuistion(Tasktheme theme)
{
	if (theme == Tasktheme::Sport)
		return true;

	return false;
}
