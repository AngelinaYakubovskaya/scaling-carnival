#include "Artist.h"

Artist::Artist(std::string artistName, std::string artistProfession, int playerAge) 
	: Player(artistName, artistProfession, playerAge) 
{
	tasktheme = Tasktheme::Art;
}
