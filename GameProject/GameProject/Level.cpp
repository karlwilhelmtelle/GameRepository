#include "View.h"
#include "Level.h"

Level::Level(const sf::VideoMode &res) :
	resolution(res),
	item(res),
	levelIndex(0)
{
	const std::vector<std::string> strings = { "Time:", "", "Highscore:", ""};
	const std::vector<float> xPosition = {
		res.width / 50.0f,
		9.0f * res.width / 10.0f,
		8.0f * res.width / 10.0f,
		4.0f * res.width / 50.0f
	};

	int i = 0;
	for (auto &string : strings)
	{
		Text *text = new Text();
		text->setString(string);
		text->setPosition(sf::Vector2f(xPosition[i], res.height / 50.0f));
		textItems.push_back(*text);
		++i;
	}

	init();
}

void Level::init()
{
	restartClock();
	item.init();
	cameraSpeed = 0.2f;
	map.load(resolution);
}

void Level::update(bool * game_over)
{
	map.update(item.getPosition(), item.getRadius(), cameraSpeed, game_over);
	updateElapsedTime();
	updateHighscore();
	cameraSpeed *= 1.00001f;
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

	textItems[3].setStringToTime(timeMilli);
}

void Level::updateHighscore()
{
	if (timeMilli > highscoreMilli)
	{
		highscoreMilli = timeMilli;
		textItems[1].setStringToMilliseconds(highscoreMilli);
	}
}

void Level::updateSettings(sf::Color mainItemColor, sf::Color objectsColor)
{
	item.updateSettings(mainItemColor);
	map.updateSettings(objectsColor);
}

void Level::keyEvent(sf::Keyboard::Key key)
{
	item.keyEvent(key, cameraSpeed);
}

void Level::restartClock()
{
	clock.restart();
}

sf::Int32 Level::getLastScore()
{
	return timeMilli;
}

sf::Int32 Level::getHighscore()
{
	return highscoreMilli;
}
