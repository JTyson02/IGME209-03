// PE5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#define SFML_STATIC
#include <SFML\Window.hpp>
#include <SFML\Graphics.hpp>

int main()
{
    // create the window
    sf::RenderWindow window(sf::VideoMode(800, 600), "My window");

    // run the program as long as the window is open
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // clear the window with black color
        window.clear(sf::Color::Black);

        sf::RectangleShape rectangle(sf::Vector2f(120.f, 50.f));

        sf::CircleShape circle(50.f);

        sf::CircleShape circle2(25.f);

        sf::RectangleShape rectangle2(sf::Vector2f(200.f, 200.f));

        circle.setPosition(650.f, 100.f);

        circle2.setPosition(300.f, 250.f);

        circle2.setFillColor(sf::Color(100, 50, 100));

        rectangle2.setPosition(500.f, 400.f);

        rectangle2.setFillColor(sf::Color(100, 100, 200));

        rectangle.setPosition(10.f, 15.f);

        // draw everything here...
        window.draw(rectangle);
        window.draw(circle);
        window.draw(rectangle2);
        window.draw(circle2);
        // window.draw(...);

        // end the current frame
        window.display();
    }
}
