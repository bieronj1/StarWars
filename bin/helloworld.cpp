#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <string>
#include <math.h>
#include <cmath>
#include "PlayerShip.hpp"
#include "Flipper.hpp"

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
	Flipper bodyFlipper(400, 400);
	bodyFlipper.addToList("Red");
	
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
    }

    // clear screen and fill with blue
    App.clear(sf::Color::Black);

		pc.update();
		App.draw(bodyFlipper); 
		App.draw(pc);
    App.display();
  }

  // Done.
  return 0;
}
