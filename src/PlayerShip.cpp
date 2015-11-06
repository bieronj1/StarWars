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
		
		if(!texture.loadFromFile("Thruster.png")){
			std::cerr<<"Couldn't load the thruster image\n";
		}
		
		if(!lefttexture.loadFromFile("LeftThruster.png")){
			std::cerr<<"Couldn't load the thruster image\n";
		}
		if(!righttexture.loadFromFile("RightThruster.png")){
			std::cerr<<"Couldn't load the thruster image\n";
		}
		
		Body defaultBody("default");
		defaultBody.setColor(sf::Color::Blue);
		setBody(defaultBody);
		Nose defaultNose("default");
		defaultNose.setColor(sf::Color::White);
		setNose(defaultNose);
		
		Tail defaultTail("default");
		defaultTail.setColor(sf::Color::Red);
		setTail(defaultTail);
		thrustersOn = false;
		leftOn = false;
		rightOn = false;
	}
	
void PlayerShip::update(){
		lx+=vx;
		ly+=vy;
}

void PlayerShip::faster(){
		vx+=fthrust*(std::cos(orientation));
		vy+=fthrust*(std::sin(orientation));
		thrustersOn = true;
	}
	
void PlayerShip::stopThruster(){
	thrustersOn = false;
}

void PlayerShip::stopLeft(){
	rightOn = false;
}
void PlayerShip::stopRight(){
	leftOn = false;
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
	leftOn = true;
}

void PlayerShip::latLeft(){
	vx+=fthrust*(std::cos(orientation-M_PI/2));
	vy+=fthrust*(std::sin(orientation-M_PI/2));
	rightOn = true;
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

		nosePolygon.setOrigin(-20, 0);

		nosePolygon.setPosition(lx + offx,ly + offy);
		nosePolygon.rotate(orientation*180/M_PI);
		target.draw(nosePolygon);
		
		
		
		sf::ConvexShape lefttailPolygon = tail.returnLeftShape();
		
		lefttailPolygon.setOrigin(17,13);
		lefttailPolygon.setPosition(lx + offx, ly +offy);
		lefttailPolygon.rotate(orientation*180/M_PI);
		target.draw(lefttailPolygon);
		
		
		sf::ConvexShape righttailPolygon = tail.returnRightShape();
		
		righttailPolygon.setOrigin(13,-11);
		righttailPolygon.setPosition(lx  +offx, ly +offy);
		righttailPolygon.rotate(orientation*180/M_PI);
		target.draw(righttailPolygon);
		
		
		if(thrustersOn){
			sf::RectangleShape thrusterRectangle;
			thrusterRectangle.setSize(sf::Vector2f(15,15));

			thrusterRectangle.setTexture(&texture);
			
			thrusterRectangle.setOrigin(30,8);
			thrusterRectangle.setPosition(lx+offx, ly+offy);
			thrusterRectangle.rotate(orientation*180/M_PI);
			target.draw(thrusterRectangle);
		}
		
		if(leftOn){
			sf::RectangleShape leftRectangle;
			leftRectangle.setSize(sf::Vector2f(15,15));
			
			leftRectangle.setTexture(&lefttexture);
			leftRectangle.setOrigin(0, 24);
			leftRectangle.setPosition(lx+offx, ly+offy);
			leftRectangle.rotate(orientation*180/M_PI);
			target.draw(leftRectangle);
		}
		
		if(rightOn){
			sf::RectangleShape rightRectangle;
			rightRectangle.setSize(sf::Vector2f(15,15));
			
			rightRectangle.setTexture(&righttexture);
			rightRectangle.setOrigin(0, -10);
			rightRectangle.setPosition(lx+offx, ly+offy);
			rightRectangle.rotate(orientation*180/M_PI);
			target.draw(rightRectangle);
		}
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