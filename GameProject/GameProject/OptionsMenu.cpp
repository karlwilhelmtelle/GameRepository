#include "OptionsMenu.h"
#include "View.h"
#include "Level.h"
#include <SFML/Audio.hpp>


OptionsMenu::OptionsMenu(const sf::VideoMode &resolution, const std::vector<size_t> initSettings) :
	selectedLineIndex(0)
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
	items[selectedLineIndex][settings[selectedLineIndex]].select();
}


void OptionsMenu::draw(View & window) const
{
	for (auto& row : items)
	{
		for (auto& col : row)
		{
			window.draw(col);
		}
	}
}

void OptionsMenu::keyEvent(const sf::Keyboard::Key key, View & window)
{
	bool change = false;
	size_t temp_line = selectedLineIndex;
	std::vector < size_t > temp_settings = settings;

	switch (key)
	{
		case sf::Keyboard::Right:
			if (temp_settings[selectedLineIndex] < items[selectedLineIndex].size() - 1)
			{
				change = true;
				++temp_settings[selectedLineIndex];
			}
			break;
		case sf::Keyboard::Left:
			if (temp_settings[selectedLineIndex] > size_t(1))
			{
				change = true;
				--temp_settings[selectedLineIndex];
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
		items[selectedLineIndex][settings[selectedLineIndex]].deselect();
		selectedLineIndex = temp_line;
		settings[selectedLineIndex] = temp_settings[selectedLineIndex];
		items[selectedLineIndex][settings[selectedLineIndex]].select();
	}
}