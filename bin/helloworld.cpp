#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <string>
#include <math.h>
#include <cmath>
#include "PlayerShip.hpp"
#include "Menu.hpp" 


static bool QWEASD[6];

int main(int argc, char** argv)
{
  // create main window
  sf::RenderWindow App(sf::VideoMode(800,600,32), "Astro-Loot");
	int FPS=60;
	App.setFramerateLimit(FPS);
	sf::Font font;
	if (!font.loadFromFile("lucon.ttf"))
	{
		std::cout<<"FONT FAILURE"<<std::endl;
	}
	
	
	PlayerShip pc(200, 300,0.1,0.05,0.05);
	Body green("default");
	pc.setBody(green);
	pc.setOrientation(3* M_PI / 2);
	Flipper noseFlipper(450, 150);
	Flipper bodyFlipper(450, 250);
	Flipper tailFlipper(450, 350);
	tailFlipper.addToList("Red"); tailFlipper.addToList("White"); tailFlipper.addToList("Blue");
	noseFlipper.addToList("Red"); noseFlipper.addToList("White"); noseFlipper.addToList("Blue"); 
	bodyFlipper.addToList("Red"); bodyFlipper.addToList("White"); bodyFlipper.addToList("Blue");
	
	Menu menu;
	menu.addFlipper(noseFlipper); 	menu.addFlipper(bodyFlipper); menu.addFlipper(tailFlipper);
	pc.chooseNose(menu.flippers.at(0).returnText());
	pc.chooseBody(menu.flippers.at(1).returnText());
	pc.chooseTail(menu.flippers.at(2).returnText());
	
  // start main loop
  while(App.isOpen())
  {
    // process events
    sf::Event Event;
    while(App.pollEvent(Event))
    {
      // Exit
      if(Event.type == sf::Event::Closed)
        App.close();

	    if((Event.type == sf::Event::KeyPressed) && (Event.key.code == sf::Keyboard::Down)){
				menu.next();
	    }
			if((Event.type == sf::Event::KeyPressed) && (Event.key.code == sf::Keyboard::Up)){
				menu.previous();
			}
			if((Event.type == sf::Event::KeyPressed) && (Event.key.code == sf::Keyboard::Left)){
				menu.flipperPrevious();
				pc.chooseBody(menu.flippers.at(1).returnText());
				pc.chooseNose(menu.flippers.at(0).returnText());
				pc.chooseTail(menu.flippers.at(2).returnText());
			}
			if((Event.type == sf::Event::KeyPressed) && (Event.key.code == sf::Keyboard::Right)){
				menu.flipperNext();
				pc.chooseBody(menu.flippers.at(1).returnText());
				pc.chooseNose(menu.flippers.at(0).returnText());
				pc.chooseTail(menu.flippers.at(2).returnText());
			}
    }





    // clear screen and fill with blue
    App.clear(sf::Color::Black);
  
		pc.update();
		App.draw(menu);
		App.draw(pc);
    App.display();
  }

  // Done.
  return 0;
}
