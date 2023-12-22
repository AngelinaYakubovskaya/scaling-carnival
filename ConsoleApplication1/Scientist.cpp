#include "Scientist.h"

Scientist::Scientist(std::string scientistName, Profession profession, int scientistAge) :
	Player(scientistName, profession, scientistAge)
{
	tasktheme = Tasktheme::Science;
}

bool Scientist::canAnswerOnQuistion(Tasktheme theme)
{
	if (theme == Tasktheme::Science)
		return true;

	return false;
}