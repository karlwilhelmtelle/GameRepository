#include "LevelMenu.h"
#include "Window.h"

LevelMenu::LevelMenu(sf::VideoMode &resolution):
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

void LevelMenu::draw(Window & window)
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
		while (true)
		{
			selected_index--;
			if (!text[selected_index].isDisabled())
			{
				break;
			}
		}
		text[selected_index].setFillColor(sf::Color::Yellow);
	}
	// move down
	else if (key == sf::Keyboard::Down && selected_index + 1 < MAX_LEVEL_MENU_POINTS)
	{
		window.playSound(SoundName::MENU);
		text[selected_index].setFillColor(sf::Color::White);
		while (true)
		{
			selected_index++;
			if (!text[selected_index].isDisabled())
			{
				break;
			}
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

void LevelMenu::disableIndex(int index)
{
	text[index].disable();
}

void LevelMenu::enableIndex(int index)
{
	text[index].enable();
}
