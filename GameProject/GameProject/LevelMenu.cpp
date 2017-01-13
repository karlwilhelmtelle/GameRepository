#include "LevelMenu.h"
#include "Window.h"

LevelMenu::LevelMenu(sf::VideoMode resolution):
	selected_index(0)
{
	for (int i = 0; i < MAX_LEVEL_MENU_POINTS; i++)
	{
		text[i].setFillColor(sf::Color::White);
		text[i].setString("Level " + std::to_string(i+1));
		text[i].setPosition(sf::Vector2f((float)resolution.width / 2.5f,
			(float)resolution.height / (MAX_LEVEL_MENU_POINTS + 1) * (i+1)));
	}
	text[0].setFillColor(sf::Color::Yellow);
}

void LevelMenu::draw(sf::RenderWindow & window)
{
	for (int i = 0; i < MAX_LEVEL_MENU_POINTS; i++)
	{
		window.draw(text[i]);
	}
}

void LevelMenu::keyEvent(sf::Keyboard::Key key, Window & window)
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
	else if (key == sf::Keyboard::Down && selected_index + 1 < MAX_LEVEL_MENU_POINTS)
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
		window.playLevel(selected_index);
	}
	else if (key == sf::Keyboard::Escape)
	{
		window.playSound(SoundName::MENU);
		window.setGameState(GameStates::MAIN_MENU);
	}
}

int LevelMenu::getSelectedLevelIndex()
{
	return selected_index;
}
