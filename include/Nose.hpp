#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <math.h>
#include <cmath>

class Nose {
  public:
		std::string name;
		Nose();
		Nose(std::string tname) ;
		void setColor(sf::Color tcolor);
		sf::Color color;
		sf::ConvexShape returnShape() const;
		
  private:
	  
	}; 