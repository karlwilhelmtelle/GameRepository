#include "LevelMenu.h"
#include "Window.h"

LevelMenu::LevelMenu(sf::VideoMode resolution):
	selected_index(0)
{
	const sf::String strings[] = { "Level 1", "Level 2", "Level 3", "Back" };

	for (int i = 0; i < MAX_LEVEL_MENU_POINTS; i++)
	{
		text[i].setFillColor(sf::Color::White);
		text[i].setString(strings[i]);
		text[i].setPosition(sf::Vector2f((float)resolution.width / 2.5f,
			(float)resolution.height / (MAX_LEVEL_MENU_POINTS + 2) * (i+1)));
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
		if (!selection_disabled)
		{
			selected_index--;
		}
		else
		{
			selected_index = window.getLevelIndex();
		}
		text[selected_index].setFillColor(sf::Color::Yellow);
	}
	// move down
	else if (key == sf::Keyboard::Down && selected_index + 1 < MAX_LEVEL_MENU_POINTS)
	{
		window.playSound(SoundName::MENU);
		text[selected_index].setFillColor(sf::Color::White);
		if (!selection_disabled)
		{
			selected_index++;
		}
		else
		{
			selected_index = MAX_LEVEL_MENU_POINTS - 1;
		}
		text[selected_index].setFillColor(sf::Color::Yellow);
	}

	//enter
	if (key == sf::Keyboard::Return)
	{
		window.playSound(SoundName::MENU);
		if (selected_index != MAX_LEVEL_MENU_POINTS - 1)
		{
			window.setLevelIndex(selected_index);
		}
		else
		{
			window.setGameState(GameState::MAIN_MENU);
		}
	}
	else if (key == sf::Keyboard::Escape)
	{
		window.playSound(SoundName::MENU);
		window.setGameState(GameState::MAIN_MENU);
	}
}

int LevelMenu::getSelectedIndex()
{
	return selected_index;
}

void LevelMenu::disableSelection(int level_index_keep_selected)
{
	selection_disabled = true;

	for (int i = 0; i < MAX_LEVEL_MENU_POINTS - 1; i++)
	{
		if (i != level_index_keep_selected)
		{
			text[i].setFillColor(sf::Color::Red);
		}
	}
}

void LevelMenu::enableSelection()
{
	selection_disabled = false;

	for (int i = 0; i < MAX_LEVEL_MENU_POINTS - 1; i++)
	{
		if (i != selected_index)
		{
			text[i].setFillColor(sf::Color::White);
		}
	}
}
