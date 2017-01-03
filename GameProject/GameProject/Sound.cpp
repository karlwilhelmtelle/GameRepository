#include "Sound.h"

Sound::Sound()
{
	if (!menu.loadFromFile("menusound.wav"))
	{
		//Fehler beheben
	}
	if (!game_over.loadFromFile("gameoversound.wav"))
	{
		//Fehler beheben
	}
	if (!nope.loadFromFile("nope.wav"))
	{
		//Fehler beheben
	}
	setBuffer(nope);
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