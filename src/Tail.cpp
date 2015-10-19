#include "Tail.hpp"


Tail::Tail(){
	
}
Tail::Tail(std::string tname){
	//Eventually, we will change this constructor to instantiate various attributes(like hitpoints, shields whatever)
	//
	name = tname;
}

void Tail::setColor(sf::Color tColor)
{
	color = tColor;
}

sf::ConvexShape Tail::returnLeftShape() const{
	sf::ConvexShape polygon;
	polygon.setPointCount(4);
	polygon.setPoint(0, sf::Vector2f(8, 5));
	polygon.setPoint(1, sf::Vector2f(5, -3));
	polygon.setPoint(2, sf::Vector2f(-3, -3));
	polygon.setPoint(3, sf::Vector2f(0, 5));
	
	polygon.setFillColor(color);
	

	return polygon;
}

sf::ConvexShape Tail::returnRightShape() const{
	sf::ConvexShape polygon;
	polygon.setPointCount(4);
	polygon.setPoint(0, sf::Vector2f(-8, 5));
	polygon.setPoint(1, sf::Vector2f(-5, -3));
	polygon.setPoint(2, sf::Vector2f(3, -3));
	polygon.setPoint(3, sf::Vector2f(0, 5));
	polygon.setFillColor(color);
	

	return polygon;
}