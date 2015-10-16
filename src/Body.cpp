#include "Body.hpp"

Body::Body(){
	
}
Body::Body(std::string tname){
	//Eventually, we will change this constructor to instantiate various attributes(like hitpoints, shields whatever)
	//
	name = tname;
}

void Body::setColor(sf::Color tColor)
{
	color = tColor;
}

sf::ConvexShape Body::returnShape() const{
	sf::ConvexShape polygon;
	polygon.setPointCount(3);
	polygon.setPoint(0, sf::Vector2f(30,0));
	polygon.setPoint(1, sf::Vector2f(-15, -15));
	polygon.setPoint(2, sf::Vector2f(-15, 15));
	polygon.setFillColor(color);

	return polygon;
}




