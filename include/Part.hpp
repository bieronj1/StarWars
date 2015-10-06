#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <math.h>
#include <cmath>


/**
*This is an abstract class for each of the indivdual parts that the ship will comprise of.  
*These parts will can have various attributes set within them that will control the behaviour of various loots.  
*However, they all must be able to rotate and change position with the ship.  
*They all must also be drawable, so that the ship can render them. 
*
*Draw is the thing that is going to change the most.
**/
class Part {
  public:
		Part() {}
		virtual ~Part()=0;
		virtual sf::ConvexShape returnShape();
		std::string name;
		
	private:
		
		
		
	};