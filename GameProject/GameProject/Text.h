#pragma once
#include <SFML/Graphics.hpp>


class Text : public sf::Text
{
public:
	Text();

	void setStringToTime(sf::Int32 milliseconds);
	
	void setStringToMilliseconds(sf::Int32 milliseconds);

	void enable();
	void disable();
	bool isDisabled();
	void hs_text();
	void game_time();
	void highscore_text();
	void highscore_menu_text();
	void highscore_menu_time();
	void highscore_menu(sf::Int32 milliseconds);
private:
	sf::Font font;
	bool is_disabled;
};