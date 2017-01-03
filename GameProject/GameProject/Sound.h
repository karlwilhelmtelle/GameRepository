#pragma once
#include <SFML/Audio.hpp>

class Sound : public sf::Sound
{
	public:
		Sound();

		void playSound();
	private:
		sf::SoundBuffer nope_sound;
};