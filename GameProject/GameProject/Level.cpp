#include "View.h"
#include "Level.h"

Level::Level(const sf::VideoMode &res) :
	resolution(res),
	item(res),
	level_index(0)
{
	highscore_text.setString("Highscore:");
	highscore_text.setPosition(sf::Vector2f((float)8 * res.width / 10,
		(float)res.height / 50));
	highscore_text.setFillColor(sf::Color::White);

	time_text.setString("Time:");
	time_text.setPosition(sf::Vector2f((float)res.width / 50,
		(float)res.height / 50));
	time_text.setFillColor(sf::Color::White);

	time_value.setFillColor(sf::Color::White);
	time_value.setString("00:00:000");
	time_value.setPosition(sf::Vector2f((float)4 * res.width / 50,
		(float)res.height / 50));

	highscore_value.setFillColor(sf::Color::White);
	highscore_value.setStringToTime(0);
	highscore_value.setPosition(sf::Vector2f((float)9 * res.width / 10,
		(float)res.height / 50));
}

void Level::init()
{
	restartClock();
	item.init();
	camera_speed = 0.2f;
	map.load(resolution);
}

void Level::update(bool * game_over)
{
	map.update(item.getPosition(), item.getRadius(), camera_speed, game_over);
	updateElapsedTime();
	updateHighscore();
	camera_speed *= 1.00001f;
}

void Level::draw(View & window)
{
	for (auto e = map.v.begin(); e != map.v.end(); ++e)
	{
		window.draw(*e);
	}

	window.draw(item);
	window.draw(time_value);
	window.draw(highscore_value);
	window.draw(highscore_text);
	window.draw(time_text);
}

void Level::updateElapsedTime()
{
	time_milliseconds = clock.getElapsedTime().asMilliseconds();

	time_value.setStringToTime(time_milliseconds);
}

void Level::updateHighscore()
{
	if (time_milliseconds > highscore_milliseconds)
	{
		highscore_milliseconds = time_milliseconds;
		highscore_value.setStringToMilliseconds(highscore_milliseconds);
	}
}

void Level::updateSettings(std::vector<size_t> settings)
{
	switch (settings[0])
	{
		case 1:
			item.setFillColor(sf::Color::Blue);
			break;
		case 2:
			item.setFillColor(sf::Color::Cyan);
			break;
		case 3:
			item.setFillColor(sf::Color::Green);
			break;
		case 4:
			item.setFillColor(sf::Color::Yellow);
			break;
		case 5:
			item.setFillColor(sf::Color::White);
			break;
		case 6:
			item.setFillColor(sf::Color::Red);
			break;
		case 7:
			item.setFillColor(sf::Color::Magenta);
			break;
	}

	switch (settings[1])
	{
	case 1:
		map.setFillColor(sf::Color::Blue);
		break;
	case 2:
		map.setFillColor(sf::Color::Cyan);
		break;
	case 3:
		map.setFillColor(sf::Color::Green);
		break;
	case 4:
		map.setFillColor(sf::Color::Yellow);
		break;
	case 5:
		map.setFillColor(sf::Color::White);
		break;
	case 6:
		map.setFillColor(sf::Color::Red);
		break;
	case 7:
		map.setFillColor(sf::Color::Magenta);
		break;
	}
}

void Level::keyEvent(sf::Keyboard::Key key)
{
	item.keyEvent(key, camera_speed);
}

void Level::restartClock()
{
	clock.restart();
}

sf::Int32 Level::getLastScore()
{
	return time_milliseconds;
}

sf::Int32 Level::getHighscore()
{
	return highscore_milliseconds;
}
