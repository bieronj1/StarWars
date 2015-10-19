#include "Nose.hpp"

Nose::Nose(){
	
}
Nose::Nose(std::string tname){
	//Eventually, we will change this constructor to instantiate various attributes(like hitpoints, shields whatever)
	//
	name = tname;
}

void Nose::setColor(sf::Color tColor)
{
	std::cerr << "change\n";
	color = tColor;
}

sf::ConvexShape Nose::returnShape() const{
	sf::ConvexShape polygon;
	polygon.setPointCount(3);
	polygon.setPoint(0, sf::Vector2f(10,0));
	polygon.setPoint(1, sf::Vector2f(-5, -5));
	polygon.setPoint(2, sf::Vector2f(-5, 5));
	polygon.setFillColor(color);

	return polygon;
}
