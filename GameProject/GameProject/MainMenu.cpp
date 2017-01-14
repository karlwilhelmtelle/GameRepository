#include "MainMenu.h"
#include "Window.h"
#include <SFML/Audio.hpp>

MainMenu::MainMenu(sf::VideoMode resolution) :
	selected_index(0)
{
	const sf::String strings[] = {"Play", "Options", "Highscore", "Exit"};

	for (int i = 0; i < MAX_QUANTITY; i++)
	{
		text[i].setFillColor(sf::Color::White);
		text[i].setString(strings[i]);
		text[i].setPosition(sf::Vector2f((float)resolution.width / 2.5f,
			(float)resolution.height / (MAX_QUANTITY + 1) * (i+1)));
	}

	text[0].setFillColor(sf::Color::Yellow);
}


void MainMenu::draw(sf::RenderWindow &window)
{
	for (int i = 0; i < MAX_QUANTITY; i++)
	{
		window.draw(text[i]);
	}
}


void MainMenu::keyEvent(sf::Keyboard::Key key, Window &window)
{
	// move up
	if (key == sf::Keyboard::Up && selected_index - 1 >= 0)
	{
		window.playSound(SoundName::MENU);
		text[selected_index].setFillColor(sf::Color::White);
		selected_index--;
		text[selected_index].setFillColor(sf::Color::Yellow);
	}
	// move down
	else if (key == sf::Keyboard::Down && selected_index + 1 < MAX_QUANTITY)
	{
		window.playSound(SoundName::MENU);
		text[selected_index].setFillColor(sf::Color::White);
		selected_index++;
		text[selected_index].setFillColor(sf::Color::Yellow);
	}

	//enter
	if (key == sf::Keyboard::Return)
	{
		window.playSound(SoundName::MENU);
		switch (selected_index)
		{
			case 0:
				window.setGameState(GameState::LEVEL_MENU);
				break;
			case 1:
				window.setGameState(GameState::OPTIONS);
				break;
			case 2:
				window.setGameState(GameState::HIGHSCORE);
				break;
			case 3:
				window.close();
				break;
		}
	}
}

int MainMenu::getSelectedIndex()
{
	return selected_index;
}