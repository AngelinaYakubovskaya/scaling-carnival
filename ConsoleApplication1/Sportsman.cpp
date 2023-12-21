#include "Sportsman.h"

Sportsman::Sportsman(std::string sportsmanName, std::string sportsmanProfession, int sportsmanAge) 
	: Player(sportsmanName, sportsmanProfession, sportsmanAge)
{
	tasktheme = Tasktheme::Sport;
}