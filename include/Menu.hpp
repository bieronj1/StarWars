#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <math.h>
#include <cmath>
#include <deque>
#include "Flipper.hpp"

class Menu : public sf::Drawable{ 
	public:
		Menu();
		void next();
		void previous();
		void flipperNext();
		void flipperPrevious();
		void addFlipper(Flipper f);
		Flipper currentFlipper();
		std::deque<Flipper> flippers;
	private:
		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
		int currentIndex;
		
		
		
	};