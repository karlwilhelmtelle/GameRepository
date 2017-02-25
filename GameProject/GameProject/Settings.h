#pragma once
#include <SFML/Graphics.hpp>

class Settings
{
	public:
		Settings();

		void update(const std::vector<size_t> settings);

		std::vector<size_t> getSettings() const;

		sf::Color getMainItemColor() const;

		sf::Color getObjectsColor() const;

		bool audioEnabled() const;

		void convertToColor(sf::Color &color, const size_t colorSettings);
	private:
		std::vector <size_t> settings;
		sf::Color mainItemColor;
		sf::Color objectsColor;
		bool isAudioEnabled;
};