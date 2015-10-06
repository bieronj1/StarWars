#include "PlayerShip.hpp"

PlayerShip::PlayerShip(float tlx, float tly, float tft, float tlt, float tr){
		lx=tlx;
		ly=tly;
		vx=0;
		vy=0;
		fthrust = tft;
		lthrust = tlt;
		sthrust= tft;
		trate=tr;
		orientation=0.0;
	}
	
void PlayerShip::update(){
		lx+=vx;
		ly+=vy;
}

void PlayerShip::faster(){
		vx+=fthrust*(std::cos(orientation));
		vy+=fthrust*(std::sin(orientation));
	}
	
void PlayerShip::reverse(){
		vx-=lthrust*(std::cos(orientation));
		vy-=lthrust*(std::sin(orientation));
	}
	
void PlayerShip::slower(){

	if(vy*vy+vx*vx<0.5){
		vx/=1.5;
		vy/=1.5;
			}
	else{
				vx+=-1*sthrust*(vx/std::sqrt(vy*vy+vx*vx));
				vy+=-1*sthrust*(vy/std::sqrt(vy*vy+vx*vx));	
			}
		}
		
void PlayerShip::turnRight(){
				orientation+=trate;
				if(orientation>=2*M_PI)
					orientation-=2*M_PI;
}


void PlayerShip::turnLeft(){
	orientation-=trate;
	if(orientation<0)
		orientation+=2*M_PI;		
}

void PlayerShip::latRight(){
	vx+=fthrust*(std::cos(orientation+M_PI/2));
	vy+=fthrust*(std::sin(orientation+M_PI/2));
}

void PlayerShip::latLeft(){
	vx+=fthrust*(std::cos(orientation-M_PI/2));
	vy+=fthrust*(std::sin(orientation-M_PI/2));
}

void PlayerShip::magicTurn(){
	float speed = std::sqrt(vx*vx+vy*vy);
	vx=speed*std::cos(orientation);
	vy=speed*std::sin(orientation);
}

void PlayerShip::draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        // You can draw other high-level objects
		sf::ConvexShape polygon = body.returnShape();
		polygon.setPosition(lx,ly);
		polygon.rotate(orientation*180/M_PI);
        target.draw(polygon);
    }

/**
*Takes in a new orientation in Radians as the only parameter, and sets the ship to that orientation.
*Useful for non-gameplay situations like the ShipBuilder  
*/
void PlayerShip::setOrientation(float newOrientation){
	orientation = newOrientation; 
}

void PlayerShip::setBody(Body tbody){
	body = tbody;
}