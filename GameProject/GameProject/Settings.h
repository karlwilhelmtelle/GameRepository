#pragma once
#include <SFML/Graphics.hpp>

class Settings
{
public:
	Settings();
	void update(std::vector<size_t> settings);
	sf::Color getMainItemColor();
	sf::Color getObjectsColor();
	bool audioEnabled();
private:
	sf::Color mainItemColor;
	sf::Color objectsColor;
	bool isAudioEnabled;
};