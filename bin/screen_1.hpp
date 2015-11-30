#include <iostream>
//#include "cScreen.hpp"
#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <math.h>
#include <cmath>
#include <vector>

using namespace std;
/*
these are in GridSquare: (p.s. I'll pretty this up later - Jamie)

#include "PlayerShip.hpp"
#include "Weapon.hpp"
#include "CDetect.hpp"
#include "Item.hpp"
#Include "Enemy.hpp"
#include "Asteroid.hpp"

and gridsquare is in GameWorld
*/



static bool QWEASD[6]; //stores keypressed values


class screen_1 : public cScreen
{
private:
    int alpha_max;
    int alpha_div;
    bool playing;
public:
    screen_1(void);
    virtual int Run(sf::RenderWindow &App);
};

screen_1::screen_1(void)
{
    alpha_max = 3 * 255;
    alpha_div = 3;
    playing = false;
}

int screen_1::Run(sf::RenderWindow &App)
{
    sf::Event Event;
    bool Running = true;
    sf::RectangleShape rectangle(sf::Vector2f(90, 40));
    rectangle.setFillColor(sf::Color(255, 202, 54));
    rectangle.setPosition(10,5);
    sf::RectangleShape rectangleBG(sf::Vector2f(280, 40));
    rectangleBG.setFillColor(sf::Color(115, 72, 24));
    rectangleBG.setPosition(10,5);
    //sf::Texture Texture;
    //sf::Sprite Sprite;
    int alpha = 0;
    // create main window
  int FPS=120;
  App.setFramerateLimit(FPS); 

	//taken from SFML official site
  sf::Font font;
	if (!font.loadFromFile("lucon.ttf"))
	{
		std::cout<<"FONT FAILURE"<<std::endl;
	}
  sf::Sprite mmoverlay;
  sf::Texture mmText;
    if (!mmText.loadFromFile("img/mmcover.png"))
    {
        std::cerr << "mmcover.png" << std::endl;
        return (-1);
    }
  mmoverlay.setTexture(mmText);
  mmoverlay.setPosition(0,0);
  sf::Sprite healthOverlay;
  sf::Texture healthText;
    if (!healthText.loadFromFile("img/healthbar.png"))
    {
        std::cerr << "healthbar.png" << std::endl;
        return (-1);
    }
  healthOverlay.setTexture(healthText);
  healthOverlay.setPosition(0,0);
	
	App.clear(sf::Color::Black);
  // start main loop

  //all code above is legacy
	int ActiveAsteroidPtr=0;
	int DeadAsteroidPtr=0;
	Asteroid* Asteroids[512];
	Weapon* Weapons[3];
  
//Test Weapon 0
	Weapon exlaser(0, 2, 2, 5, 0);
  	cout << exlaser.getData(); 
  PlayerShip pc(50,50,0.05,0.05,0.025);
  
  GameWorld world(&pc);

    if (playing)
    {
        alpha = alpha_max;
    }

    while (Running)
    {
        App.clear(sf::Color::Black); //prepare to draw on a clean slate
	  
	 
    // process events
    sf::Event Event;
    while(App.pollEvent(Event))
    {
      // Exit
      if(Event.type == sf::Event::Closed)
	  {App.close();exit(0);}
    }
	
	
	
	//process user input (move to method later)
	QWEASD[0]=sf::Keyboard::isKeyPressed(sf::Keyboard::Q);
	QWEASD[1]=sf::Keyboard::isKeyPressed(sf::Keyboard::W);
	QWEASD[2]=sf::Keyboard::isKeyPressed(sf::Keyboard::E);
	QWEASD[3]=sf::Keyboard::isKeyPressed(sf::Keyboard::A);
	QWEASD[4]=sf::Keyboard::isKeyPressed(sf::Keyboard::S);
	QWEASD[5]=sf::Keyboard::isKeyPressed(sf::Keyboard::D);
	bool SHIFT =sf::Keyboard::isKeyPressed(sf::Keyboard::LShift);
	
	if(QWEASD[1]){pc.faster();}else{pc.stopThruster();}
	if(QWEASD[4]){
		if(SHIFT)
			pc.slower();
		else
			pc.reverse();
	}
	if(QWEASD[3]){pc.turnLeft();}
	if(QWEASD[5]){pc.turnRight();}
	if(QWEASD[0]){pc.latLeft();}else{pc.stopLeft();}
	if(QWEASD[2]){pc.latRight();}else{pc.stopRight();}
	bool zoom = false;
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
		zoom=true;
	}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::T)){
		world.checkLinks();
		std::cout<<"Check Complete"<<std::endl;
	}
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
    	// left click...
		if(exlaser.fire())
			{
				world.addItem(new Item(0, 0, exlaser.spd * cos(pc.orientation)+pc.vx,exlaser.spd * sin(pc.orientation)+pc.vy,3), 600+pc.lx,600+pc.ly);
			}
	}
	App.clear(sf::Color::Black);
	sf::View camera(sf::FloatRect(0,0,1200,800));
    	sf::View minimap(sf::FloatRect(0,0,600,600));
    	sf::View mmOverlay(sf::FloatRect(0,0,300,300));
	sf::View hOverlay(sf::FloatRect(0,0,300,50));
	world.update();
	exlaser.updateCD();
	
	camera.setCenter(1200+pc.lx, 1200+pc.ly);
	
	//camera.move(1250-650+pc.lx,1250-500+pc.ly);
	minimap.move(1250-350+pc.lx,1250-350+pc.ly);
	camera.setRotation((pc.orientation+3.14/2.0)*180.0/M_PI);
	minimap.setRotation((pc.orientation+3.14/2.0)*180.0/M_PI);
	
	if(zoom){
	camera.zoom(5);}
	minimap.zoom(3);
	camera.setViewport(sf::FloatRect(0,0,1,1));
	minimap.setViewport(sf::FloatRect(0.77f,0.6866f,0.21,0.2933));
	mmOverlay.setViewport(sf::FloatRect(0.75f,0.6666f,0.25,0.3333));
	hOverlay.setViewport(sf::FloatRect(0.375f,0.85f,0.25,0.0625));
	App.setView(camera);
		
	world.drawOnWindow(&App);
	
	rectangle.setSize(sf::Vector2f((int)(pc.returnDisplayHealth()*2.8f), 40));
	sf::RectangleShape minimapback(sf::Vector2f(2500,2500));
	minimapback.setFillColor(sf::Color(25,45,25));
	App.setView(minimap);
	App.draw(minimapback);
	world.drawOnWindow(&App);
	App.setView(hOverlay);
	App.draw(rectangleBG);
	App.draw(rectangle);
	App.draw(healthOverlay);
	
	App.setView(mmOverlay);
	App.draw(mmoverlay);
	
	App.display();
    }

    //Never reaching this point normally, but just in case, exit the application
    return (-1);
}
