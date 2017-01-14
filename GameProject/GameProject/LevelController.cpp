#include "LevelController.h"

LevelController::LevelController(sf::VideoMode &res) :
	resolution(res),
	level1(res),
	currentLevel(&level1),
	level_index(0)
{
	level1.init();
}

void LevelController::setLevelIndex(int index)
{
	if (level_index != index)
	{
		level_index = index;
		switch (level_index)
		{
		case 0:
			currentLevel = &level1;
			break;
		default:
			break;
		}
	}
	currentLevel->init();
}

Level * LevelController::getCurrentLevel()
{
	return currentLevel;
}