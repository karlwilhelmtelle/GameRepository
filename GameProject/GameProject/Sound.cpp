#include "Sound.h"

Sound::Sound()
{
	if (!menu.loadFromFile("menusound.wav"))
	{
	}
	if (!game_over.loadFromFile("gameoversound.wav"))
	{
	}
	if (!nope.loadFromFile("nope.wav"))
	{
	}
	if (!test.loadFromFile("game_over_sound_full.wav"))
	{
	}
	setBuffer(test);
	play();
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