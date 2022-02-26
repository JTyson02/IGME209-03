
using namespace std;
#include <Box2D/Box2D.h>
#include <conio.h>
#include <random>

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
    }
    else 
    {
        printf("Target %f, %f --> Snake %f, %f\n", tempX, tempY, body.GetPosition().x, body.GetPosition().y);
    }

}

void ApplyForces(b2Body *body, char key)
{
    //Applies force depending on which key was hit
    switch (key)
    {
    case 'w': //Goes up
        body->ApplyForceToCenter(b2Vec2(0.0f, 100.0f), true);
        break;

    case 'a': //Goes left
        body->ApplyForceToCenter(b2Vec2(15.0f, 0.0f), true);
        break;

    case 'd': //Goes right
        body->ApplyForceToCenter(b2Vec2(-15.0f, 0.0f), true);
        break;

    default: //None of the listed keys
        break;
    }

}

void MoveTarget(float& xpos, float& ypos, b2Body& body, int& targetsHit)
{
    //AABB collision test with a variance of +- 1.0f
    if (body.GetPosition().x <= xpos + 1.0f && body.GetPosition().x >= xpos - 1.0f 
        && body.GetPosition().y <= ypos + 1.0f && body.GetPosition().y >= ypos - 1.0f)
    {
        targetHit = true;
        targetsHit++;

        tempX = xpos;
        tempY = ypos;

        ypos = dist(gen);
        xpos = dist(gen);
    }
    else
    {
        tempX = xpos;
        tempY = ypos;
    }

}