#include <iostream>
//#include "cScreen.hpp"
#include <string>
#include <SFML/Graphics.hpp>
#include <math.h> 
#include "GameWorld.hpp"
#include <SFML/Audio.hpp>


 
class screen_0 : public cScreen
{
private:
    int alpha_max;
    int alpha_div;
    float GLOBAL_RES = 300.0f;
    bool playing;
    bool hoverCustom = false;
    bool hoverPlay = false;
    bool hoverL = false;
    bool hoverR = false;
    int selMode = 0;
    int hoverMode = -1;
    int newHover = -1;
    int diff = 1;
    sf::Texture modeImg [12];
    sf::Sprite modeSprite [4];
    std::string diffStr[3];
    
    
public:
    screen_0(void);
    void saveSelection();
    virtual int Run(sf::RenderWindow &App);
};

screen_0::screen_0(void)
{
    alpha_max = 3 * 255;
    alpha_div = 3;
    playing = false;
}

bool inRange (float x1, float x2, float y1, float y2, float dist)
{
    if(sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2)) < dist)
	return true;
    return false;
}

void screen_0::saveSelection(){
	std::ofstream ofs;
	ofs.open("bin/select.txt", std::ofstream::out| std::ofstream::trunc);
	ofs << selMode; ofs << "\n";
	ofs << diff; ofs << "\n";
	ofs.close();
}

