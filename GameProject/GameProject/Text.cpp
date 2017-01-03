#include "Text.h"

Text::Text()
{
	if (!font.loadFromFile("OpenSans-Bold.ttf"))
	{
		//Fehler beheben
	}
	setFont(font);
}