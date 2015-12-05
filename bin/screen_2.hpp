#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <string>
#include <math.h>
#include <fstream>
#include <cmath>
#include "Menu.hpp" 
#include <map>
//#include <cScreen.hpp>
#include <sstream>
#include <SFML/Audio.hpp>

#define SSTR( x ) dynamic_cast< std::ostringstream & >( \
        ( std::ostringstream() << std::dec << x ) ).str()



class screen_2 : public cScreen
{
private:
    int alpha_max;
    int alpha_div;
    bool playing;
    sf::Texture expText [6];
    sf::Sprite expSprite [10];
    sf::Sprite upSprite [10];
    int stats [10];
    int costs [6] = {100, 150, 200, 250, 300, 0};
    string costSTR [6] = {"100 UP", "150 UP", "200 UP", "250 UP", "300 UP", "MAX LEVEL"};
    int totalPT = 0;
    sf::Text upString[10];
	
public:
    screen_2(void);
    virtual int Run(sf::RenderWindow &App);
    std::string loadx();
    void loadstats();
		int str2int (const string &str);
		string IntToString (int a);
		std::map<std::string, std::string> loadNoses();
		std::map<std::string, std::string> loadBodies();
		std::map<std::string, std::string> loadTails();
		void saveState(std::string nose, std::string body, std::string tail);
		void saveStats();
		void savePoints();
		bool mouseOnSprite(sf::Sprite &av_Sprite, sf::RenderWindow &av_Window);
};


string screen_2::IntToString (int a)
{
    ostringstream temp;
    temp<<a;
    return temp.str();
}

bool screen_2::mouseOnSprite(sf::Sprite &av_Sprite, sf::RenderWindow &av_Window)
{
      
    int mouseX = sf::Mouse::getPosition().x;
    int mouseY = sf::Mouse::getPosition().y;
      
    sf::Vector2i windowPosition = av_Window.getPosition();
  
    if(mouseX > av_Sprite.getPosition().x + windowPosition.x && mouseX < ( av_Sprite.getPosition().x + av_Sprite.getGlobalBounds().width + windowPosition.x)
        && mouseY > av_Sprite.getPosition().y + windowPosition.y + 30  && mouseY < ( av_Sprite.getPosition().y + av_Sprite.getGlobalBounds().height + windowPosition.y + 30) )
    {
        if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            return true;
        }
        return false;
    }
      
    return false;
  
}



int screen_2::str2int (const string &str) {
  stringstream ss(str);
  int num;
  if((ss >> num).fail())
  { 
      //ERROR 
  }
  return num;
}

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

std::string screen_2::loadx(){
	string points;
	std::ifstream myfile("bin/upt.txt");
	std::string line;
	std::string::size_type sz;   // alias of size_t

	if(!myfile.is_open())
	{
		std::cerr<<"Could not open the points file\n";
	}
	if(getline(myfile, line))
    		points = (line);
	myfile.close();
	totalPT = str2int(points);
	return points;
	
}

