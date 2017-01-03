#include "Sound.h"

Sound::Sound()
{
	if (!menu.loadFromFile("main_menu_sound.wav"))
	{
		//Fehler beheben
	}
}


void Sound::playSound(SoundName sound_name)
{
	if (sound_name == SoundName::MENU)
	{
		setBuffer(menu);
	}
	play();
}