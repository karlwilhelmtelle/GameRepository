#pragma once
#include "MainItem.h"
#include "ObjectContainer.h"
#include "Text.h"

class Level
{
public:
	Level(const sf::VideoMode &resolution);

	void draw(View &window);

	void init();

	void update(bool * game_over);

	void updateElapsedTime();

	void updateHighscore();

	void updateSettings(std::vector < size_t > settings);

	void keyEvent(sf::Keyboard::Key key);

	void restartClock();

	sf::Int32 getLastScore();
	
	sf::Int32 getHighscore();
private:
	const int level_index;

	const sf::VideoMode &resolution;

	float camera_speed;

	MainItem item;

	ObjectContainer map;

	sf::Clock clock;
	Text time_value;
	Text highscore_value;
	Text highscore_text;
	Text time_text;
	sf::Int32 time_milliseconds;
	sf::Int32 highscore_milliseconds;
};