void screen_2::loadstats(){
	string points;
	std::ifstream myfile("bin/stat.txt");
	std::string line;
	std::string::size_type sz;   // alias of size_t

	if(!myfile.is_open())
	{
		std::cerr<<"Could not open the stats file\n";
	}
	int place = 0;
	while(getline(myfile, line))
		{
			stats[place] = str2int(line);
			place++;
		}
	myfile.close();
	
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

void screen_2::saveStats(){
	std::ofstream ofs;
	ofs.open("bin/stat.txt", std::ofstream::out| std::ofstream::trunc);
	for (int i=0; i<10; i++)
	{
	ofs << stats[i]; ofs << "\n";
	}
	ofs.close();
}
void screen_2::savePoints(){
	std::ofstream ofs;
	ofs.open("bin/upt.txt", std::ofstream::out| std::ofstream::trunc);
	ofs << totalPT; ofs << "\n";
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
		if (!font.loadFromFile("LemonMilk.otf"))
		{
			std::cout<<"FONT FAILURE"<<std::endl;
		}
		
		if (!expText[0].loadFromFile("img/exp0.png"))
    		{
        	std::cerr << "exp0.png" << std::endl;
        	return (-1);
    		}
		if (!expText[1].loadFromFile("img/exp1.png"))
    		{
        	std::cerr << "exp1.png" << std::endl;
        	return (-1);
    		}
		if (!expText[2].loadFromFile("img/exp2.png"))
    		{
        	std::cerr << "exp2.png" << std::endl;
        	return (-1);
    		}
		if (!expText[3].loadFromFile("img/exp3.png"))
    		{
        	std::cerr << "exp3.png" << std::endl;
        	return (-1);
    		}
		if (!expText[4].loadFromFile("img/exp4.png"))
    		{
        	std::cerr << "exp4.png" << std::endl;
        	return (-1);
    		}
		if (!expText[5].loadFromFile("img/exp5.png"))
    		{
        	std::cerr << "exp5.png" << std::endl;
        	return (-1);
    		}

		sf::Texture tMain;
    		sf::Sprite sMain;
    		if (!tMain.loadFromFile("img/returnmain.png"))
    		{
        		std::cerr << "returnmain.png" << std::endl;
        		return (-1);
    		}
		sf::Sprite shipBG;
		sf::Texture shipBuild;
    		if (!shipBuild.loadFromFile("img/shipbg.png"))
    		{
        		std::cerr << "upbutton.png" << std::endl;
        		return (-1);
    		}
		shipBG.setTexture(shipBuild);
		shipBG.setPosition(895,280);
		sf::Texture uOn;
    		if (!uOn.loadFromFile("img/upbutton.png"))
    		{
        		std::cerr << "upbutton.png" << std::endl;
        		return (-1);
    		}
		sf::Texture uOff;
    		if (!uOff.loadFromFile("img/upbuttonx.png"))
    		{
        		std::cerr << "upbuttonx.png" << std::endl;
        		return (-1);
    		}
		sf::Text points; 
		points.setFont(font);
		points.setCharacterSize(45);
		points.setPosition(80, 50); 
		std::string thepoints = loadx();
		points.setString(thepoints + " UPGRADE POINTS"); 
		loadstats();
	//Setting up sprites for exp bar
		expSprite[0].setTexture(expText[stats[0]]);
    		expSprite[0].setPosition(410,221);	
		upSprite[0].setPosition(620,220);
		upString[0].setPosition(660,218);
		expSprite[1].setTexture(expText[stats[1]]);
    		expSprite[1].setPosition(410,251);
		upSprite[1].setPosition(620,250);
		upString[1].setPosition(660,248);
		expSprite[2].setTexture(expText[stats[2]]);
    		expSprite[2].setPosition(410,281);
		upSprite[2].setPosition(620,280);
		upString[2].setPosition(660,278);	
		expSprite[3].setTexture(expText[stats[3]]);
    		expSprite[3].setPosition(410,361);
		upSprite[3].setPosition(620,360);
		upString[3].setPosition(660,358);
		expSprite[4].setTexture(expText[stats[4]]);
    		expSprite[4].setPosition(410,391);
		upSprite[4].setPosition(620,390);
		upString[4].setPosition(660,388);	
		expSprite[5].setTexture(expText[stats[5]]);
    		expSprite[5].setPosition(410,421);
		upSprite[5].setPosition(620,420);
		upString[5].setPosition(660,418);
		expSprite[6].setTexture(expText[stats[6]]);
    		expSprite[6].setPosition(410,521);
		upSprite[6].setPosition(620,520);
		upString[6].setPosition(660,518);	
		expSprite[7].setTexture(expText[stats[7]]);
    		expSprite[7].setPosition(410,551);
		upSprite[7].setPosition(620,550);
		upString[7].setPosition(660,548);
		expSprite[8].setTexture(expText[stats[8]]);
    		expSprite[8].setPosition(410,581);
		upSprite[8].setPosition(620,580);
		upString[8].setPosition(660,578);	
		expSprite[9].setTexture(expText[stats[9]]);
    		expSprite[9].setPosition(410,611);
		upSprite[9].setPosition(620,610);
		upString[9].setPosition(660,608);
		

		sf::Color ptcolor(255, 205, 0);
		sf::Color ptcolorl(255, 225, 100);
		sf::Color gray(55, 55, 55);

		for (int i=0; i<10; i++) { 
			upString[i].setCharacterSize(27);
			upString[i].setFont(font);
			upString[i].setString(costSTR[stats[i]]);
			if(totalPT < costs[stats[i]])
			{
    				upSprite[i].setTexture(uOff);
				upString[i].setColor(gray);
			}
			else
			{
				upSprite[i].setTexture(uOn);
				upString[i].setColor(ptcolorl);
			}
		}
		

    		sMain.setTexture(tMain);
    		sMain.setPosition(850,750);
	//Sets up dictionairies and iterators
		std::map<std::string, std::string> noseDict = loadNoses();
		std::map<std::string, std::string>::iterator noseIt = noseDict.begin();

		std::map<std::string, std::string> bodyDict = loadBodies();
		std::map<std::string, std::string>::iterator  bodyIt = bodyDict.begin();

		std::map<std::string, std::string> tailDict = loadTails();
		std::map<std::string, std::string>::iterator  tailIt = tailDict.begin();
		sf::Text weap; 
		weap.setFont(font); 
		weap.setCharacterSize(35);
		weap.setPosition(80, 130);  
		weap.setString("Weapons"); 
		weap.setColor(sf::Color::Black);
		sf::Text engine; 
		engine.setFont(font); 
		engine.setCharacterSize(35);
		engine.setPosition(80, 470);  
		engine.setString("Engine"); 
		engine.setColor(sf::Color::Black);
		sf::Text laser; 
		laser.setCharacterSize(30);
		laser.setFont(font); 
		laser.setPosition(150, 180);  
		laser.setString("Shrink Laser"); 
		laser.setColor(sf::Color::Black);
		sf::Text laserpow; 
		laserpow.setCharacterSize(27);
		laserpow.setFont(font); 
		laserpow.setPosition(220, 220);  
		laserpow.setString("Power"); 
		laserpow.setColor(sf::Color::Black);
		sf::Text laserspd; 
		laserspd.setCharacterSize(27);
		laserspd.setFont(font); 
		laserspd.setPosition(220, 250);  
		laserspd.setString("Speed"); 
		laserspd.setColor(sf::Color::Black);
		sf::Text lasercd; 
		lasercd.setCharacterSize(27);
		lasercd.setFont(font); 
		lasercd.setPosition(220, 280);  
		lasercd.setString("Cooldown"); 
		lasercd.setColor(sf::Color::Black);
		sf::Text missile; 
		missile.setFont(font); 
		missile.setCharacterSize(30);
		missile.setPosition(150, 320);  
		missile.setString("Bounce Missile"); 
		missile.setColor(sf::Color::Black);
		sf::Text misspow; 
		misspow.setCharacterSize(27);
		misspow.setFont(font); 
		misspow.setPosition(220, 360);  
		misspow.setString("Power"); 
		misspow.setColor(sf::Color::Black);
		sf::Text missspd; 
		missspd.setCharacterSize(27);
		missspd.setFont(font); 
		missspd.setPosition(220, 390);  
		missspd.setString("Speed"); 
		missspd.setColor(sf::Color::Black);
		sf::Text misscd; 
		misscd.setCharacterSize(27);
		misscd.setFont(font); 
		misscd.setPosition(220, 420);  
		misscd.setString("Cooldown"); 
		misscd.setColor(sf::Color::Black);
		sf::Text forward; 
		forward.setCharacterSize(27);
		forward.setFont(font); 
		forward.setPosition(220, 520);  
		forward.setString("Fwd Thrust"); 
		forward.setColor(sf::Color::Black);
		sf::Text side; 
		side.setCharacterSize(27);
		side.setFont(font); 
		side.setPosition(220, 550);  
		side.setString("Side Thrust"); 
		side.setColor(sf::Color::Black);
		sf::Text backward; 
		backward.setCharacterSize(27);
		backward.setFont(font); 
		backward.setPosition(220, 580);  
		backward.setString("Back Thrust"); 
		backward.setColor(sf::Color::Black);
		sf::Text shield; 
		shield.setCharacterSize(27);
		shield.setFont(font); 
		shield.setPosition(220, 610);  
		shield.setString("Shield"); 
		shield.setColor(sf::Color::Black);
		sf::Text shipcolor; 
		shipcolor.setCharacterSize(30);
		shipcolor.setFont(font); 
		shipcolor.setPosition(917, 240);  
		shipcolor.setString("Custom Colors"); 
		shipcolor.setColor(sf::Color::Black);
		
		
		points.setColor(ptcolor);
		PlayerShip pc(980, 370,0.1,0.05,0.05);
		pc.setOrientation(3* M_PI / 2);

	//Populate flippers

		Flipper noseFlipper(1050, 300);
		for(noseIt=noseDict.begin(); noseIt!=noseDict.end(); ++noseIt)
		{
			noseFlipper.addToList(noseIt->first);
		}

		Flipper bodyFlipper(1050, 350);
		for(bodyIt=bodyDict.begin(); bodyIt!=bodyDict.end(); ++bodyIt)
		{
			bodyFlipper.addToList(bodyIt->first);
		}


		Flipper tailFlipper(1050, 400);
		for(tailIt=tailDict.begin(); tailIt!=tailDict.end(); ++tailIt)
		{
			tailFlipper.addToList(tailIt->first);
		}




		Menu menu;
		menu.addFlipper(noseFlipper); 	menu.addFlipper(bodyFlipper); menu.addFlipper(tailFlipper);
		pc.chooseNose(noseDict.at(menu.flippers.at(0).returnText()));
		pc.chooseBody(bodyDict.at(menu.flippers.at(1).returnText()));
		pc.chooseTail(tailDict.at(menu.flippers.at(2).returnText()));
		
	sf::SoundBuffer buffert;//thruster buffer
	if (!buffert.loadFromFile("sounds/blip.wav"))
	    return -1;
	    //making sounds 
	    sf::Sound clicksound;
	    clicksound.setBuffer(buffert);
	  sf::SoundBuffer buffern;//thruster buffer
	//background music
	sf::Music bgmusic;
	if (!bgmusic.openFromFile("sounds/GrimesOblivion.wav"))
	return -1; // error
	bgmusic.play();
	bgmusic.setLoop(true); 
	int hovcount = 0; 

		
		
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
		if(Event.type == sf::Event::MouseButtonPressed)
		{clicksound.play(); 
			if(mouseOnSprite(sMain, App))
			{
				saveState(noseDict.at(menu.flippers.at(0).returnText()), bodyDict.at(menu.flippers.at(1).returnText()), 
						tailDict.at(menu.flippers.at(2).returnText()));
					saveStats();
					savePoints();
					return(0);
			}
			for (int i=0; i<10; i++){
				if(mouseOnSprite(upSprite[i], App)){
					if(stats[i] < 5)					
					if(totalPT >= costs[stats[i]])
					{
						totalPT -= costs[stats[i]];
						points.setString(IntToString(totalPT) + " UPGRADE POINTS");
						stats[i] += 1;
						expSprite[i].setTexture(expText[stats[i]]);
							upString[i].setString(costSTR[stats[i]]);
							for (int i=0; i<10; i++) { 
							if(totalPT < costs[stats[i]] && stats[i] < 5)
							{
    							upSprite[i].setTexture(uOff);
							upString[i].setColor(gray);
							}
							else
							{
							upSprite[i].setTexture(uOn);
							upString[i].setColor(ptcolorl);
							}
		}
						
					}
				}
			}



		}
		    if((Event.type == sf::Event::KeyPressed) && (Event.key.code == sf::Keyboard::Down)){ clicksound.play(); 
					menu.next();
		    }
				if((Event.type == sf::Event::KeyPressed) && (Event.key.code == sf::Keyboard::Up)){ clicksound.play(); 
					menu.previous();
				}
				if((Event.type == sf::Event::KeyPressed) && (Event.key.code == sf::Keyboard::Left)){ clicksound.play(); 
					menu.flipperPrevious();
					pc.chooseBody(bodyDict.at(menu.flippers.at(1).returnText()));
					pc.chooseNose(noseDict.at(menu.flippers.at(0).returnText()));
					pc.chooseTail(tailDict.at(menu.flippers.at(2).returnText()));
				}
				if((Event.type == sf::Event::KeyPressed) && (Event.key.code == sf::Keyboard::Right)){ clicksound.play(); 
					menu.flipperNext();
					pc.chooseBody(bodyDict.at(menu.flippers.at(1).returnText()));
					pc.chooseNose(noseDict.at(menu.flippers.at(0).returnText()));
					pc.chooseTail(tailDict.at(menu.flippers.at(2).returnText()));
				}
				if((Event.type == sf::Event::KeyPressed) && (Event.key.code == sf::Keyboard::Return)){ clicksound.play(); 
					saveState(noseDict.at(menu.flippers.at(0).returnText()), bodyDict.at(menu.flippers.at(1).returnText()), 
						tailDict.at(menu.flippers.at(2).returnText()));
					return(0);
				}
	    }





	    // clear screen and fill with blue
	    	App.clear(sf::Color::White);
	    	App.draw(points);
	  	pc.update();
		for (int i=0; i<10; i++) {
			App.draw(expSprite[i]);
			
			if(stats[i] < 5)
				App.draw(upSprite[i]);
			int xo = stats[i];
			upString[i].setString(costSTR[xo]);			
			App.draw(upString[i]);
		}
		App.draw(shipBG);
		App.draw(missile);
		App.draw(laser);
		App.draw(laserpow);
		App.draw(laserspd);
		App.draw(lasercd);
		App.draw(misspow);
		App.draw(missspd);
		App.draw(misscd);
		App.draw(menu);
		App.draw(weap);
		App.draw(engine);
		App.draw(pc);
		App.draw(forward);
		App.draw(side);
		App.draw(backward);
		App.draw(shield);
		App.draw(sMain);
		App.draw(shipcolor);
		
	    	App.display();
	  }

	  // Done.
	  return (-1);
}
