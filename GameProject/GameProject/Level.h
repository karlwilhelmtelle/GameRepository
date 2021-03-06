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

		void updateSettings(const sf::Color mainItemColor, const sf::Color objectsColor);

		void setLevelIndex(const size_t levelIndex);

		size_t getLevelIndex() const;

		void keyEvent(const sf::Keyboard::Key key);

		void restartClock();

		sf::Int32 getLastScore() const;
	
		sf::Int32 getHighscore() const;
	private:
		size_t levelIndex;

		const sf::VideoMode &resolution;

		float cameraSpeed;

		MainItem item;

		ObjectContainer map;

		sf::Clock clock;
		std::vector<Text> textItems;
		sf::Int32 timeMilli;
		sf::Int32 highscoreMilli;
};