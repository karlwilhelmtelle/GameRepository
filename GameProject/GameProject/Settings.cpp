#include "Settings.h"

Settings::Settings() :
	settings({2, 6, 1})
{
	update(settings);
}

void Settings::update(const std::vector<size_t> settings)
{
	convertToColor(mainItemColor, settings[0]);
	convertToColor(objectsColor, settings[1]);

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

void Settings::convertToColor(sf::Color &color, const size_t colorSettings)
{
	switch (colorSettings)
	{
	case 1:
		color = sf::Color::Blue;
	case 2:
		color = sf::Color::Cyan;
		break;
	case 3:
		color = sf::Color::Green;
		break;
	case 4:
		color = sf::Color::Yellow;
		break;
	case 5:
		color = sf::Color::White;
		break;
	case 6:
		color = sf::Color::Red;
		break;
	case 7:
		color = sf::Color::Magenta;
		break;
	}
}

std::vector<size_t> Settings::getSettings() const
{
	return settings;
}

sf::Color Settings::getMainItemColor() const
{
	return mainItemColor;
}

sf::Color Settings::getObjectsColor() const
{
	return objectsColor;
}

bool Settings::audioEnabled() const
{
	return isAudioEnabled;
}
