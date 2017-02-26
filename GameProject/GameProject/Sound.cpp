#include "Sound.h"

Sound::Sound() :
	isEnabled(true)
{
	if (!menu.loadFromFile("Sounds/menu_sound.wav"))
	{
		throw std::runtime_error("Missing file: Sounds/menu_sound.wav");
	}
	if (!gameOver.loadFromFile("Sounds/game_over_sound.wav"))
	{
		throw std::runtime_error("Missing file: Sounds/game_over_sound.wav");
	}
}


void Sound::playSound(const SoundName sound_name)
{
	if (isEnabled)
	{
		switch (sound_name)
		{
			case SoundName::MENU:
				setBuffer(menu);
				break;
			case SoundName::GAME_OVER:
				setBuffer(gameOver);
				break;
		}

		play();
	}
}

void Sound::updateSettings(const bool isAudioEnabled)
{
	if (isAudioEnabled && !isEnabled)
	{
		isEnabled = true;
	}
	else if (!isAudioEnabled && isEnabled)
	{
		isEnabled = false;
	}
}
