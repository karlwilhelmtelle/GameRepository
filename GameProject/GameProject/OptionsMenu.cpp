#include "OptionsMenu.h"
#include "View.h"
#include "Level.h"
#include <SFML/Audio.hpp>


OptionsMenu::OptionsMenu(const sf::VideoMode &resolution) :
	line(0),
	column(0)
{
	const sf::String soundMenu[] = { "Colour (Character):", "Colour (Enemies):", "Sound:", "Back" };
	const sf::String soundOptions[] = { "On" , "Off" };
	const sf::String Colours[] = { "Black", "Blue", "Cyan", "Green", "Yellow" , "White" ,"Red", "Magenta" };
	const sf::String Colours2[] = { "Black", "Blue", "Cyan", "Green", "Yellow" , "White" ,"Red", "Magenta" };
	for (int i = 0; i < SOUND_OPTION_QUANTITY; i++)
	{
		s_o_Menu[i].setFillColor(sf::Color::White);
		s_o_Menu[i].setString(soundOptions[i]);
		s_o_Menu[i].setPosition(sf::Vector2f((float)(i + 3) * resolution.width / 8,
			3 * (float)resolution.height / 5));
	}


	for (int i = 0; i < SOUND_MENU_QUANTITY; i++)
	{
		s_o_Points[i].setFillColor(sf::Color::White);
		s_o_Points[i].setString(soundMenu[i]);
		s_o_Points[i].setPosition(sf::Vector2f((float)resolution.width / 8,
			(float)(i + 1) * resolution.height / 5));
	}

	for (int i = 0; i < COLOUR_QUANTITY; i++)
	{
		s_o_Colours[i].setFillColor(sf::Color::White);
		s_o_Colours[i].setString(Colours[i]);
		s_o_Colours[i].setPosition(sf::Vector2f((float)(i + 6) * resolution.width / 16,
			(float)resolution.height / 5));
	}
	for (int i = 0; i < COLOUR_QUANTITY_2; i++)
	{
		s_o_Colours2[i].setFillColor(sf::Color::White);
		s_o_Colours2[i].setString(Colours2[i]);
		s_o_Colours2[i].setPosition(sf::Vector2f((float)(i + 6) * resolution.width / 16,
			2 * (float)resolution.height / 5));
	}
	s_o_Colours[0].setFillColor(sf::Color::Yellow);
}

void OptionsMenu::draw(View & window)
{
	for (int i = 0; i < SOUND_OPTION_QUANTITY; i++)
	{
		window.draw(s_o_Menu[i]);
	}
	for (int i = 0; i < SOUND_MENU_QUANTITY; i++)
	{
		window.draw(s_o_Points[i]);
	}
	for (int i = 0; i < COLOUR_QUANTITY; i++)
	{
		window.draw(s_o_Colours[i]);
	}
	for (int i = 0; i < COLOUR_QUANTITY_2; i++)
	{
		window.draw(s_o_Colours2[i]);
	}
}

void OptionsMenu::keyEvent(sf::Keyboard::Key key, View & window)
{
	switch (line)
	{
		case 0:
		{
			if (key == sf::Keyboard::Right && column <= 6)
			{
				window.playSound(SoundName::MENU);
				s_o_Colours[column].setFillColor(sf::Color::White);
				column++;
				s_o_Colours[column].setFillColor(sf::Color::Yellow);
			}
			else if (key == sf::Keyboard::Left && column > 0)
			{
				window.playSound(SoundName::MENU);
				s_o_Colours[column].setFillColor(sf::Color::White);
				column--;
				s_o_Colours[column].setFillColor(sf::Color::Yellow);
			}
			else if (key == sf::Keyboard::Down)
			{
				window.playSound(SoundName::MENU);
				line++;
				s_o_Colours2[column].setFillColor(sf::Color::Yellow);
				s_o_Colours[column].setFillColor(sf::Color::White);
			}
			break;
		}

		case 1:
		{
			if (key == sf::Keyboard::Right && column <= 6)
			{
				window.playSound(SoundName::MENU);
				s_o_Colours2[column].setFillColor(sf::Color::White);
				column++;
				s_o_Colours2[column].setFillColor(sf::Color::Yellow);
			}
			else if (key == sf::Keyboard::Left && column > 0)
			{
				window.playSound(SoundName::MENU);
				s_o_Colours2[column].setFillColor(sf::Color::White);
				column--;
				s_o_Colours2[column].setFillColor(sf::Color::Yellow);
			}
			else if (key == sf::Keyboard::Down)
			{
				window.playSound(SoundName::MENU);
				line++;
				s_o_Menu[0].setFillColor(sf::Color::Yellow);
				s_o_Colours2[column].setFillColor(sf::Color::White);
				column = 0;
			}
			else if (key == sf::Keyboard::Up)
			{
				window.playSound(SoundName::MENU);
				line--;
				s_o_Colours[column].setFillColor(sf::Color::Yellow);
				s_o_Colours2[column].setFillColor(sf::Color::White);
			}
			break;
		}

		case 2:
		{
			if (key == sf::Keyboard::Right && column < 1)
			{
				window.playSound(SoundName::MENU);
				s_o_Menu[column].setFillColor(sf::Color::White);
				column++;
				s_o_Menu[column].setFillColor(sf::Color::Yellow);
				s_o_Menu[5].setFillColor(sf::Color::White);
			}
			else if (key == sf::Keyboard::Left && column > 0)
			{
				window.playSound(SoundName::MENU);
				s_o_Menu[column].setFillColor(sf::Color::White);
				column--;
				s_o_Menu[column].setFillColor(sf::Color::Yellow);
				s_o_Menu[5].setFillColor(sf::Color::White);
			}
			else if (key == sf::Keyboard::Up)
			{
				window.playSound(SoundName::MENU);
				line--;
				s_o_Colours2[column].setFillColor(sf::Color::Yellow);
				s_o_Menu[column].setFillColor(sf::Color::White);
				s_o_Menu[5].setFillColor(sf::Color::White);
			}
			else if (key == sf::Keyboard::Down)
			{
				window.playSound(SoundName::MENU);
				line++;
				s_o_Menu[5].setFillColor(sf::Color::Yellow);
				s_o_Menu[column].setFillColor(sf::Color::White);
			}
			break;
		}

		case 3:
		{
			if (key == sf::Keyboard::Return)
			{
				window.setGameState(GameState::MAIN_MENU);
			}
			else if (key == sf::Keyboard::Up)
			{
				window.playSound(SoundName::MENU);
				line--;
				s_o_Menu[0].setFillColor(sf::Color::Yellow);
				s_o_Colours2[column].setFillColor(sf::Color::White);
				s_o_Menu[5].setFillColor(sf::Color::White);
				column = 0;
			}
		}
	}
}

int OptionsMenu::getLine()
{
	return line;
}

int OptionsMenu::getColumn()
{
	return column;
}

