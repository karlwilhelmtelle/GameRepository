#include "Sound.h"

Sound::Sound()
{
	if (!nope_sound.loadFromFile("nope sound.wav"))
	{
		//Fehler beheben
	}
}


void Sound::playSound()
{
	setBuffer(nope_sound);
	play();
}