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
		virtual sf::RectangleShape returnShape() const;
		sf::Texture texture;
		int yOffset; int xOffset;
		int getYOffset() const; int getXOffset() const;
		void setYOffset(int y); void setXOffset(int x);
		
		
  private:
	  
	}; 