#include "Sound.h"

Sound::Sound()
{
	if (!menu.loadFromFile("menu_sound.wav"))
	{
	}
	if (!game_over.loadFromFile("game_over_sound.wav"))
	{
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