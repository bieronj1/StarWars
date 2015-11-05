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
		Body defaultBody("default");
		defaultBody.setColor(sf::Color::Green);
		setBody(defaultBody);
		Nose defaultNose("default");
		defaultNose.setColor(sf::Color::White);
		setNose(defaultNose);
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
	
void PlayerShip::chooseNose(std::string noseName){
	std::cerr << noseName;
	std::cerr << "\n";
	if(!noseName.compare("Red")){
		Nose red("Red");
		red.setColor(sf::Color::Red);
		setNose(red);
	}else if(!noseName.compare("White")){
		Nose white("White");
		white.setColor(sf::Color::White);
		setNose(white);
	}else if(!noseName.compare("Blue")){
		Nose blue("Blue");
		blue.setColor(sf::Color::Blue);
		setNose(blue);
	}
}
	
void PlayerShip::chooseBody(std::string bodyName){

	if(!bodyName.compare("Red")){
		Body red("Red");
		red.setColor(sf::Color::Red);
		setBody(red);
	}else if(!bodyName.compare("White")){
		Body white("White");
		white.setColor(sf::Color::White);
		setBody(white);
	}else if(!bodyName.compare("Blue")){
		Body blue("Blue");
		blue.setColor(sf::Color::Blue);
		setBody(blue);
	}
}

void PlayerShip::chooseTail(std::string tailName){

	if(!tailName.compare("Red")){
		Tail red("Red");
		red.setColor(sf::Color::Red);
		setTail(red);
	}else if(!tailName.compare("White")){
		Tail white("White");
		white.setColor(sf::Color::White);
		setTail(white);
	}else if(!tailName.compare("Blue")){
		Tail blue("Blue");
		blue.setColor(sf::Color::Blue);
		setTail(blue);
	}
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

void PlayerShip::setRenderOffset(float x, float y){
	offx=x;
	offy=y;
}
void PlayerShip::draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        // You can draw other high-level objects
		sf::ConvexShape bodyPolygon = body.returnShape();
		bodyPolygon.setPosition(offx+ lx, offy + ly);
		bodyPolygon.rotate(orientation*180/M_PI);
    target.draw(bodyPolygon);

		sf::ConvexShape nosePolygon = nose.returnShape();

		nosePolygon.setOrigin(offx, offy);

	//	nosePolygon.setPosition(lx,ly);
		nosePolygon.rotate(orientation*180/M_PI);
		target.draw(nosePolygon);
		
		sf::ConvexShape lefttailPolygon = tail.returnLeftShape();
		lefttailPolygon.setPosition(lx -13, ly +17);
		lefttailPolygon.rotate(orientation*180/M_PI);
		target.draw(lefttailPolygon);
		
		sf::ConvexShape righttailPolygon = tail.returnRightShape();
		righttailPolygon.setPosition(lx  +11, ly +13);
		righttailPolygon.rotate(orientation*180/M_PI);
		target.draw(righttailPolygon);
    }

/**
*Takes in a new orientation in Radians as the only parameter, and sets the ship to that orientation.
*Useful for non-gameplay situations like the ShipBuilder  
*/
void PlayerShip::setOrientation(float newOrientation){
	orientation = newOrientation; 
}

void PlayerShip::setTail(Tail ttail){
	tail = ttail;
}

void PlayerShip::setBody(Body tbody){
	body = tbody;
}

void PlayerShip::setNose(Nose tnose){
	nose = tnose;
}