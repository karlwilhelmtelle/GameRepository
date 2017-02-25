#include "Settings.h"

Settings::Settings() :
	settings({2, 6, 1})
{
	update(settings);
}

void Settings::update(std::vector<size_t> settings)
{
	switch (settings[0])
	{
		case 1:
			mainItemColor = sf::Color::Blue;
			break;
		case 2:
			mainItemColor = sf::Color::Cyan;
			break;
		case 3:
			mainItemColor = sf::Color::Green;
			break;
		case 4:
			mainItemColor = sf::Color::Yellow;
			break;
		case 5:
			mainItemColor = sf::Color::White;
			break;
		case 6:
			mainItemColor = sf::Color::Red;
			break;
		case 7:
			mainItemColor = sf::Color::Magenta;
			break;
	}

	switch (settings[1])
	{
		case 1:
			objectsColor = sf::Color::Blue;
			break;
		case 2:
			objectsColor = sf::Color::Cyan;
			break;
		case 3:
			objectsColor = sf::Color::Green;
			break;
		case 4:
			objectsColor = sf::Color::Yellow;
			break;
		case 5:
			objectsColor = sf::Color::White;
			break;
		case 6:
			objectsColor = sf::Color::Red;
			break;
		case 7:
			objectsColor = sf::Color::Magenta;
			break;
	}

	switch (settings[2])
	{
		case 1:
			if (!isAudioEnabled)
			{
				isAudioEnabled = true;
			}
			break;
		case 2:
			if (isAudioEnabled)
			{
				isAudioEnabled = false;
			}
			break;
	}
}

std::vector<size_t> Settings::getSettings()
{
	return settings;
}

sf::Color Settings::getMainItemColor()
{
	return mainItemColor;
}

sf::Color Settings::getObjectsColor()
{
	return objectsColor;
}

bool Settings::audioEnabled()
{
	return isAudioEnabled;
}
