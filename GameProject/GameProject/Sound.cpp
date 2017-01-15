#include "Sound.h"

Sound::Sound()
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
	if (sound_name == SoundName::MENU)
	{
		setBuffer(menu);
	}
	else if (sound_name == SoundName::GAME_OVER)
	{
		setBuffer(game_over);
	}

	play();
}