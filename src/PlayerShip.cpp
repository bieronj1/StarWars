#include "PlayerShip.hpp"


std::vector<std::string> &split(const std::string &s, char delim, std::vector<std::string> &elems) {
    std::stringstream ss(s);
    std::string item;
    while (std::getline(ss, item, delim)) {
        elems.push_back(item);
    }
    return elems;
}


std::vector<std::string> split(const std::string &s, char delim) {
    std::vector<std::string> elems;
    split(s, delim, elems);
    return elems;
}

void PlayerShip::loadFromFile(){
	std::ifstream myfile("bin/shipState.txt");
	std::string line;
	if(!myfile.is_open())
	{
		std::cerr<<"Could not open the playership file\n";
	}
	getline (myfile, line);
	chooseNose(line);
	
	getline(myfile, line);
	chooseBody(line);	
	
	getline(myfile, line);
	chooseTail(line);

	
}

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
		
		if(!texture.loadFromFile("img/thruster0.png")){
			std::cerr<<"Couldn't load the thruster image\n";
		}
		
		if(!lefttexture.loadFromFile("img/thruster1.png")){
			std::cerr<<"Couldn't load the thruster image\n";
		}
		if(!righttexture.loadFromFile("img/thruster2.png")){
			std::cerr<<"Couldn't load the thruster image\n";
		}
		
		loadFromFile();

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
	
void PlayerShip::chooseNose(std::string line){
  std::vector<std::string> splitLine = split(line, ',');
	Nose nose(splitLine.at(0));
	sf::Color noseColor(std::atoi(splitLine.at(1).c_str()), 
	  std::atoi(splitLine.at(2).c_str()), std::atoi(splitLine.at(3).c_str()));
	nose.setColor(noseColor);
	setNose(nose);
}
	
void PlayerShip::chooseBody(std::string line){
	std::vector<std::string> splitLine = split(line, ',');
	Body body(splitLine.at(0));
	sf::Color bodyColor(std::atoi(splitLine.at(1).c_str()), 
	  std::atoi(splitLine.at(2).c_str()), std::atoi(splitLine.at(3).c_str()));
	body.setColor(bodyColor);
	setBody(body);
}

void PlayerShip::chooseTail(std::string line){

	std::vector<std::string> splitLine = split(line, ',');
	Tail tail(splitLine.at(0));
	sf::Color tailColor(std::atoi(splitLine.at(1).c_str()), 
	  std::atoi(splitLine.at(2).c_str()), std::atoi(splitLine.at(3).c_str()));
	tail.setColor(tailColor);
	setTail(tail);
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
		sf::RectangleShape bodyPolygon = body.returnShape();
		bodyPolygon.setOrigin(27.5, 13.5);
		bodyPolygon.setPosition(offx+ lx, offy + ly);
		bodyPolygon.rotate(orientation*180/M_PI);
    target.draw(bodyPolygon);

		sf::RectangleShape nosePolygon = nose.returnShape();

		nosePolygon.setOrigin(nose.getXOffset(), nose.getYOffset());

		nosePolygon.setPosition(lx + offx,ly + offy);
		nosePolygon.setOrigin(27.5, 13.5);
		nosePolygon.rotate(orientation*180/M_PI);
		target.draw(nosePolygon);
		
		
		
		sf::RectangleShape tailPolygon = tail.returnShape();
		tailPolygon.setOrigin(27.5, 13.5);
		tailPolygon.setPosition(lx + offx,ly + offy);
		tailPolygon.rotate(orientation*180/M_PI);
		target.draw(tailPolygon);
		
/*
		sf::CircleShape centerpoint;
		centerpoint.setOrigin(2,2);
		centerpoint.setPosition(offx+lx,offy+ly);
		centerpoint.setRadius(2);
		centerpoint.setFillColor(sf::Color::White);
		target.draw(centerpoint);
*/		
		
		
		
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
			leftRectangle.setOrigin(0, 22);
			leftRectangle.setPosition(lx+offx, ly+offy);
			leftRectangle.rotate(orientation*180/M_PI);
			target.draw(leftRectangle);
		}
		
		if(rightOn){
			sf::RectangleShape rightRectangle;
			rightRectangle.setSize(sf::Vector2f(15,15));
			
			rightRectangle.setTexture(&righttexture);
			rightRectangle.setOrigin(0, -8);
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
