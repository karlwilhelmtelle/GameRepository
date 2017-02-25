#pragma once
#include <SFML/Graphics.hpp>

class Settings
{
public:
	Settings();

	void update(std::vector<size_t> settings);

	std::vector<size_t> getSettings();

	sf::Color getMainItemColor();

	sf::Color getObjectsColor();

	bool audioEnabled();
private:
	std::vector <size_t> settings;
	sf::Color mainItemColor;
	sf::Color objectsColor;
	bool isAudioEnabled;
};