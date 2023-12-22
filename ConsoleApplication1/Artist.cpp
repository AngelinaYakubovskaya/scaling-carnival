#include "Artist.h"

Artist::Artist(std::string artistName, Profession profession, int playerAge)
	: Player(artistName, profession, playerAge) 
{
	tasktheme = Tasktheme::Art;
}

bool Artist::canAnswerOnQuistion(Tasktheme theme)
{
	if (theme == Tasktheme::Art)
		return true;

	return false;
}
