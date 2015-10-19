#include "Flipper.hpp"

Flipper::Flipper(float tx, float ty){
	x = tx;
	y = ty;
	index = 0;
	hilighted = false;
	if(!font.loadFromFile("lucon.ttf"))
	{
		std::cout<<"FONT FAILURE"<<std::endl;
	}
}


void Flipper::changeIndex(int change)
{
	index = index + change;
}

void Flipper::setHilighted(bool thilighted)
{

	hilighted = thilighted;
}

int Flipper::getIndex()
{
	return index;
}

bool Flipper::getHilighted()
{
	return hilighted;
}

void Flipper::addToList(std::string added)
{
	names.push_back(added);
}

std::string Flipper::returnText()
{
	return names.at(index);
}

void Flipper::previous()
{
	index--;
	if(index == -1)
	{
		index = names.size() - 1;
	}else
	{
	index = index % names.size();
  }
}
void Flipper::next()
{
	index++;
	index = index % names.size();


}

void Flipper::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	sf::Text text;
	text.setFont(font);
	text.setPosition(x, y);
	text.setString(names.at(index));
	
	if(hilighted)
	{
		text.setColor(sf::Color::Yellow);
	}else{
		text.setColor(sf::Color::White);
	}

	target.draw(text);
}