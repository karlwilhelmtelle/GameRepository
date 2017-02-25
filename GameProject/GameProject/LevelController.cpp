#include "LevelController.h"

LevelController::LevelController(const sf::VideoMode &res) :
	resolution(res),
	level1(res),
	currentLevel(&level1),
	levelIndex(0)
{
	level1.init();
}

void LevelController::setLevelIndex(const int index)
{
	if (levelIndex != index)
	{
		levelIndex = index;
		switch (levelIndex)
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

Level * LevelController::getCurrentLevel() const
{
	return currentLevel;
}