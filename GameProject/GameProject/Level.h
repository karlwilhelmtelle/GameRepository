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

	void updateSettings(sf::Color mainItemColor, sf::Color objectsColor);

	void keyEvent(sf::Keyboard::Key key);

	void restartClock();

	sf::Int32 getLastScore();
	
	sf::Int32 getHighscore();
private:
	const size_t levelIndex;

	const sf::VideoMode &resolution;

	float cameraSpeed;

	MainItem item;

	ObjectContainer map;

	sf::Clock clock;
	std::vector<Text> textItems;
	sf::Int32 timeMilli;
	sf::Int32 highscoreMilli;
};