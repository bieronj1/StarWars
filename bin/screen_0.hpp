#include <iostream>
//#include "cScreen.hpp"

#include <SFML/Graphics.hpp>
#include <math.h>  
class screen_0 : public cScreen
{
private:
    int alpha_max;
    int alpha_div;
    float GLOBAL_RES = 300.0f;
    bool playing;
    bool hoverCustom = false;
    bool hoverPlay = false;
    int selMode = 0;
    int hoverMode = -1;
    int newHover = -1;
    sf::Texture modeImg [12];
    sf::Sprite modeSprite [4];
public:
    screen_0(void);
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

int screen_0::Run(sf::RenderWindow &App)
{
    sf::Event Event;
    bool Running = true;
    //sf::Texture Texture;
    //sf::Sprite Sprite;
    int alpha = 0;
    sf::Font Font;
    int menu = 0;

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
    s9.setPosition(GLOBAL_RES*8/3 - 60,GLOBAL_RES*11/6);

    sf::Texture m10;
    sf::Sprite s10;
    if (!m10.loadFromFile("img/rarrow.png"))
    {
        std::cerr << "mode4.png" << std::endl;
        return (-1);
    }
    s10.setTexture(m10);
    s10.setPosition(GLOBAL_RES*8/3 + 200,GLOBAL_RES*11/6);




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
			hoverPlay = true;			
			s4.setTexture(m5);
			}
		else
			{
			s4.setTexture(m4);
			hoverPlay = false;
			}
		if(Event.mouseMove.x  > GLOBAL_RES*8/3-25 && Event.mouseMove.x < (GLOBAL_RES*8/3+225) && Event.mouseMove.y > 0 && Event.mouseMove.y < 50)
			{
			hoverCustom = true;			
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
			}
		else if(inRange(Event.mouseMove.x, GLOBAL_RES*2/3 + 125, Event.mouseMove.y, GLOBAL_RES*2/3 + 125, 125))
			{
			newHover = 1;
			}			
		else if(inRange(Event.mouseMove.x, GLOBAL_RES*1/6 + 125, Event.mouseMove.y, GLOBAL_RES*7/6 + 125, 125))
			{
			newHover = 2;
			}	
		else if(inRange(Event.mouseMove.x, GLOBAL_RES*7/6 + 125, Event.mouseMove.y, GLOBAL_RES*7/6 + 125, 125))
			{			
			newHover = 3;
			}
		}
		else
			newHover = -1;
	
		if(newHover != hoverMode && hoverMode >= 0 && hoverMode != selMode)
			modeSprite[hoverMode].setTexture(modeImg[hoverMode + 8]);
		hoverMode = newHover;
		if(hoverMode >= 0 && hoverMode != selMode)
			modeSprite[hoverMode].setTexture(modeImg[hoverMode + 4]);
		}
	    //Mouseclick
	    if (Event.type == sf::Event::MouseButtonPressed)
		{
    		if (Event.mouseButton.button == sf::Mouse::Left)
    		{
        	std::cout << "the left button was pressed" << std::endl;
        		if(hoverMode != selMode && hoverMode >= 0)
			{
				modeSprite[0].setTexture(modeImg[8]);
				modeSprite[1].setTexture(modeImg[9]);
				modeSprite[2].setTexture(modeImg[10]);
				modeSprite[3].setTexture(modeImg[11]);
				modeSprite[hoverMode].setTexture(modeImg[hoverMode]);
				selMode = hoverMode;
			}
    		}
		if (hoverPlay)
		{
		switch (selMode)
		{
                case 0:
                    return (1);
                    break;
                case 1:
                    return (1);
                    break;
		case 2:
                    return (1);
                    break;
		case 3:
                    return (1);
                    break;
                default:
                    break;
                }
		}
		if (hoverCustom)
			return (1);
	    }
            //Key pressed
            if (Event.type == sf::Event::KeyPressed)
            {
                switch (Event.key.code)
                {
                case sf::Keyboard::Up:
                    menu = 0;
                    break;
                case sf::Keyboard::Down:
                    menu = 1;
                    break;
                case sf::Keyboard::Return:
                    if (menu == 0)
                    {
                        //Let's get play !
                        playing = true;
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
        App.display();
    }

    //Never reaching this point normally, but just in case, exit the application
    return (-1);
}
