#include "View.h"
#include "Level.h"

Level::Level(const sf::VideoMode &res) :
	resolution(res),
	item(res)
{
	
	const std::vector<std::string> strings = { "Time:", "", "Highscore:", ""};
	const std::vector<float> xPosition = {
		res.width / 50.0f,
		5.0f * res.width / 50.0f,
		37.0f * res.width / 50.0f,
		45.0f * res.width / 50.0f,
	};

	int i = 0;
	for (auto &string : strings)
	{
		Text *text = new Text(res.height);
		text->setString(string);
		text->setPosition(sf::Vector2f(xPosition[i], res.height / 50.0f));
		textItems.push_back(*text);
		++i;
	}

	setLevelIndex(0);
	init();
}

void Level::init()
{
	switch (levelIndex)
	{
		case 0:
			cameraSpeed = 0.2f;
			break;
		case 1:
			cameraSpeed = 0.4f;
			break;
		case 2:
			cameraSpeed = 0.6f;
			break;
	}

	restartClock();
	item.init();
	map.load(resolution);
}

void Level::update(bool * game_over)
{
	map.update(item.getPosition(), item.getRadius(), cameraSpeed, game_over);
	updateElapsedTime();
	updateHighscore();
	cameraSpeed += 0.000005f;
}

void Level::draw(View & window)
{
	for (auto &e : map.v)
	{
		window.draw(e);
	}

	window.draw(item);

	for (auto &e : textItems)
	{
		window.draw(e);
	}
}

void Level::updateElapsedTime()
{
	timeMilli = clock.getElapsedTime().asMilliseconds();

	textItems[1].setStringToTime(timeMilli);
}

void Level::updateHighscore()
{
	if (timeMilli > highscoreMilli)
	{
		highscoreMilli = timeMilli;
		textItems[3].setStringToTime(highscoreMilli);
	}
}

void Level::updateSettings(const sf::Color mainItemColor, const sf::Color objectsColor)
{
	item.updateSettings(mainItemColor);
	map.updateSettings(objectsColor);
}

void Level::setLevelIndex(const size_t newLevelIndex)
{
	if (levelIndex != newLevelIndex)
	{
		levelIndex = newLevelIndex;
		init();
	}
}

size_t Level::getLevelIndex() const
{
	return levelIndex;
}

void Level::keyEvent(const sf::Keyboard::Key key)
{
	item.keyEvent(key, cameraSpeed);
}

void Level::restartClock()
{
	clock.restart();
}

sf::Int32 Level::getLastScore() const
{
	return timeMilli;
}

sf::Int32 Level::getHighscore() const
{
	return highscoreMilli;
}
