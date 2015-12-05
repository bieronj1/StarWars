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
		virtual int Run(sf::RenderWindow &App);
		sf::Font font;
		std::string mode;
		std::string score;
		void compareHighAndCurrent(std::string highScore, std::string current);
		void loadModeAndScore();
		void addUpgradePoints(std::string score);
		int str2int(string &str);
	private:
		int alpha_max;
    int alpha_div;
    bool playing;
		
	};
	
	
int screen_3::str2int (string &str) {

  stringstream ss(str);
  int num;
  if((ss >> num).fail())
  { 
      //ERROR 
  }
  return num;
}

void screen_3::addUpgradePoints(std::string score){
  int currentScore = str2int(score);
  std::ifstream ifs("bin/upt.txt");
  std::string line;
  getline(ifs, line);
  ifs.close();
  int total = str2int(line);
  total = total + currentScore;
  std::ofstream ofs("bin/upt.txt", std::ofstream::out| std::ofstream::trunc);
  ofs<<total;
  
}
	

void screen_3::compareHighAndCurrent(std::string highScore, std::string current){
    int intHighScore = str2int(highScore);
    int intCurrent = str2int(current);
    if(intCurrent > intHighScore)
    {
      	std::ofstream ofs;
	ofs.open("bin/championState.txt", std::ofstream::out| std::ofstream::trunc);
	std::ifstream ifs("bin/shipState.txt");
	std::string line;
	while(getline(ifs, line)){
	  ofs<<line<<"\n";
	}
	ofs<<current;
	ofs.close();
	ifs.close();
    }
}

	
void screen_3::loadModeAndScore(){
  std::ifstream myfile("bin/modeAndScore.txt");
  std::string line;
	if(!myfile.is_open())
	{
		std::cerr<<"Could not open the mode and score file\n";
	}
	getline(myfile, line);
	mode = line;
	getline(myfile, line);
	score = line;
  
  
}




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
	
	loadModeAndScore();
	
	PlayerShip pc(450, 575,0.1,0.05,0.05);
	pc.loadFromFileScored();
	pc.setOrientation(3* M_PI / 2);
	
	compareHighAndCurrent(pc.score, score);
	addUpgradePoints(score);

	sf::Text pcscore; pcscore.setFont(font);
 	pcscore.setPosition(700, 575); pcscore.setString(pc.score);
	pcscore.setColor(sf::Color::Black);
	
	sf::Text victoryText; victoryText.setFont(font);
	victoryText.setPosition(350, 225); victoryText.setString("Your Score was:  ");
	victoryText.setColor(sf::Color::Black);
	
	
	sf::Text playerScore; playerScore.setFont(font);
	playerScore.setPosition(700, 225); playerScore.setString(score);
	playerScore.setColor(sf::Color::Black);
	
	
	sf::Text exitToMenuText; exitToMenuText.setFont(font);
	exitToMenuText.setPosition(350, 725); exitToMenuText.setString("Press Enter to Return to Main Menu");
	exitToMenuText.setColor(sf::Color::Black);
	
	sf::Text previousChampText; previousChampText.setFont(font);
	previousChampText.setPosition(350, 425); previousChampText.setString("The previous Champion was:");
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
	App.draw(victoryText);

	App.draw(previousChampText);
	App.draw(exitToMenuText);
	App.draw(playerScore);
	App.draw(pc);
	App.draw(pcscore);
	App.display();
	}
	return(-1);
	
	

}