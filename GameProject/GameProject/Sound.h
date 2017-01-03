#pragma once
#include <SFML/Audio.hpp>

enum class SoundName { MENU, GAME_OVER };

class Sound : public sf::Sound
{
	public:
		Sound();

		void playSound(SoundName sound_name);
	private:
		sf::SoundBuffer menu;
		sf::SoundBuffer game_over;
		sf::SoundBuffer nope;
};