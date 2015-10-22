#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <math.h>
#include <cmath>
#include <Body.hpp>
#include <Nose.hpp>
#include <Tail.hpp>

class PlayerShip : public sf::Drawable{
  public:
	  float lx;
  	float ly;
		float vx;
 		float vy;
 		float orientation;//0 is straight towards (1.0)
		float fthrust;//forward thrust
		float sthrust;//stopping thrust
		float offx=0;
		float offy=0;
		float lthrust;//lateral thrust
		float trate;//turnrate, in rotations per frame
		
		Body body;
		Nose nose;
		Tail tail;
		
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
		void chooseBody(std::string bodyName);
		void setRenderOffset(float x, float y);
		
		void setTail(Tail ttail);
		void chooseTail(std::string tailName);
		
		void setNose(Nose tnose);
		void chooseNose(std::string noseName);
	private:
		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	
	};