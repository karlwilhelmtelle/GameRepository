#include "HighscoreMenu.h"
#include "Level.h"
#include "View.h"
#include <SFML/Audio.hpp>

HighscoreMenu::HighscoreMenu(const sf::VideoMode &resolution) :
	selectedIndex(2),
	highscore_milliseconds(0),
	last_score_milliseconds(0)
{
	std::vector< std::vector < sf::String > > strings;
	strings.push_back({ "Last Score: ", "" });
	strings.push_back({ "Highscore: " , "" });
	strings.push_back({ "Back" });

	int i = 0;
	for (auto &row : strings)
	{
		int j = 0;
		std::vector < Text > lineElements;

		for (auto &col : row)
		{
			Text *text = new Text();
			text->setString(col);
			text->setPosition(sf::Vector2f(
				resolution.width * (j + 1) / 4.0f,
				resolution.height * (i + 1) / 4.0f	
			));
			lineElements.push_back(*text);
			++j;
		}

		items.push_back(lineElements);
		++i;
	}

	items[selectedIndex][0].select();
	updateTimeValues(highscore_milliseconds, last_score_milliseconds);
}

void HighscoreMenu::draw(View & window)
{
	for (auto &row : items)
	{
		for (auto &e : row)
		{
			window.draw(e);
		}
	}
}

void HighscoreMenu::keyEvent(sf::Keyboard::Key key, View & window)
{
	switch (key)
	{
		case sf::Keyboard::Return:
			window.setGameState(GameState::MAIN_MENU);
			break;
	}
}

void HighscoreMenu::updateTimeValues(sf::Int32 highscore, sf::Int32 last_score)
{
	highscore_milliseconds = highscore;
	last_score_milliseconds = last_score;
	items[0][1].setStringToTime(last_score_milliseconds);
	items[1][1].setStringToMilliseconds(highscore_milliseconds);
}

