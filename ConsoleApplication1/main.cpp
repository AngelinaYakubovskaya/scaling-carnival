#include <iostream>
#include <string>

#include "Artist.h"
#include "Scientist.h"
#include "Sportsman.h"
#include "Quiz.h"
#include "Team.h"

int main() {
    std::shared_ptr<Artist> artist(new Artist("Jane Smith", Profession::ArtistPro, 25));
    artist->printInfo();

    std::shared_ptr<Scientist> scientist(new Scientist("John Brown", Profession::SientistPro, 30));
    scientist->printInfo();

    std::shared_ptr<Sportsman> sportsman(new Sportsman("John Smith",Profession::SportsmanPro, 21));
    sportsman->printInfo();

    Quiz quiz;
    Team team1("of artists");
    Team team2("of scientists");
    Team team3("of sportsmans");

    team1.addPlayer(artist);
    team2.addPlayer(scientist);
    team3.addPlayer(sportsman);

	quiz.addTeam(team1);
	quiz.addTeam(team2);
	quiz.addTeam(team3);

    quiz.addTask({ Tasktheme::Art });
    quiz.addTask({ Tasktheme::Science });
    quiz.addTask({ Tasktheme::Sport });

	quiz.play();

    return 0;
}




