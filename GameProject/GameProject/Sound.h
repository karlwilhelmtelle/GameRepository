#pragma once
#include <SFML/Audio.hpp>

enum class SoundName { MENU };

class Sound : public sf::Sound
{
	public:
		Sound();

		void playSound(SoundName sound_name);
	private:
		sf::SoundBuffer menu;
};