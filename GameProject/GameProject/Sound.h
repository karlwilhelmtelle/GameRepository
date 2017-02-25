#pragma once
#include <SFML/Audio.hpp>

enum class SoundName { MENU, GAME_OVER };

class Sound : public sf::Sound
{
	public:
		Sound();

		void playSound(const SoundName soundName);
		void updateSettings(const bool isEnabled);
	private:
		bool isEnabled;
		sf::SoundBuffer menu;
		sf::SoundBuffer gameOver;
};