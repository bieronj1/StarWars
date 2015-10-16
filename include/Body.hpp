#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <math.h>
#include <cmath>
//#include "Part.hpp"

class Body {
  public:
		std::string name;
		Body();
		Body(std::string tname) ;
		void setColor(sf::Color tcolor);
		sf::Color color;
		sf::ConvexShape returnShape() const;
		
  private:
	  
	};