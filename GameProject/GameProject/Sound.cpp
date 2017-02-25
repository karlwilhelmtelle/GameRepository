#include "Sound.h"

Sound::Sound() :
	isEnabled(true)
{
	if (!menu.loadFromFile("Sounds/menu_sound.wav"))
	{
		throw std::exception("Sounds/menu_sound.wav");
	}
	if (!game_over.loadFromFile("Sounds/game_over_sound.wav"))
	{
		throw std::exception("Sounds/game_over_sound.wav");
	}
}


void Sound::playSound(SoundName sound_name)
{
	if (isEnabled)
	{
		switch (sound_name)
		{
			case SoundName::MENU:
				setBuffer(menu);
				break;
			case SoundName::GAME_OVER:
				setBuffer(game_over);
				break;
		}

		play();
	}
}

void Sound::updateSettings(bool isAudioEnabled)
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
