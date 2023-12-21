#include "Quiz.h"

	void Quiz::addTeam(Team team) {
		teams.push_back(team);
	}

	void Quiz::addTask(Task task)
	{
		tasks.push_back(task);
	}

	void Quiz::printInfo() {
		for (int i = 0; i < teams.size(); ++i)
		{
			std::cout << "team name = " << teams.at(i).getName() << ";" << std::endl;
		}
	}

	void Quiz::play() {
		for (int i = 0; i < tasks.size(); ++i)
		{
			for (int j = 0; j < teams.size(); ++j)
			{
				if (teams[j].hasSpecialistByTaskTheme(tasks[i].tasktheme))
				{
					teams[j].addNumberOfPoints(1);
				}
			}
		}

		if (teams.empty())
			return;

		int begin = teams[0].getNumberOfPoints();
		bool isDrownGame = true;
		for (int j = 0; j < teams.size(); ++j)
		{
			if (teams[j].getNumberOfPoints() != begin)
				isDrownGame = false;
		}

		if (isDrownGame)
		{
			std::cout << "Drawn game" << std::endl;
			return;
		}

		int max = -1;
		int indexWon = -1;
		for (int j = 0; j < teams.size(); ++j)
		{
			if (teams[j].getNumberOfPoints() > max) {
				indexWon = j;
				max = teams[j].getNumberOfPoints();
			}
		}

		std::cout << "Team " << teams[indexWon].getName() << " won!!!";
	}