int screen_0::Run(sf::RenderWindow &App)
{
    sf::Event Event;
    bool Running = true;
    //sf::Texture Texture;
    //sf::Sprite Sprite;
    diffStr[0] = "30 seconds";
    diffStr[1] = "90 seconds";
    diffStr[2] = "3 minutes";
    int alpha = 0;
    sf::Font Font;
    int menu = 0;
    sf::Font font;
    sf::Text text;
    diff = 1; 

    PlayerShip pc(900, 400,0.1,0.05,0.05);
    pc.setOrientation(3* M_PI / 2);

    font.loadFromFile("LemonMilk.otf");
    text.setFont(font);
    text.setString("90 seconds");
    text.setCharacterSize(35);
    text.setColor(sf::Color::Black);
    sf::FloatRect textRect = text.getLocalBounds();
    text.setOrigin(textRect.left + textRect.width/2.0f,
    textRect.top  + textRect.height/2.0f);
    text.setPosition(sf::Vector2f(GLOBAL_RES*8/3+100,GLOBAL_RES*19/10+45));
    
    
   
    //sf::Texture m0;
    if (!modeImg[0].loadFromFile("img/mode00.png"))
    {
        std::cerr << "mode00.png" << std::endl;
        return (-1);
    }
    if (!modeImg[4].loadFromFile("img/mode01.png"))
    {
        std::cerr << "mode01.png" << std::endl;
        return (-1);
    }
    if (!modeImg[8].loadFromFile("img/mode02.png"))
    {
        std::cerr << "mode02.png" << std::endl;
        return (-1);
    }
    modeSprite[0].setTexture(modeImg[0]);
    modeSprite[0].setPosition(GLOBAL_RES*2/3,GLOBAL_RES*5/3);

    
    if (!modeImg[1].loadFromFile("img/mode10.png"))
    {
        std::cerr << "mode10.png" << std::endl;
        return (-1);
    }
    if (!modeImg[5].loadFromFile("img/mode11.png"))
    {
        std::cerr << "mode11.png" << std::endl;
        return (-1);
    }
    if (!modeImg[9].loadFromFile("img/mode12.png"))
    {
        std::cerr << "mode12.png" << std::endl;
        return (-1);
    }
    modeSprite[1].setTexture(modeImg[9]);
    modeSprite[1].setPosition(GLOBAL_RES*2/3,GLOBAL_RES*2/3);

    if (!modeImg[2].loadFromFile("img/mode20.png"))
    {
        std::cerr << "mode2.png" << std::endl;
        return (-1);
    }
    if (!modeImg[6].loadFromFile("img/mode21.png"))
    {
        std::cerr << "mode21.png" << std::endl;
        return (-1);
    }
    if (!modeImg[10].loadFromFile("img/mode22.png"))
    {
        std::cerr << "mode22.png" << std::endl;
        return (-1);
    }
    modeSprite[2].setTexture(modeImg[10]);
    modeSprite[2].setPosition(GLOBAL_RES*1/6,GLOBAL_RES*7/6);

    if (!modeImg[3].loadFromFile("img/mode30.png"))
    {
        std::cerr << "mode3.png" << std::endl;
        return (-1);
    }
    if (!modeImg[7].loadFromFile("img/mode31.png"))
    {
        std::cerr << "mode00.png" << std::endl;
        return (-1);
    }
    if (!modeImg[11].loadFromFile("img/mode32.png"))
    {
        std::cerr << "mode00.png" << std::endl;
        return (-1);
    }
    modeSprite[3].setTexture(modeImg[11]);
    modeSprite[3].setPosition(GLOBAL_RES*7/6,GLOBAL_RES*7/6);

    sf::Texture m4;
    sf::Sprite s4;
    if (!m4.loadFromFile("img/play.png"))
    {
        std::cerr << "mode4.png" << std::endl;
        return (-1);
    }
    s4.setTexture(m4);
    s4.setPosition(GLOBAL_RES*8/3,GLOBAL_RES*14/6);

    sf::Texture m5;
    if (!m5.loadFromFile("img/playsel.png"))
    {
        std::cerr << "mode5.png" << std::endl;
        return (-1);
    }

    sf::Texture m6;
    sf::Sprite s6;
    if (!m6.loadFromFile("img/astrologo.png"))
    {
        std::cerr << "mode6.png" << std::endl;
        return (-1);
    }
    s6.setTexture(m6);
    s6.setPosition(30.0f,30.0f);

    sf::Texture m7;
    sf::Sprite s7;
    if (!m7.loadFromFile("img/cust.png"))
    {
        std::cerr << "mode4.png" << std::endl;
        return (-1);
    }
    s7.setTexture(m7);
    s7.setPosition(GLOBAL_RES*8/3 - 25,0);

    sf::Texture m8;
    if (!m8.loadFromFile("img/custsel.png"))
    {
        std::cerr << "mode5.png" << std::endl;
        return (-1);
    }

    sf::Texture m9;
    sf::Sprite s9;
    if (!m9.loadFromFile("img/larrow.png"))
    {
        std::cerr << "mode4.png" << std::endl;
        return (-1);
    }
    s9.setTexture(m9);
    s9.setPosition(GLOBAL_RES*8/3 - 60,GLOBAL_RES*19/10);

    sf::Texture m10;
    sf::Sprite s10;
    if (!m10.loadFromFile("img/rarrow.png"))
    {
        std::cerr << "mode4.png" << std::endl;
        return (-1);
    }
    s10.setTexture(m10);
    s10.setPosition(GLOBAL_RES*8/3 + 200,GLOBAL_RES*19/10);

    sf::Texture m11;
    sf::Sprite s11;
    if (!m11.loadFromFile("img/shippre.png"))
    {
        std::cerr << "shippre.png" << std::endl;
        return (-1);
    }
    s11.setTexture(m11);
    s11.setPosition(GLOBAL_RES*8/3 -50,GLOBAL_RES*17/20);

  //This is the sound buffer 
    sf::SoundBuffer buffert;//thruster buffer
    if (!buffert.loadFromFile("sounds/blip.wav"))
        return -1;
	//making sounds 
	sf::Sound clicksound;
	clicksound.setBuffer(buffert);
       sf::SoundBuffer buffern;//thruster buffer
    if (!buffern.loadFromFile("sounds/neon.wav"))
        return -1;
	//making sounds 
	sf::Sound hoversound;
	hoversound.setBuffer(buffern);
    hoversound.setPitch(.8); 
    //background music
    sf::Music bgmusic;
    if (!bgmusic.openFromFile("sounds/GrimesOblivion.wav"))
    return -1; // error
    bgmusic.play();
    bgmusic.setLoop(true); 
    int hovcount = 0; 


/*
    Sprite.setTexture(Texture);
    Sprite.setColor(sf::Color(255, 255, 255, alpha));
*/
    if (!Font.loadFromFile("slkscr.ttf"))
    {
        std::cerr << "Error loading slkscr.ttf" << std::endl;
        return (-1);
    }
	

    if (playing)
    {
        alpha = alpha_max;
    }

    while (Running)
    {
        //Verifying events
        while (App.pollEvent(Event))
        {
	  
	
            // Window closed
            if (Event.type == sf::Event::Closed)
            {
                return (-1);
            }
	    if (Event.type == sf::Event::MouseMoved)
		{
		if(Event.mouseMove.x  > GLOBAL_RES*8/3 && Event.mouseMove.x < (GLOBAL_RES*8/3+200) && Event.mouseMove.y > GLOBAL_RES*14/6 && Event.mouseMove.y < (GLOBAL_RES*14/6 + 80))
			{
			hovcount = 1; 
			if (hoversound.getStatus() != sf::Sound::Playing)
			  hoversound.play();
			hoverPlay = true;			
			s4.setTexture(m5);
			hoversound.play(); 
		    
			}
		else
			{
			s4.setTexture(m4);
			hoverPlay = false;
			}
		if(Event.mouseMove.x  > GLOBAL_RES*8/3 - 60 && Event.mouseMove.x < (GLOBAL_RES*8/3) && Event.mouseMove.y > GLOBAL_RES*19/10 && Event.mouseMove.y < (GLOBAL_RES*19/10 + 90))
			{
			hoverL = true;
			hovcount = 1; 
			if (hoversound.getStatus() != sf::Sound::Playing)
			  hoversound.play();
			}
		else
			{
			hoverL = false;
			}
		if(Event.mouseMove.x  > GLOBAL_RES*8/3 +200 && Event.mouseMove.x < (GLOBAL_RES*8/3 + 260) && Event.mouseMove.y > GLOBAL_RES*19/10 && Event.mouseMove.y < (GLOBAL_RES*19/10 + 90))
			{
			hoverR = true;
			hovcount = 1; 
			if (hoversound.getStatus() != sf::Sound::Playing)
			  hoversound.play();
			}
		else
			{
			hoverR = false;
			}
		if(Event.mouseMove.x  > GLOBAL_RES*8/3-25 && Event.mouseMove.x < (GLOBAL_RES*8/3+225) && Event.mouseMove.y > 0 && Event.mouseMove.y < 50)
			{
			hoverCustom = true;	
			hovcount = 1; 
			if (hoversound.getStatus() != sf::Sound::Playing)
			  hoversound.play();		
			s7.setTexture(m8);
			}
		else
			{
			s7.setTexture(m7);
			hoverCustom = false;
			}
		if(inRange(Event.mouseMove.x, GLOBAL_RES*2/3 + 125, Event.mouseMove.y, GLOBAL_RES*7/6 + 125, GLOBAL_RES/2 + 125))
		{
		
		if(inRange(Event.mouseMove.x, GLOBAL_RES*2/3 + 125, Event.mouseMove.y, GLOBAL_RES*5/3 + 125, 125))
			{
			newHover = 0;
					hovcount = 1; 
			if (hoversound.getStatus() != sf::Sound::Playing)
			  hoversound.play();
			}
		/*
		else if(inRange(Event.mouseMove.x, GLOBAL_RES*2/3 + 125, Event.mouseMove.y, GLOBAL_RES*2/3 + 125, 125))
			{
			newHover = 1;
					hovcount = 1; 
			if (hoversound.getStatus() != sf::Sound::Playing)
			  hoversound.play();
			}
				
		*/	
		else if(inRange(Event.mouseMove.x, GLOBAL_RES*1/6 + 125, Event.mouseMove.y, GLOBAL_RES*7/6 + 125, 125))
			{
			newHover = 2;
					hovcount = 1; 
			if (hoversound.getStatus() != sf::Sound::Playing)
			  hoversound.play();
			}	
		/*
		else if(inRange(Event.mouseMove.x, GLOBAL_RES*7/6 + 125, Event.mouseMove.y, GLOBAL_RES*7/6 + 125, 125))
			{			
			newHover = 3; 
					hovcount = 1; 
			if (hoversound.getStatus() != sf::Sound::Playing)
			  hoversound.play();
			}
		*/
		}
		else
			newHover = -1;
	
		if(newHover != hoverMode && hoverMode >= 0 && hoverMode != selMode)
			modeSprite[hoverMode].setTexture(modeImg[hoverMode + 8]);
		hoverMode = newHover;
		if(hoverMode >= 0 && hoverMode != selMode)
			modeSprite[hoverMode].setTexture(modeImg[hoverMode + 4]);
		}
		
		//for hoversounds 
	if (hovcount != 1)
	  hoversound.pause();
	else 
	  hovcount = 0; 
	    //Mouseclick
	    if (Event.type == sf::Event::MouseButtonPressed)
		{
		 
    		if (Event.mouseButton.button == sf::Mouse::Left)
    		{
        	//std::cout << "the left button was pressed" << std::endl;
		  
        		if(hoverMode != selMode && hoverMode >= 0)
			{
				modeSprite[0].setTexture(modeImg[8]);
				modeSprite[1].setTexture(modeImg[9]);
				modeSprite[2].setTexture(modeImg[10]);
				modeSprite[3].setTexture(modeImg[11]);
				modeSprite[hoverMode].setTexture(modeImg[hoverMode]);
				selMode = hoverMode;
				 clicksound.play(); 
			}
    		
		if (hoverPlay)
		{
		saveSelection();
		clicksound.play(); 
		return(1);
		}
		if (hoverCustom)
		{ clicksound.play(); 
		  return (2);}
		if (hoverL)
		{	 clicksound.play(); 
			if(diff > 0)
			{
			diff--;
			text.setString(diffStr[diff]);
    			sf::FloatRect textRect = text.getLocalBounds();
    			text.setOrigin(textRect.left + textRect.width/2.0f,
    			textRect.top  + textRect.height/2.0f);
    			text.setPosition(sf::Vector2f(GLOBAL_RES*8/3+100,GLOBAL_RES*19/10+45));
			}		
		}
		if (hoverR)
		{	 clicksound.play(); 
			if(diff < 2)
			{
			diff++;
			text.setString(diffStr[diff]);
    			sf::FloatRect textRect = text.getLocalBounds();
    			text.setOrigin(textRect.left + textRect.width/2.0f,
    			textRect.top  + textRect.height/2.0f);
    			text.setPosition(sf::Vector2f(GLOBAL_RES*8/3+100,GLOBAL_RES*19/10+45));
			}
		}
		
		}
	    }
            //Key pressed
            if (Event.type == sf::Event::KeyPressed)
            { clicksound.play(); 
                switch (Event.key.code)
                {
                case sf::Keyboard::Up:
                    menu = 0;
                    break;
                case sf::Keyboard::Down:
                    menu = 1;
                    break;
		case sf::Keyboard::S:
			return(2);
			break;
                case sf::Keyboard::Return:
                    if (menu == 0)
                    {
                        //Let's get play !
                        playing = true;
			saveSelection();
                        return (1);
                    }
                    else
                    {
                        //Let's get work...
                        return (-1);
                    }
                    break;
                default:
                    break;
                }
            }
        }
        
        //Clearing screen
        App.clear(sf::Color::White);
        //Drawing
        //App.draw(Sprite);
        
	App.draw(modeSprite[0]);
	App.draw(modeSprite[1]);
	App.draw(modeSprite[2]);
	App.draw(modeSprite[3]);
	App.draw(s4);
	App.draw(s6);
	App.draw(s7);
	App.draw(s9);
	App.draw(s10);
	App.draw(s11);
	App.draw(text);
	App.draw(pc);
        App.display();
    }

    //Never reaching this point normally, but just in case, exit the application
    return (-1);
}
