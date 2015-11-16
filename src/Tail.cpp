#include "Tail.hpp"


Tail::Tail(){
	
}
Tail::Tail(std::string tname){
	//Eventually, we will change this constructor to instantiate various attributes(like hitpoints, shields whatever)
	//
	name = tname;
	if(!texture.loadFromFile("img/basetail.png")){
		std::cerr<<"Couldn't load the nose image\n";
	}
}

void Tail::setColor(sf::Color tColor)
{
	color = tColor;
}

sf::RectangleShape Tail::returnShape() const{
	sf::RectangleShape polygon(sf::Vector2f(55,27.5));
  polygon.setTexture(&texture);
	polygon.setFillColor(color);
	return polygon;
}
