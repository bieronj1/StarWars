#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <math.h>
#include <cmath>
//#include "Part.hpp"

class Tail {
  public:
		std::string name;
		Tail();
		Tail(std::string tname) ;
		void setColor(sf::Color tcolor);
		sf::Color color;
		sf::ConvexShape returnLeftShape() const;
		sf::ConvexShape returnRightShape() const;
		
  private:
	  
	};