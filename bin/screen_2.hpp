#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <string>
#include <math.h>
#include <fstream>
#include <cmath>
#include "Menu.hpp" 
#include <map>
//#include <cScreen.hpp>



class screen_2 : public cScreen
{
private:
    int alpha_max;
    int alpha_div;
    bool playing;
public:
    screen_2(void);
    virtual int Run(sf::RenderWindow &App);
		std::map<std::string, std::string> loadNoses();
		std::map<std::string, std::string> loadBodies();
		std::map<std::string, std::string> loadTails();
		void saveState(std::string nose, std::string body, std::string tail);
};

std::map<std::string, std::string> screen_2::loadNoses(){
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


std::map<std::string, std::string> screen_2::loadBodies(){
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

std::map<std::string, std::string> screen_2::loadTails(){
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

void screen_2::saveState(std::string nose, std::string body, std::string tail){
	std::ofstream ofs;
	ofs.open("bin/shipState.txt", std::ofstream::out| std::ofstream::trunc);
	ofs << nose; ofs << "\n"; ofs << body; ofs << "\n"; ofs << tail; 
	ofs.close();
}

screen_2::screen_2(void)
{
    alpha_max = 3 * 255;
    alpha_div = 3;
    playing = false;
}

int screen_2::Run(sf::RenderWindow &App){
	  // create main window
	 //  sf::RenderWindow App(sf::VideoMode(1200,800,32), "Astro-Loot");
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

			sf::Text message; message.setFont(font); message.setPosition(100, 350);  message.setString("Press Enter to\n Save and Exit"); message.setColor(sf::Color::White);


		PlayerShip pc(650, 350,0.1,0.05,0.05);
		pc.setOrientation(3* M_PI / 2);

	//Populate flippers

		Flipper noseFlipper(850, 250);
		for(noseIt=noseDict.begin(); noseIt!=noseDict.end(); ++noseIt)
		{
			noseFlipper.addToList(noseIt->first);
		}

		Flipper bodyFlipper(850, 350);
		for(bodyIt=bodyDict.begin(); bodyIt!=bodyDict.end(); ++bodyIt)
		{
			bodyFlipper.addToList(bodyIt->first);
		}


		Flipper tailFlipper(850, 450);
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
					return(0);
				}
	    }





	    // clear screen and fill with blue
	    App.clear(sf::Color::Black);

			pc.update();
			App.draw(menu);
			App.draw(pc);
			App.draw(message);
	    App.display();
	  }

	  // Done.
	  return 0;
}