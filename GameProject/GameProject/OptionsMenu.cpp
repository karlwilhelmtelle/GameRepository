#include "OptionsMenu.h"
#include "View.h"
#include "Level.h"
#include <SFML/Audio.hpp>


OptionsMenu::OptionsMenu(const sf::VideoMode &resolution, const std::vector<size_t> initSettings) :
	line(0)
{
	//const sf::String soundMenu[] = { "Colour (Character):", "Colour (Enemies):", "Sound:", "Back" };
	std::vector< std::vector<sf::String> > strings;
	strings.push_back({ "Character:", "Blue", "Cyan", "Green", "Yellow" , "White" ,"Red", "Magenta" });
	strings.push_back({ "Enemies:", "Blue", "Cyan", "Green", "Yellow" , "White" ,"Red", "Magenta" });
	strings.push_back({ "Sound:", "On" , "Off" });
	settings = initSettings;

	int i = 0;
	for (auto &row : strings)
	{
		std::vector<Text> lineElements;
		int j = 0;
		for (auto &col : row)
		{			
			Text *text = new Text();
			text->setString(col);
			text->setPosition(sf::Vector2f((float) resolution.width * (j + 1) / 10,
				(float)resolution.height * (i + 1) / 5));
			
			lineElements.push_back(*text);
			++j;
		}
		items.push_back(lineElements);
		++i;
	}
	items[line][settings[line]].select();
}


void OptionsMenu::draw(View & window)
{
	for (auto& row : items)
	{
		for (auto& col : row)
		{
			window.draw(col);
		}
	}
}

void OptionsMenu::keyEvent(sf::Keyboard::Key key, View & window)
{
	bool change = false;
	size_t temp_line = line;
	std::vector < size_t > temp_settings = settings;

	switch (key)
	{
		case sf::Keyboard::Right:
			if (temp_settings[line] < items[line].size() - 1)
			{
				change = true;
				++temp_settings[line];
			}
			break;
		case sf::Keyboard::Left:
			if (temp_settings[line] > size_t(1))
			{
				change = true;
				--temp_settings[line];
			}
			break;
		case sf::Keyboard::Down:
			if (temp_line < items.size() - 1)
			{
				change = true;
				++temp_line;
			}
			break;
		case sf::Keyboard::Up:
			if (temp_line > size_t(0))
			{
				change = true;
				--temp_line;
			}
			break;
		case sf::Keyboard::Return:
		case sf::Keyboard::Escape:
			window.updateSettings(settings);
			window.setGameState(GameState::MAIN_MENU);
			break;
	}

	if (change)
	{
		window.playSound(SoundName::MENU);
		items[line][settings[line]].deselect();
		line = temp_line;
		settings[line] = temp_settings[line];
		items[line][settings[line]].select();
	}
}