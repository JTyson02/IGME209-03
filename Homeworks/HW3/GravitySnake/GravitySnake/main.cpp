// GravitySnake.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <conio.h>
#include <random>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "snake.h"
#include "Box2D/Box2D.h"

using namespace std;

int main()
{

    int score = 100000000;

    //the number of times the target has been reached
    int targetsHit = 0;
    int* targetsHitP = &targetsHit;

    //The X and Y position of the target
    float xposition = 0.0f;
    float yposition = 0.0f;

    float* xPos = &xposition;
    float* yPos = &yposition;

    //Vector defining gravity
    b2Vec2 gravity(0.0f, -0.01f);

    //Box2d World
    b2World world(gravity);

    //World pointer for passing into Update
    b2World* worldP = &world;

    //creates the b2d snake body
    b2BodyDef snakeBody;
    snakeBody.type = b2_dynamicBody;
    snakeBody.position.Set(2.0f, 4.0f);
    b2Body* body = world.CreateBody(&snakeBody);

    //generates a dynamic box to serve as a hitbox
    b2PolygonShape dynamicBox;
    dynamicBox.SetAsBox(1.0f, 5.0f);
    
    //defines a fixture using the dynamic box
    b2FixtureDef fixtureDef;
    fixtureDef.shape = &dynamicBox;
    fixtureDef.density = 1.0f;
    fixtureDef.friction = 1.0f;

    //Attatches the fixture to the snake body
    body->CreateFixture(&fixtureDef);

    cout << "Welcome to Gravity Snake! Hit the target(s) to win!" << endl;
    cout << "Use WASD to move the snake, R Reverses Gravity, and Space stops the snake's movement!";

    SetUpTargets();

    // create the window
    sf::RenderWindow window(sf::VideoMode(800, 600), "My window");

    float xdiff = 400;
    float ydiff = 300;

    //Defines the timestep
    float timeStep = 1.0f / 10000.0f;

    while (window.isOpen() && !gameOver)
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }
        
        ProcessInput(*body, *worldP);

        Update(worldP, timeStep);

        score--;
        
        // clear the window with black color
        window.clear(sf::Color::Black);

        sf::RectangleShape rectangle(sf::Vector2f(10.f, 10.f));
        sf::CircleShape snakeBod(20.f);

        rectangle.setPosition(currentLocation.x - xdiff, currentLocation.y - ydiff);

        snakeBod.setPosition(sf::Vector2f(body->GetPosition().x - xdiff, body->GetPosition().y - ydiff));

        // draw everything here...
        window.draw(rectangle);
        window.draw(snakeBod);
        // window.draw(...);

        // end the current frame
        window.display();

        Display(*body);

    }
    cout << "Congratulations! You scored " << score << " out of 100,000,000 points!" << endl;

}
