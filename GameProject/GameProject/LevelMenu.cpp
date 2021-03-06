#include "LevelMenu.h"
#include "View.h"

LevelMenu::LevelMenu(const sf::VideoMode &resolution):
	selectedLineIndex(0)
{
	const std::vector<sf::String> strings = { "Level 1", "Level 2", "Level 3", "Back" };

	int i = 0;
	for (auto &string : strings)
	{
		Text *text = new Text();
		text->setString(string);
		text->setPosition(sf::Vector2f((float)resolution.width / 2.5f,
			(float)resolution.height / (strings.size() + 2) * (i+1)));

		items.push_back(*text);
		++i;
	}

	items[selectedLineIndex].select();
}

void LevelMenu::draw(View & window) const
{
	for (auto &e : items)
	{
		window.draw(e);
	}
}

void LevelMenu::keyEvent(const sf::Keyboard::Key key, View & window)
{
	bool change = false;
	size_t tempSelectedIndex = selectedLineIndex;

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
		if (selectedLineIndex != items.size() - 1)
		{
			window.setLevelIndex(selectedLineIndex);
		}
		else
		{
			window.setGameState(GameState::MAIN_MENU);
		}
		break;
	case sf::Keyboard::Escape:
		change = true;
		window.setGameState(GameState::MAIN_MENU);
		break;
	}

	if (change)
	{
		window.playSound(SoundName::MENU);
		items[selectedLineIndex].deselect();
		selectedLineIndex = tempSelectedIndex;
		items[selectedLineIndex].select();
	}
}