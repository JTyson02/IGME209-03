// GravitySnake.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <conio.h>
#include <random>
#include "snake.h"
#include "Box2D/Box2D/Box2D.h"

using namespace std;

int main()
{

    int score = 100000;

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

    cout << "Welcome to Gravity Snake! Hit the target 10 times to win!" << endl;

    char key = NULL;

    //Defines the timestep
    float timeStep = 1.0f / 10000.0f;

    while(targetsHit < 10)
    {

        //If a key is pressed, apply force
        if (_kbhit())
        {
            //Save the key
            key = _getch();

            //If the key pressed is escape
            if (key == '\x1b')
            {
                //break
                break;
            }
            //Otherwise apply forces
            ApplyForces(body, key);

            Update(worldP, timeStep);

            MoveTarget(*xPos, *yPos, *body, *targetsHitP);

            //Print out the locations of the player and target position
            Display(*body);

            //Decrease score for every button pressed
            score--;

        }
        else
        {
            Update(worldP, timeStep);

            MoveTarget(*xPos, *yPos, *body, *targetsHitP);

            //Print out the locations of the player and target position
            Display(*body);
        }
    }

    cout << "Congratulations! You scored " << score << " out of 100,000 points!" << endl;

}
