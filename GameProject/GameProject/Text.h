#pragma once
#include <SFML/Graphics.hpp>


class Text : public sf::Text
{
	public:
		Text(const unsigned int resHeight);

		void setStringToTime(const sf::Int32 milliseconds);
	
		void setStringToMilli(const sf::Int32 milliseconds);

		void enable();
		void disable();
		bool enabled() const;

		void select();
		void deselect();
	private:
		sf::Font font;
		bool isEnabled;
		bool isSelected;
};