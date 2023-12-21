#pragma once

#include "consts.h"

class Task {
public:
	Task(Tasktheme tasktheme) :
		tasktheme(tasktheme)
	{}

private:
	enum Tasktheme tasktheme;
};
