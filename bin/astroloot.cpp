#include <iostream>
#include <SFML/Graphics.hpp>
#include "screens.hpp"

int main(int argc, char** argv)
{
    //Applications variables
    std::vector<cScreen*> Screens;
    int screen = 0;

    //Window creation
    sf::RenderWindow App(sf::VideoMode(1200, 800, 32), "Astro-Loot");

    //Mouse cursor no more visible
    //App.setMouseCursorVisible(false);

    //Screens preparations
    screen_0 s0;
    Screens.push_back(&s0);
    screen_1 s1;
    Screens.push_back(&s1);
		screen_2 s2;
		Screens.push_back(&s2);
		screen_3 s3;
		Screens.push_back(&s3);

    //Main loop
    while (screen >= 0)
    {
        screen = Screens[screen]->Run(App);
    }

    return EXIT_SUCCESS;
}
