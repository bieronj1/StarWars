#include "Body.hpp"

Body::Body(){
	
}
Body::Body(std::string tname){
	//Eventually, we will change this constructor to instantiate various attributes(like hitpoints, shields whatever)
	//
	name = tname;
	if(!texture.loadFromFile("img/basebody.png")){
		std::cerr<<"Couldn't load the body image\n";
	}
}

void Body::setColor(sf::Color tColor)
{
	color = tColor;
}

sf::RectangleShape Body::returnShape() const{
	sf::RectangleShape polygon(sf::Vector2f(55,27.5));
	polygon.setTexture(&texture);
	polygon.setFillColor(color);

	return polygon;
}




