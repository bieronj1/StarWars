#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <math.h>
#include <cmath>
#include <deque>

class Flipper : public sf::Drawable{
	public:
		int x; int y;
		Flipper(float tx, float ty);
		void changeIndex(int change);
		int getIndex();
		void addToList(std::string added);
		bool getHilighted();
		void setHilighted(bool thilighted);
		std::string returnText();
		sf::Font font;
	  std::deque<std::string> names;
		void next();
		void previous();
		
	private:
		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
		int index;
		bool hilighted;
	};