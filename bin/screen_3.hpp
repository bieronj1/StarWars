#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <string>
#include <math.h>
#include <fstream>
#include <cmath>

#include <map>
//#include <cScreen.hpp>
#include <sstream>
#include <SFML/Audio.hpp>

class screen_3 : public cScreen
{
	public:
		screen_3(void);
		void loadPreviousWinner();
		virtual int Run(sf::RenderWindow &App);
		sf::Font font;
	private:
		int alpha_max;
    int alpha_div;
    bool playing;
		
	};

screen_3::screen_3(void)
{
    alpha_max = 3 * 255;
    alpha_div = 3;
    playing = false;
}

int screen_3::Run(sf::RenderWindow &App)
{
	if (!font.loadFromFile("LemonMilk.otf"))
	{
		std::cout<<"FONT FAILURE"<<std::endl;
	}
	int FPS=60;
	App.setFramerateLimit(FPS);
	
	
	
	sf::Text exitToMenuText; exitToMenuText.setFont(font);
	exitToMenuText.setPosition(400, 725); exitToMenuText.setString("Press Enter to Return to Main Menu");
	exitToMenuText.setColor(sf::Color::Black);
	
	sf::Text previousChampText; previousChampText.setFont(font);
	previousChampText.setPosition(400, 425); previousChampText.setString("The previous Champion was:");
	previousChampText.setColor(sf::Color::Black);
	
	while(App.isOpen())
	{
		sf::Event Event;
    while(App.pollEvent(Event))
    {
		if((Event.type == sf::Event::KeyPressed) && (Event.key.code == sf::Keyboard::Return)){
			return(0);
		}
	  }
	  
	
	App.clear(sf::Color::White);
	App.draw(previousChampText);
	App.draw(exitToMenuText);
	App.display();
	}
	return(-1);
	
	

}