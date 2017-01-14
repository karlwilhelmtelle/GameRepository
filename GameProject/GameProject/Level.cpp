#include "Window.h"
#include "Level.h"

Level::Level(sf::VideoMode &res) :
	resolution(res),
	item(res),
	level_index(0)
{
	time_text.setFillColor(sf::Color::White);
	time_text.setString("00:00:000");
	time_text.setPosition(sf::Vector2f((float)res.width / 50,
		(float)res.height / 50));

	highscore_text.setFillColor(sf::Color::White);
	highscore_text.setStringToTime(0);
	highscore_text.setPosition(sf::Vector2f((float)9 * res.width / 10,
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

void Level::draw(Window & window)
{
	window.draw(item);
	window.draw(time_text);
	window.draw(highscore_text);

	for (auto e = map.v.begin(); e != map.v.end(); ++e)
	{
		window.draw(*e);
	}
	/*
	// TODO: Ausgabe der Zeit im Spiel und Ausgabe der Gesamtzeit fehlt
	float game_time = clock.getElapsedTime().asMilliseconds() / 1000.f;
	int score = (int) game_time / 1000;*/
}

void Level::updateElapsedTime()
{
	time_milliseconds = clock.getElapsedTime().asMilliseconds();

	time_text.setStringToTime(time_milliseconds);
}

void Level::updateHighscore()
{
	if (time_milliseconds > highscore_milliseconds)
	{
		highscore_milliseconds = time_milliseconds;
		highscore_text.setStringToMilliseconds(highscore_milliseconds);
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
