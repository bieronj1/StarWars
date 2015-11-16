#include "Nose.hpp"

Nose::Nose(){
	
}
Nose::Nose(std::string tname){
	//Eventually, we will change this constructor to instantiate various attributes(like hitpoints, shields whatever)
	//
	yOffset = 0;
	xOffset = 0;
	name = tname;
	if(!texture.loadFromFile("img/basenose.png")){
		std::cerr<<"Couldn't load the nose image\n";
	}
}

void Nose::setColor(sf::Color tColor)
{
	std::cerr << "change\n";
	color = tColor;
}

sf::RectangleShape Nose::returnShape() const{
	sf::RectangleShape polygon(sf::Vector2f(55,27.5));
  polygon.setTexture(&texture);
	polygon.setFillColor(color);

	return polygon;
}

void Nose::setYOffset(int y){
	yOffset = y;
}

void Nose::setXOffset(int x){
	xOffset = x;
}
int Nose::getXOffset() const
{
	return xOffset;
}

int Nose::getYOffset() const
{
	return yOffset;
}
