#include "Scientist.h"

Scientist::Scientist(std::string scientistName, std::string scientistProfession, int scientistAge) : 
	Player(scientistName, scientistProfession, scientistAge)
{
	tasktheme = Tasktheme::Science;
}