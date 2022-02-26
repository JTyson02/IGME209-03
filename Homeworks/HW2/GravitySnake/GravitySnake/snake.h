#pragma once
#include <Box2D/Box2D.h>

void Update(b2World *world, float timeStep);

void Display(b2Body& body);

void ApplyForces(b2Body *body, char key);

void MoveTarget(float& xpos, float& ypos, b2Body &body, int &targetsHit);