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
		sf::ConvexShape returnShape() const;
		
  private:
	  
	};