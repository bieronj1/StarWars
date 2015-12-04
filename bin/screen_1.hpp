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
    int gameMode = 0;
    int difficulty = 1;
public:
    screen_1(void);
    virtual int Run(sf::RenderWindow &App);
    int str2int (const string &str);
    void loadSelection();
    std::vector<int> loadConfig();
    string IntToString (int a);
};

screen_1::screen_1(void)
{
    alpha_max = 3 * 255;
    alpha_div = 3;
    playing = false;
}

int screen_1::str2int (const string &str) {
  stringstream ss(str);
  int num;
  if((ss >> num).fail())
  { 
      //ERROR 
  }
  return num;
}

string screen_1::IntToString (int a)
{
    ostringstream temp;
    temp<<a;
    return temp.str();
}


std::vector<int> screen_1::loadConfig(){
   std::vector<int> configVariables;
   std::string line;
   std::ifstream myfile("bin/upgradeState.txt");
   if(getline(myfile, line)){
     int i = str2int(line);
     configVariables.push_back(i);
   }
   return configVariables;
   
}


void screen_1::loadSelection(){
	std::ifstream myfile("bin/select.txt");
	std::string line;
	std::string::size_type sz;   // alias of size_t

	if(!myfile.is_open())
	{
		std::cerr<<"Could not open the selection file\n";
	}
	int place = 0;
	if(getline(myfile, line))
		{
			gameMode = str2int(line);
		}
	if(getline(myfile, line))
		{
			difficulty = str2int(line);
		}
	myfile.close();
	
}

