#pragma once
#include <SFML/Audio.hpp>

enum class SoundName { MENU, GAME_OVER };

class Sound : public sf::Sound
{
	public:
		Sound();

		void playSound(SoundName sound_name);
		void disable();
		void enable();
	private:
		bool isEnabled;
		sf::SoundBuffer menu;
		sf::SoundBuffer game_over;
};