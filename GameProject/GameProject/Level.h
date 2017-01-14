#pragma once
#include "MainItem.h"
#include "ObjectContainer.h"
#include "Text.h"

class Level
{
public:
	Level(sf::VideoMode &resolution);

	void draw(Window &window);

	void init();

	void update(bool * game_over);

	void updateElapsedTime();
	void updateHighscore();

	void keyEvent(sf::Keyboard::Key key);

	void restartClock();
private:
	const int level_index;

	sf::VideoMode &resolution;

	float camera_speed;

	MainItem item;

	ObjectContainer map;

	sf::Clock clock;
	Text time_text;
	Text highscore_text;
	sf::Int32 time_milliseconds;
	sf::Int32 highscore_milliseconds;
};