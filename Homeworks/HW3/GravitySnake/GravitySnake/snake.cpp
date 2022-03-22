
using namespace std;
#include <iostream>
#include <Box2D/Box2D.h>
#include <conio.h>
#include <random>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "snake.h"


//Random
random_device rd;   // non-deterministic generator
mt19937 gen(rd());  // to seed mersenne twister.
uniform_int_distribution<> dist(-5.0, 5.0); // distribute results between -5 and 5 inclusive.

//A quick bool used to print out an extra "target hit!" in display
bool targetHit = false;

//Temporary X and Y variables to use to print out the old location of the target
float tempX = 0.0f;
float tempY = 0.0f;


void Update(b2World *world, float timeStep)
{
	
    //sets the number of iterations to calculate the physics
    int32 velocityIterations = 6;
    int32 positionIterations = 2;

    world->Step(timeStep, velocityIterations, positionIterations);

}

void Display(b2Body& body)
{

    if(targetHit) 
    {
        
        printf("Target %f, %f --> Snake %f, %f (Target hit!)\n", tempX, tempY, body.GetPosition().x, body.GetPosition().y);
        targetHit = false;

        selectNextTarget();

    }
    else 
    {
        printf("Target %f, %f --> Snake %f, %f\n", tempX, tempY, body.GetPosition().x, body.GetPosition().y);
    }

}

#pragma region ApplyForces
//Moves the player up
void ApplyForceUp(b2Body &player) {
    player.ApplyForceToCenter(b2Vec2(0.0f, 100.0f), true); 
}

//Moves the player down
void ApplyForceDown(b2Body& player) {
    player.ApplyForceToCenter(b2Vec2(0.0f, -100.0f), true); 
}

//Moves the player left
void ApplyForceLeft(b2Body& player) {
    player.ApplyForceToCenter(b2Vec2(15.0f, 0.0f), true); 
}

//Moves the player right
void ApplyForceRight(b2Body& player) {
    player.ApplyForceToCenter(b2Vec2(-15.0f, 0.0f), true); 
}
#pragma endregion

//Stops the player's movement
void StopMoving(b2Body &player) {
    player.SetLinearVelocity(b2Vec2(0,0)); 
}

//Reverses Gravity
void ReverseGravity(b2World &world) {

    b2Vec2 grav = world.GetGravity();
    world.SetGravity(-grav);

}

//Takes in key presses and calls functions based on the inputs
void ProcessInput(b2Body &player, b2World &world) {

    funcPtr myfuncPtr = nullptr;
    gravPtr gravPtr = nullptr;

    //Moves the player left
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        // left key is pressed: move our character
        myfuncPtr = &ApplyForceLeft;
    }
    
    //Moves the player right
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        // right key is pressed: move our character
        myfuncPtr = &ApplyForceRight;

    }
    
    //Moves the player down
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        // down key is pressed: move our character
        myfuncPtr = &ApplyForceDown;
    }
    
    //Moves the player up
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        // up key is pressed: move our character
        myfuncPtr = &ApplyForceUp;
    }
    
    //Stops player movement
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
    {
        myfuncPtr = &StopMoving;
    }
    
    //Reverses Gravity
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
    {
        gravPtr = &ReverseGravity;
    }

    if (myfuncPtr != nullptr) {
        (*myfuncPtr)(player);
    }

    if (gravPtr != nullptr) {
        (*gravPtr)(world);
    }
}

//Sets up an array of coordinate points
void SetUpTargets() {

    int cnt;

    //Take in user input for the number of targets to display
    cout << "Please enter the number of targets to display: " << endl;
    cin >> cnt;

    //Sanitizes user input to ensure it is a number between 1-10
    while (cnt < 1 || !isdigit(cnt) || cnt > 10)
    {
        cout << "Please enter the number of targets to display (1-10): " << endl;
        cin >> cnt;
    }

    //Creates a new array
    *targetLocations = new b2Vec2[cnt + 1];
    
    //Loops through the array and fills it with coordinates
    for (int i = 0; i < cnt; i++)
    {

        float xpos = dist(gen);
        float ypos = dist(gen);

        b2Vec2 targetLocation = b2Vec2(xpos, ypos);

        targetLocations[i] = &targetLocation;

        //On the last loop, add a termination coorinate point
        if (i = cnt) {

            b2Vec2 termPoint = b2Vec2(-1000, -1000);

            targetLocations[i+1] = &termPoint;
        }

    }

    currentLocation = *targetLocations[0];

}

//Selects the next available coordinate point, returns true if there are more targets and false if not
bool selectNextTarget() {

    currentLocation = *targetLocations[currentTarget + 1];
    
    //If the current location is the Termination Target, returns false since it's the last in the array
    if (currentLocation == b2Vec2(-1000,-1000)) {
        gameOver = true;
        return false;
    }

    else {
        return true;
    }

}