#include "highscore_menu.h"
#include "Window.h"
#include <SFML/Audio.hpp>

highscore_menu::~highscore_menu()
{
}

highscore_menu::highscore_menu(sf::VideoMode resolution):
	selectedIndexHighscore(0)
{
	const sf::String text[] = { "Last Score: ", "Highscore: ", "Sound: " };
	const sf::String soundOptions[] = { "On" , "Off" };
	for (int i = 0; i < MAX_QUANTITY_HIGHSCORE; i++)
	{
		textHighscore_menu[i].setFillColor(sf::Color::White);
		textHighscore_menu[i].setString(text[i]);
		textHighscore_menu[i].setPosition(sf::Vector2f((float)resolution.width / 3.5f,
			(float)resolution.height / (MAX_QUANTITY_HIGHSCORE + 1) * (i + 1)));
	}
	for (int i = 0; i < SOUND_OPTION_QUANTITY; i++)
	{
		s_o_Highscore_menu[i].setFillColor(sf::Color::White);
		s_o_Highscore_menu[i].setString(soundOptions[i]);
		s_o_Highscore_menu[i].setPosition(sf::Vector2f((float)(i+2) * resolution.width / 4,
			3 * (float)resolution.height / 4));
	}
	s_o_Highscore_menu[0].setFillColor(sf::Color::Yellow);
}

void highscore_menu::draw(sf::RenderWindow & window)
{
	for (int i = 0; i < MAX_QUANTITY_HIGHSCORE; i++)
	{
		window.draw(textHighscore_menu[i]);
	}
	for (int i = 0; i < SOUND_OPTION_QUANTITY; i++)
	{
		window.draw(s_o_Highscore_menu[i]);
	}
}

void highscore_menu::keyEvent(sf::Keyboard::Key key, Window & window)
{
	if (key == sf::Keyboard::Right && selectedIndexHighscore == 0)
	{
		window.playSound(SoundName::MENU);
		s_o_Highscore_menu[selectedIndexHighscore].setFillColor(sf::Color::White);
		selectedIndexHighscore++;
		s_o_Highscore_menu[selectedIndexHighscore].setFillColor(sf::Color::Yellow);
	}

	else if (key == sf::Keyboard::Left && selectedIndexHighscore == 1)
	{
		window.playSound(SoundName::MENU);
		s_o_Highscore_menu[selectedIndexHighscore].setFillColor(sf::Color::White);
		selectedIndexHighscore--;
		s_o_Highscore_menu[selectedIndexHighscore].setFillColor(sf::Color::Yellow);
	}
	if (key == sf::Keyboard::Return)
	{
		switch (selectedIndexHighscore)
		{
		case 0:
			//resume all sounds
			break;
		case 1:
			//mute all sounds
			break;
		}
	}
}

int highscore_menu::getSelectedIndex()
{
	return 0;
}

