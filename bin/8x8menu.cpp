#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <string>
#include <math.h>
#include <fstream>
#include <cmath>
#include "Menu.hpp" 
#include <map>

static bool QWEASD[6];



void saveState(std::string one, std::string two,std::string three,std::string four,std::string five,std::string six,std::string seven,std::string eight){
	std::ofstream ofs;
	ofs.open("bin/upgradeState.txt", std::ofstream::out| std::ofstream::trunc);
	ofs << one; ofs << "\n"; ofs << two; ofs << "\n"; ofs << three; ofs << "\n";
	ofs << four; ofs << "\n"; ofs << five; ofs << "\n"; ofs << six; ofs << "\n";
	ofs << seven; ofs << "\n"; ofs << eight; 
	ofs.close();
}



int main(int argc, char** argv)
{
  // create main window
  sf::RenderWindow App(sf::VideoMode(1200,800,32), "Astro-Loot");
	int FPS=60;
	App.setFramerateLimit(FPS);
	sf::Font font;
	if (!font.loadFromFile("lucon.ttf"))
	{
		std::cout<<"FONT FAILURE"<<std::endl;
	}
	
	


//Populate flippers
	
	sf::Text Flipper1Text; Flipper1Text.setFont(font); Flipper1Text.setPosition(650, 25); Flipper1Text.setString("a"); Flipper1Text.setColor(sf::Color::White);
	Flipper Flipper1(1000, 25);
	Flipper1.addToList("1");Flipper1.addToList("2");Flipper1.addToList("3");Flipper1.addToList("4");Flipper1.addToList("5");


  sf::Text Flipper2Text; Flipper2Text.setFont(font); Flipper2Text.setPosition(650, 125); Flipper2Text.setString("b");Flipper2Text.setColor(sf::Color::White);
	Flipper Flipper2(1000, 125);
	Flipper2.addToList("1");Flipper2.addToList("2");Flipper2.addToList("3");Flipper2.addToList("4");Flipper2.addToList("5");


  sf::Text Flipper3Text; Flipper3Text.setFont(font); Flipper3Text.setPosition(650, 225); Flipper3Text.setString("c");Flipper3Text.setColor(sf::Color::White);
	Flipper Flipper3(1000, 225);
	Flipper3.addToList("1");Flipper3.addToList("2");Flipper3.addToList("3");Flipper3.addToList("4");Flipper3.addToList("5");


  sf::Text Flipper4Text; Flipper4Text.setFont(font); Flipper4Text.setPosition(650, 325); Flipper4Text.setString("d");Flipper4Text.setColor(sf::Color::White);
	Flipper Flipper4(1000, 325);
	Flipper4.addToList("1");Flipper4.addToList("2");Flipper4.addToList("3");Flipper4.addToList("4");Flipper4.addToList("5");
		
	sf::Text Flipper5Text; Flipper5Text.setFont(font); Flipper5Text.setPosition(650, 425); Flipper5Text.setString("e");Flipper5Text.setColor(sf::Color::White);
	Flipper Flipper5(1000, 425);
	Flipper5.addToList("1");Flipper5.addToList("2");Flipper5.addToList("3");Flipper5.addToList("4");Flipper5.addToList("5");
	
	sf::Text Flipper6Text; Flipper6Text.setFont(font); Flipper6Text.setPosition(650, 525); Flipper6Text.setString("f");Flipper6Text.setColor(sf::Color::White);
	Flipper Flipper6(1000, 525);
	Flipper6.addToList("1");Flipper6.addToList("2");Flipper6.addToList("3");Flipper6.addToList("4");Flipper6.addToList("5");
	
	sf::Text Flipper7Text; Flipper7Text.setFont(font); Flipper7Text.setPosition(650, 625); Flipper7Text.setString("g");Flipper7Text.setColor(sf::Color::White);
	Flipper Flipper7(1000, 625);
	Flipper7.addToList("1");Flipper7.addToList("2");Flipper7.addToList("3");Flipper7.addToList("4");Flipper7.addToList("5");
	
	
	sf::Text Flipper8Text; Flipper8Text.setFont(font); Flipper8Text.setPosition(650, 725); Flipper8Text.setString("h");Flipper8Text.setColor(sf::Color::White);
	Flipper Flipper8(1000, 725); 
	Flipper8.addToList("1");Flipper8.addToList("2");Flipper8.addToList("3");Flipper8.addToList("4");Flipper8.addToList("5");
	
	sf::Text message; message.setFont(font); message.setPosition(100, 400);  message.setString("Press Enter to\n Save and Exit"); message.setColor(sf::Color::White);
	Menu menu;
	menu.addFlipper(Flipper1); 	menu.addFlipper(Flipper2); menu.addFlipper(Flipper3); menu.addFlipper(Flipper4);
	menu.addFlipper(Flipper5); 	menu.addFlipper(Flipper6); menu.addFlipper(Flipper7); menu.addFlipper(Flipper8);
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

			}
			if((Event.type == sf::Event::KeyPressed) && (Event.key.code == sf::Keyboard::Right)){
				menu.flipperNext();

			}
			if((Event.type == sf::Event::KeyPressed) && (Event.key.code == sf::Keyboard::Return)){
//save method goes here
				saveState(menu.flippers.at(0).returnText(), menu.flippers.at(1).returnText(), menu.flippers.at(2).returnText(),
				menu.flippers.at(3).returnText(), menu.flippers.at(4).returnText(), menu.flippers.at(5).returnText(),
				menu.flippers.at(6).returnText(), menu.flippers.at(7).returnText());
			}
    }





    // clear screen and fill with blue
    App.clear(sf::Color::Black);

		App.draw(menu);
		App.draw(Flipper1Text);App.draw(Flipper2Text);App.draw(Flipper3Text);App.draw(Flipper4Text);
		App.draw(Flipper5Text);App.draw(Flipper6Text);App.draw(Flipper7Text);App.draw(Flipper8Text);
		App.draw(message);
    App.display();
  }

  // Done.
  return 0;
}