#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <math.h>
#include <cmath>
#include <Body.hpp>

class PlayerShip : public sf::Drawable{
  public:
	  float lx;
  	float ly;
		float vx;
 		float vy;
 		float orientation;//0 is straight towards (1.0)
		float fthrust;//forward thrust
		float sthrust;//stopping thrust
		float lthrust;//lateral thrust
		float trate;//turnrate, in rotations per frame
		
		Body body;
		
		PlayerShip(float tlx, float tly, float tft, float tlt, float tr);
		void update();
		void faster();
		void reverse();
		void slower();
		void turnRight();
		void turnLeft();
		void latRight();
		void latLeft();
		void magicTurn();
		void setOrientation(float newOrientation); 
		void setBody(Body tbody);
	private:
		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	
	};