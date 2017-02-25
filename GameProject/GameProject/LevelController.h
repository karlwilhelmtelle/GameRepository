#pragma once
#include "Level.h"
#include "ObjectContainer.h"
#include "Text.h"


class LevelController
{
public:
	LevelController(const sf::VideoMode &resolution);

	Level* getCurrentLevel();

	void setLevelIndex(int index);
private:	
	const sf::VideoMode &resolution;

	int levelIndex;

	Level* currentLevel;
	Level level1;
};