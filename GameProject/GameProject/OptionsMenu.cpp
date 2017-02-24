#include "OptionsMenu.h"
#include "View.h"
#include "Level.h"
#include <SFML/Audio.hpp>


OptionsMenu::OptionsMenu(const sf::VideoMode &resolution) :
	line(0)
{
	//const sf::String soundMenu[] = { "Colour (Character):", "Colour (Enemies):", "Sound:", "Back" };
	std::vector < std::vector <sf::String> > strings;
	strings.push_back({ "Character:", "Blue", "Cyan", "Green", "Yellow" , "White" ,"Red", "Magenta" });
	strings.push_back({ "Enemies:", "Blue", "Cyan", "Green", "Yellow" , "White" ,"Red", "Magenta" });
	strings.push_back({ "Sound:", "On" , "Off" });
	settings = { 2, 6, 1 };

	int i = 0;
	for (auto& row : strings)
	{
		std::vector<Text> line_items;
		int j = 0;
		for (auto& col : row)
		{
			Text text;
			text.setFillColor(sf::Color::White);
			text.setString(col);
			text.setPosition(sf::Vector2f((float) resolution.width * (j + 1) / 10,
				(float)resolution.height * (i + 1) / 5));
			line_items.push_back(text);
			j++;
		}
		items.push_back(line_items);
		i++;
	}
	items[line][settings[line]].setFillColor(sf::Color::Yellow);
}

void OptionsMenu::draw(View & window)
{
	for (auto& row : items)
	{
		for (auto& col : row)
		{
			Text text;
			text.setString(col.getString());
			text.setPosition(col.getPosition());
			text.setFillColor(col.getFillColor());
			window.draw(text);
		}
	}
}

void OptionsMenu::keyEvent(sf::Keyboard::Key key, View & window)
{
	items[line][settings[line]].setFillColor(sf::Color::White);
	switch (key)
	{
		case sf::Keyboard::Right:
			settings[line]++;
			window.playSound(SoundName::MENU);
			break;
		case sf::Keyboard::Left:
			settings[line]--;
			window.playSound(SoundName::MENU);
			break;
		case sf::Keyboard::Up:
			line--;
			window.playSound(SoundName::MENU);
			break;
		case sf::Keyboard::Down:
			line++;
			window.playSound(SoundName::MENU);
			break;
		case sf::Keyboard::Return:
			window.updateSettings(settings);
			window.setGameState(GameState::MAIN_MENU);
			break;
		case sf::Keyboard::Escape:
			window.updateSettings(settings);
			window.setGameState(GameState::MAIN_MENU);
			break;
	}
	line = std::min(std::max(line, size_t(0)), items.size() - 1);
	settings[line] = std::min(std::max(settings[line], size_t(1)), items[line].size() - 1);
	items[line][settings[line]].setFillColor(sf::Color::Yellow);
}