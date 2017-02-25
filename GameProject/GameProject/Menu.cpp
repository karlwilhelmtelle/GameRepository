#include "Menu.h"
#include "View.h"

Menu::Menu(const sf::VideoMode & res, const std::vector<size_t> settings) :
	currentMenu(MenuState::MainMenu)
{
	std::vector< std::vector < std::vector <sf::String>>> strings = {
		{ 
			{ "Play" },{ "Options" },{ "Highscore" }, { "Exit" } 
		},
		{ 
			{"Level 1"},{ "Level 2" },{ "Level 3" },{ "Back" } 
		},
		{
			{ "Character:", "Blue", "Cyan", "Green", "Yellow" , "White" ,"Red", "Magenta" },
			{ "Enemies:", "Blue", "Cyan", "Green", "Yellow" , "White" ,"Red", "Magenta" },
			{ "Sound:", "On" , "Off" },
		},
		{
			{ "Last Score: ", "" },
			{ "Highscore: " , "" },
			{ "Back" }
		}
	};

	selectedRow = { 0, 0, 0, 2 };
	selectedCol = {
		{ 0, 0, 0, 0 },
		{ 0, 0, 0, 0 },
		{ settings[0], settings[1], settings[2], 0 },
		{ 0, 0, 0 }
	};

	int i = 0;
	for (auto &menu : strings)
	{
		int j = 0;
		std::vector < std::vector <Text> > menuElements;
		for (auto &row : menu)
		{
			int k = 0;
			std::vector < Text > lineElements;

			for (auto &col : row)
			{
				Text *text = new Text();
				text->setString(col);
				text->setPosition(getPosition(
					(MenuState)i, res, 
					menu.size(), row.size(), 
					j, k));
				lineElements.push_back(*text);
				++k;
			}

			menuElements.push_back(lineElements);
			++j;
		}

		items.push_back(menuElements);
		++i;
	}

	// items -> MenuArt -> Zeile -> Spalte;
	i = 0;
	for (auto &menu : items)
	{
		getSelectedElement((MenuState)i)->select();
		++i;
	}

	items[HighscoreMenu][0][1].setStringToTime(0);
	items[HighscoreMenu][1][1].setStringToMilli(0);
}

void Menu::draw(View & window) const
{
	for (auto &row : items[currentMenu])
	{
		for (auto &e : row)
		{
			window.draw(e);
		}
	}
}

void Menu::updateHighscore(const sf::Int32 highscore, const sf::Int32 lastScore)
{
	items[HighscoreMenu][0][1].setStringToTime(lastScore);
	items[HighscoreMenu][1][1].setStringToMilli(highscore);
}

void Menu::setMenu(const MenuState type)
{
	if (type != currentMenu)
	{
		currentMenu = type;
	}
}

sf::Vector2f Menu::getPosition(const MenuState menu, const sf::VideoMode res, 
	const size_t maxRows, const size_t maxCols, 
	const size_t row, const size_t col) const
{
	sf::Vector2f pos;

	switch (menu)
	{
		case MainMenu:
		{
			pos.x = res.width / 2.5f;
			pos.y = res.height * (row + 1.0f) / (maxRows + 1.0f);
			break;
		}
		case LevelMenu:
		{
			pos.x = res.width / 2.5f;
			pos.y = res.height * (row + 1.0f) / (maxRows + 2.0f);
			break;
		}
		case OptionsMenu:
		{
			pos.x = res.width * (col + 1.0f) / 10.0f;
			pos.y = res.height * (row + 1.0f) / 5.0f;
			break;
		}
		case HighscoreMenu:
		{
			pos.x = res.width * (col + 1.0f) / 4.0f;
			pos.y = res.height * (row + 1.0f) / 4.0f;
			break;
		}
	}

	return pos;
}

Text * Menu::getSelectedElement(const MenuState menu)
{
	return & items[menu][selectedRow[menu]][selectedCol[menu][selectedRow[menu]]];
}

void Menu::keyEvent(const sf::Keyboard::Key key, View & window)
{
	bool change = false;
	size_t newSelectedRow = selectedRow[currentMenu];
	size_t newSelectedCol = selectedCol[currentMenu][newSelectedRow];

	switch (currentMenu)
	{
		case MainMenu:
		{
			switch (key)
			{
				case sf::Keyboard::Up:
				{
					if (newSelectedRow > 0)
					{
						change = true;
						--newSelectedRow;
					}
					break;
				}
				case sf::Keyboard::Down:
				{
					if (newSelectedRow < items[currentMenu].size() - 1)
					{
						change = true;
						++newSelectedRow;
					}
					break;
				}
				case sf::Keyboard::Return:
				{
					switch (newSelectedRow)
					{
						case 0:
							setMenu(LevelMenu);
							break;
						case 1:
							setMenu(OptionsMenu);
							break;
						case 2:
							setMenu(HighscoreMenu);
							break;
						case 3:
							window.close();
							break;
					}
					window.playSound(SoundName::MENU);
					break;
				}
			} // end switch
			break;
		} // end case Main

		case LevelMenu:
		{
			switch (key)
			{
				case sf::Keyboard::Up:
				{
					if (newSelectedRow > 0)
					{
						change = true;
						--newSelectedRow;
					}
					break;
				}
				case sf::Keyboard::Down:
				{
					if (newSelectedRow < items[currentMenu].size() - 1)
					{
						change = true;
						++newSelectedRow;
					}
					break;
				}
				case sf::Keyboard::Return:
				{
					if (newSelectedRow != items[currentMenu].size() - 1)
					{
						window.setLevelIndex(newSelectedRow);
					}
					else
					{
						setMenu(MainMenu);
						window.playSound(SoundName::MENU);
					}
					break;
				}
				case sf::Keyboard::Escape:
				{
					setMenu(MainMenu);
					window.playSound(SoundName::MENU);
					break;
				}
			} // end switch
			break;
		} //end case Level

		case OptionsMenu:
		{
			switch (key)
			{
				case sf::Keyboard::Right:
				{
					if (newSelectedCol < items[currentMenu][newSelectedRow].size() - 1)
					{
						change = true;
						++newSelectedCol;
					}
					break;
				}
				case sf::Keyboard::Left:
				{
					if (newSelectedCol > size_t(1))
					{
						change = true;
						--newSelectedCol;
					}
					break;
				}
				case sf::Keyboard::Down:
				{
					if (newSelectedRow < items[currentMenu].size() - 1)
					{
						change = true;
						++newSelectedRow;
					}
					break;
				}
				case sf::Keyboard::Up:
				{
					if (newSelectedRow > size_t(0))
					{
						change = true;
						--newSelectedRow;
					}
					break;
				}
				case sf::Keyboard::Return:
				case sf::Keyboard::Escape:
				{
					window.updateSettings(selectedCol[currentMenu]);
					setMenu(MainMenu);
					window.playSound(SoundName::MENU);
					break;
				}
			} //end switch
			break;
		} //end case Options

		case HighscoreMenu:
		{
			switch (key)
			{
				case sf::Keyboard::Return:
				case sf::Keyboard::Escape:
				{
					setMenu(MainMenu);
					window.playSound(SoundName::MENU);
					break;
				}
			} //end switch
			break;
		} //end case Highscore
	} //end switch

	if (change)
	{
		window.playSound(SoundName::MENU);
		getSelectedElement(currentMenu)->deselect();

		selectedCol[currentMenu][selectedRow[currentMenu]] = newSelectedCol;
		selectedRow[currentMenu] = newSelectedRow;
		
		getSelectedElement(currentMenu)->select();
	}
}