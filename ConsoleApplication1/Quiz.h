#pragma once

#include "Team.h"
#include "Task.h"

#include <vector>

class Quiz {
public:
	void addTeam(Team team);

	void addTask(Task task);

	void printInfo();

	void play();

private:
	std::vector<Team> teams;
	std::vector<Task> tasks;
};