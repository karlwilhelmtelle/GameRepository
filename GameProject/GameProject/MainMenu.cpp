#include "MainMenu.h"
#include "View.h"
#include <SFML/Audio.hpp>

MainMenu::MainMenu(const sf::VideoMode &resolution) :
	selectedIndex(0)
{
	const std::vector<sf::String> strings = {"Play", "Options", "Highscore", "Exit"};

	int i = 0;
	for (auto &string : strings)
	{
		Text *text = new Text();
		text->setString(string);
		text->setPosition(sf::Vector2f((float)resolution.width / 2.5f,
			(float)resolution.height / (strings.size() + 1) * (i + 1)));
		
		items.push_back(*text);
		++i;
	}

	items[selectedIndex].select();
}


void MainMenu::draw(View &window)
{
	for (auto &e : items)
	{
		window.draw(e);
	}
}


void MainMenu::keyEvent(sf::Keyboard::Key key, View &window)
{
	bool change = false;
	size_t tempSelectedIndex = selectedIndex;

	switch (key)
	{
		case sf::Keyboard::Up:
			if (tempSelectedIndex > 0)
			{
				change = true;
				--tempSelectedIndex;
			}
			break;
		case sf::Keyboard::Down:
			if (tempSelectedIndex < items.size() - 1)
			{
				change = true;
				++tempSelectedIndex;
			}
			break;
		case sf::Keyboard::Return:
			change = true;
			switch (selectedIndex)
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
			break;
	}

	if (change)
	{
		window.playSound(SoundName::MENU);
		items[selectedIndex].deselect();
		selectedIndex = tempSelectedIndex;
		items[selectedIndex].select();
	}
}

size_t MainMenu::getSelectedIndex()
{
	return selectedIndex;
}