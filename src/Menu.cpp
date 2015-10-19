#include "Menu.hpp"

Menu::Menu()
{
	currentIndex = 0;
}

void Menu::addFlipper(Flipper f)
{
	flippers.push_back(f);
}

void Menu::flipperNext()
{
	flippers.at(currentIndex).next();
}

void Menu::flipperPrevious()
{
	flippers.at(currentIndex).previous();
}
void Menu::next()
{
	flippers.at(currentIndex).setHilighted(false);
	currentIndex++;
	currentIndex = currentIndex % flippers.size();
	flippers.at(currentIndex).setHilighted(true);
}

void Menu::previous()
{
	flippers.at(currentIndex).setHilighted(false);
	currentIndex--;
	if (currentIndex == -1) {
		currentIndex = flippers.size() - 1;
	}
	else {
		currentIndex = currentIndex % flippers.size();
	}
	flippers.at(currentIndex).setHilighted(true);
	
}

Flipper Menu::currentFlipper()
{
	return flippers.at(currentIndex);

}

void Menu::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	for(int i = 0; i < flippers.size(); i++ )
	{
		target.draw(flippers.at(i));
	}
}