int screen_1::Run(sf::RenderWindow &App)
{
    	sf::Event Event;
    	bool Running = true;
    	sf::RectangleShape rectangle(sf::Vector2f(90, 40));
    	rectangle.setFillColor(sf::Color(255, 202, 54));
    	rectangle.setPosition(10,60);
    	sf::RectangleShape rectangleBG(sf::Vector2f(280, 40));
    	rectangleBG.setFillColor(sf::Color(115, 72, 24));
    	rectangleBG.setPosition(10,60);
	sf::RectangleShape rectangle2(sf::Vector2f(90, 40));
    	rectangle2.setFillColor(sf::Color(35, 55, 255));
    	rectangle2.setPosition(10,5);
    	sf::RectangleShape rectangleBG2(sf::Vector2f(280, 40));
    	rectangleBG2.setFillColor(sf::Color(25, 30, 125));
    	rectangleBG2.setPosition(10,5);
	sf::Clock clock;
	sf::Time elapsed1 = clock.getElapsedTime();
	int min = 0;
	int sec = 0;
	float angle;
    	//sf::Texture Texture;
    	//sf::Sprite Sprite;
    	int alpha = 0;
    	// create main window
	sf::Sprite imageBG;
	sf::Texture bgText;
   	if (!bgText.loadFromFile("img/bgtile.jpg"))
    	{
        std::cerr << "bgtile.jpg" << std::endl;
        return (-1);
    	}
	imageBG.setTexture(bgText);
	sf::Sprite timeBG;
	sf::Texture timeText;
   	if (!timeText.loadFromFile("img/timeoverlay.png"))
    	{
        std::cerr << "timeoverlay.png" << std::endl;
        return (-1);
    	}
	timeBG.setTexture(timeText);
	timeBG.setPosition(0,37);
	sf::Sprite circ;
	sf::Texture circText;
   	if (!circText.loadFromFile("img/origin.png"))
    	{
        std::cerr << "circ.png" << std::endl;
        return (-1);
    	}
	circ.setTexture(circText);
	circ.setOrigin(15,15);
  	int FPS=120;
  	App.setFramerateLimit(FPS); 

	// load game mode and difficulty
  	loadSelection();

	//taken from SFML official site
  	sf::Font font;
	if (!font.loadFromFile("lucon.ttf"))
	{
		std::cout<<"FONT FAILURE"<<std::endl;
	}
	sf::Font fontTime;
	if (!fontTime.loadFromFile("digitalm.ttf"))
	{
		std::cout<<"FONT FAILURE"<<std::endl;
	}
	sf::Text timeCounter; 
	timeCounter.setFont(fontTime); 
	timeCounter.setCharacterSize(70);
	timeCounter.setPosition(40, 40);  
	timeCounter.setColor(sf::Color::White);
  	sf::Sprite mmoverlay;
  	sf::Texture mmText;
    	if (!mmText.loadFromFile("img/mmcover.png"))
    	{
        std::cerr << "mmcover.png" << std::endl;
        return (-1);
    	}
    	
   //These are the sound buffers
    sf::SoundBuffer buffert;//thruster buffer
    if (!buffert.loadFromFile("sounds/storm-01.wav"))
        return -1;
    sf::SoundBuffer bufferl;//laser buffer
    if (!bufferl.loadFromFile("sounds/Laser2.wav"))
        return -1;
	//making sounds 
	sf::Sound lasersound;
	lasersound.setBuffer(bufferl);
	lasersound.setVolume(30); 
	sf::Sound thrustersound;
	thrustersound.setBuffer(buffert); 
	thrustersound.setVolume(80); 
    //int for keeping track of thrusters
    int thrustercounter = 0; 
 
       sf::SoundBuffer buffera;//shieldbuffer
    if (!buffera.loadFromFile("sounds/hitabsorb.wav"))
        return -1;
    	sf::Sound shieldsound;
	shieldsound.setBuffer(buffera);
    shieldsound.setPitch(.8);
    shieldsound.setVolume(30); 
    int shieldcounter = 0; 
   // shieldsound.setPitch(0.8); 
    
    
    //background music
    sf::Music bgmusic;
    if (!bgmusic.openFromFile("sounds/JBSorry.wav"))
    return -1; // error
    bgmusic.play();
    bgmusic.setLoop(true); 

    	
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
  	sf::Sprite shieldOverlay;
	shieldOverlay.setTexture(healthText);
	shieldOverlay.setPosition(0,55);

	
	App.clear(sf::Color::Black);
  // start main loop
sf::View camera(sf::FloatRect(0,0,1200,800));
	Weapon* Weapons[3];
  
//Test Weapon 0
	Weapon exlaser(0, 2, 2, 5, 0);
	Weapon excannon(0, 20, 2, 5, 0);
  	cout << exlaser.getData(); 
  PlayerShip pc(50,50,0.035,0.035,0.015);
  	pc.setShields(true);
  GameWorld world(&pc, FPS);

    if (playing)
    {
        alpha = alpha_max;
    }

    while (Running)
    {
        App.clear(sf::Color::Black); //prepare to draw on a clean slate
	elapsed1 = clock.getElapsedTime();

	if(elapsed1.asSeconds() > 180)
	{
		camera.setCenter(600, 400);
		camera.setRotation(0);
		App.setView(camera);
		return(0);
	}
	min = (180-elapsed1.asSeconds())/60;
	sec = (180-elapsed1.asSeconds()) - min*60;
	if(sec > 9)
		timeCounter.setString(IntToString(min)+":"+IntToString(sec)); 
	else
		timeCounter.setString(IntToString(min)+":0"+IntToString(sec)); 
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
	
	if(QWEASD[1])
		{pc.faster();
		   thrustercounter = 1;
		if (thrustersound.getStatus() != sf::Sound::Playing)
		{ thrustersound.setPitch(.5); 
		  thrustersound.play();
		  
		}}
	else{pc.stopThruster(); }
	
	if(QWEASD[4]){
		if(SHIFT)
			pc.slower();
		else
			pc.reverse();
	}
	if(QWEASD[3]){pc.turnLeft();}
	if(QWEASD[5]){pc.turnRight();}
	if(QWEASD[0]){pc.latLeft();
	  thrustercounter = 1; 
	  if (thrustersound.getStatus() != sf::Sound::Playing)
		{ thrustersound.setPitch(.6); 
		  thrustersound.play();	
		  
		}}
	  else{pc.stopLeft();  }
	if(QWEASD[2]){pc.latRight();
	  thrustercounter = 1;
	  if (thrustersound.getStatus() != sf::Sound::Playing)
		{ thrustersound.setPitch(.6); 
		  thrustersound.play();	
		   
		}}
	else{pc.stopRight();; 
	}
	bool zoom = false;
	pc.shieldsUp=false;
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
		//zoom=true;
		pc.shieldsUp=true;		  
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
				world.addItem(new Item(0, 0, exlaser.spd * cos(pc.orientation)+pc.vx,exlaser.spd * sin(pc.orientation)+pc.vy,3,0,10), 600+pc.lx,600+pc.ly);
			 lasersound.setPitch(1.0); 
				lasersound.play(); 
			}
	}
	
	if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
	{
    	// right click...
		if(excannon.fire())
			{
				world.addItem(new Item(0, 0, excannon.spd * cos(pc.orientation)+pc.vx,excannon.spd * sin(pc.orientation)+pc.vy,3,10000,0), 600+pc.lx,600+pc.ly);
			lasersound.setPitch(.5); 
			  lasersound.play(); 
				world.addItem(new Item(0, 0, excannon.spd * cos(pc.orientation)+pc.vx,excannon.spd * sin(pc.orientation)+pc.vy,7,10000,0), 607+pc.lx,607+pc.ly);

			}
	}
	//for thruster sounds 
	if (thrustercounter != 1)
	  thrustersound.pause();
	else 
	  thrustercounter = 0; 
	
	//for sheidl 
	if (pc.displayShield > 10 && pc.shieldsUp == true)
	  {
	shieldcounter = 1;
	if (shieldsound.getStatus() != sf::Sound::Playing)
	shieldsound.play();}
	
	if (shieldcounter != 1)
	  shieldsound.pause();
	else 
	  shieldcounter = 0; 
	
	//keys to pause music
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::N) == true)
	{
	    bgmusic.pause();

	}
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::M) == true)
	{
	    if (bgmusic.getStatus() == sf::Sound::Paused)
	    bgmusic.play(); 
	}


	App.clear(sf::Color::Black);
	
	sf::View bg(sf::FloatRect(0,0,1024,1024));
    	sf::View minimap(sf::FloatRect(0,0,600,600));
    	sf::View mmOverlay(sf::FloatRect(0,0,300,300));
	sf::View hOverlay(sf::FloatRect(0,0,300,200));
	sf::View tOverlay(sf::FloatRect(0,0,300,200));
	sf::View cOverlay(sf::FloatRect(0,0,400,400));
	world.update();
	exlaser.updateCD();
	excannon.updateCD();
	camera.setCenter(1200+pc.lx, 1200+pc.ly);
	
	//camera.move(1250-650+pc.lx,1250-500+pc.ly);
	minimap.move(1250-350+pc.lx,1250-350+pc.ly);
	camera.setRotation((pc.orientation+3.14/2.0)*180.0/M_PI);
	minimap.setRotation((pc.orientation+3.14/2.0)*180.0/M_PI);
	//cOverlay.setRotation((pc.orientation+3.14/2.0)*180.0/M_PI);
	
	if(zoom){
	camera.zoom(5);}
	minimap.zoom(3);
	camera.setViewport(sf::FloatRect(0,0,1,1));
	bg.setViewport(sf::FloatRect(0,0,1,1));
	minimap.setViewport(sf::FloatRect(0.77f,0.6866f,0.21,0.2933));
	mmOverlay.setViewport(sf::FloatRect(0.75f,0.6666f,0.25,0.3333));
	hOverlay.setViewport(sf::FloatRect(0.375f,0.85f,0.25,0.2500));
	tOverlay.setViewport(sf::FloatRect(0.0f,0.75f,0.25,0.2500));
	cOverlay.setViewport(sf::FloatRect(0.333f,0.25f,0.33333,0.5));
	App.setView(bg);
	App.draw(imageBG);
	App.setView(camera);
	world.drawOnWindow(&App);
	
	rectangle.setSize(sf::Vector2f((int)(pc.returnDisplayHealth()*2.8f), 40));
	rectangle2.setSize(sf::Vector2f((int)(pc.returnDisplayShield()*2.8f), 40));
	sf::RectangleShape minimapback(sf::Vector2f(2500,2500));
	minimapback.setFillColor(sf::Color(25,45,25));
	
	angle = atan2(world.xshifts,world.yshifts) + (pc.orientation) + 4.712f;
	circ.setPosition(cos(angle)*150.0f+200,sin(angle)*150.0f+200);


	App.setView(minimap);
	App.draw(minimapback);
	world.drawOnWindow(&App);
	App.setView(hOverlay);
	App.draw(rectangleBG);
	App.draw(rectangle);
	
	App.draw(rectangleBG2);
	App.draw(rectangle2);
	App.draw(shieldOverlay);
	App.draw(healthOverlay);
	App.setView(mmOverlay);
	App.draw(mmoverlay);
	App.setView(tOverlay);
	App.draw(timeBG);
	App.draw(timeCounter);
	App.setView(cOverlay);
	if(abs(world.xshifts) + abs(world.yshifts) > 2)
		App.draw(circ);
	App.display();
    }

    //Never reaching this point normally, but just in case, exit the application
    return (-1);
}
