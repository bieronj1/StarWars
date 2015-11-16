#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <string>
#include <math.h>
#include <fstream>
#include <cmath>
#include "PlayerShip.hpp"
#include "Menu.hpp" 
#include <map>


static bool QWEASD[6];

std::map<std::string, std::string> loadNoses(){
	std::map<std::string, std::string> dict;
	std::ifstream myfile("bin/noses.txt");
	std::string line;
	if(!myfile.is_open())
	{
		std::cerr<<"Could not open the noses file\n";
	}
	while(getline(myfile, line))
	{
		std::size_t found = line.find_first_of(",");
		std::string name = line.substr(0, found);
		dict.insert(std::pair<std::string, std::string> (name, line));	
	}
	myfile.close();
	return dict;
	
}


std::map<std::string, std::string> loadBodies(){
		std::map<std::string, std::string> dict;
		std::ifstream myfile("bin/bodies.txt");
		std::string line;
		if(!myfile.is_open())
		{
			std::cerr<<"Could not open the bodies file\n";
		}
		while(getline(myfile, line))
		{
			std::size_t found = line.find_first_of(",");
			std::string name = line.substr(0, found);
			dict.insert(std::pair<std::string, std::string> (name, line));	
		}
		myfile.close();
		return dict;
	
}

std::map<std::string, std::string> loadTails(){
	std::map<std::string, std::string> dict;
	std::ifstream myfile("bin/tails.txt");
	std::string line;
	if(!myfile.is_open())
	{
		std::cerr<<"Could not open the tails file\n";
	}
	while(getline(myfile, line))
	{
		std::size_t found = line.find_first_of(",");
		std::string name = line.substr(0, found);
		dict.insert(std::pair<std::string, std::string> (name, line));	
	}
	myfile.close();
	return dict;
}

void saveState(std::string nose, std::string body, std::string tail){
	std::ofstream ofs;
	ofs.open("bin/shipState.txt", std::ofstream::out| std::ofstream::trunc);
	ofs << nose; ofs << "\n"; ofs << body; ofs << "\n"; ofs << tail; 
	ofs.close();
}

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
	
	
//Sets up dictionairies and iterators
	std::map<std::string, std::string> noseDict = loadNoses();
	std::map<std::string, std::string>::iterator noseIt = noseDict.begin();
	
	std::map<std::string, std::string> bodyDict = loadBodies();
	std::map<std::string, std::string>::iterator  bodyIt = bodyDict.begin();
	
	std::map<std::string, std::string> tailDict = loadTails();
	std::map<std::string, std::string>::iterator  tailIt = tailDict.begin();
	
	
	
	
	PlayerShip pc(200, 300,0.1,0.05,0.05);
	pc.setOrientation(3* M_PI / 2);

//Populate flippers
	
	Flipper noseFlipper(450, 150);
	for(noseIt=noseDict.begin(); noseIt!=noseDict.end(); ++noseIt)
	{
		noseFlipper.addToList(noseIt->first);
	}

	Flipper bodyFlipper(450, 250);
	for(bodyIt=bodyDict.begin(); bodyIt!=bodyDict.end(); ++bodyIt)
	{
		bodyFlipper.addToList(bodyIt->first);
	}
	
	
	Flipper tailFlipper(450, 350);
	for(tailIt=tailDict.begin(); tailIt!=tailDict.end(); ++tailIt)
	{
		tailFlipper.addToList(tailIt->first);
	}
	 
	
	
	
	Menu menu;
	menu.addFlipper(noseFlipper); 	menu.addFlipper(bodyFlipper); menu.addFlipper(tailFlipper);
	pc.chooseNose(noseDict.at(menu.flippers.at(0).returnText()));
	pc.chooseBody(bodyDict.at(menu.flippers.at(1).returnText()));
	pc.chooseTail(tailDict.at(menu.flippers.at(2).returnText()));
	
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
				pc.chooseBody(bodyDict.at(menu.flippers.at(1).returnText()));
				pc.chooseNose(noseDict.at(menu.flippers.at(0).returnText()));
				pc.chooseTail(tailDict.at(menu.flippers.at(2).returnText()));
			}
			if((Event.type == sf::Event::KeyPressed) && (Event.key.code == sf::Keyboard::Right)){
				menu.flipperNext();
				pc.chooseBody(bodyDict.at(menu.flippers.at(1).returnText()));
				pc.chooseNose(noseDict.at(menu.flippers.at(0).returnText()));
				pc.chooseTail(tailDict.at(menu.flippers.at(2).returnText()));
			}
			if((Event.type == sf::Event::KeyPressed) && (Event.key.code == sf::Keyboard::Return)){
				saveState(noseDict.at(menu.flippers.at(0).returnText()), bodyDict.at(menu.flippers.at(1).returnText()), 
					tailDict.at(menu.flippers.at(2).returnText()));
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
