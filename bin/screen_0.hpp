#include <iostream>
//#include "cScreen.hpp"

#include <SFML/Graphics.hpp>

class screen_0 : public cScreen
{
private:
    int alpha_max;
    int alpha_div;
    bool playing;
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

int screen_0::Run(sf::RenderWindow &App)
{
    sf::Event Event;
    bool Running = true;
    //sf::Texture Texture;
    //sf::Sprite Sprite;
    int alpha = 0;
    sf::Font Font;
    int menu = 0;

    sf::Texture m0;
    sf::Sprite s0;
    if (!m0.loadFromFile("img/mode0.png"))
    {
        std::cerr << "mode0.png" << std::endl;
        return (-1);
    }
    s0.setTexture(m0);
    s0.setPosition(150.0f,100.0f);

    sf::Texture m1;
    sf::Sprite s1;
    if (!m1.loadFromFile("img/mode1.png"))
    {
        std::cerr << "mode1.png" << std::endl;
        return (-1);
    }
    s1.setTexture(m1);
    s1.setPosition(150.0f,320.0f);

    sf::Texture m2;
    sf::Sprite s2;
    if (!m2.loadFromFile("img/mode2.png"))
    {
        std::cerr << "mode2.png" << std::endl;
        return (-1);
    }
    s2.setTexture(m2);
    s2.setPosition(260.0f,210.0f);

    sf::Texture m3;
    sf::Sprite s3;
    if (!m3.loadFromFile("img/mode3.png"))
    {
        std::cerr << "mode3.png" << std::endl;
        return (-1);
    }
    s3.setTexture(m3);
    s3.setPosition(40.0f,210.0f);

    sf::Texture m4;
    sf::Sprite s4;
    if (!m4.loadFromFile("img/play.png"))
    {
        std::cerr << "mode4.png" << std::endl;
        return (-1);
    }
    s4.setTexture(m4);
    s4.setPosition(570.0f,420.0f);

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
        
	App.draw(s0);
	App.draw(s1);
	App.draw(s2);
	App.draw(s3);
	App.draw(s4);

        App.display();
    }

    //Never reaching this point normally, but just in case, exit the application
    return (-1);
}
