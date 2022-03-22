#pragma once
#include <Box2D/Box2D.h>

void Update(b2World *world, float timeStep);

void Display(b2Body& body);

void ApplyForceUp(b2Body &player);

void ApplyForceDown(b2Body &player);

void ApplyForceLeft(b2Body &player);

void ApplyForceRight(b2Body &player);

void StopMoving(b2Body &player);

void ReverseGravity(b2World &world);

void ProcessInput(b2Body &player, b2World &world);

void SetUpTargets();

bool selectNextTarget();

extern b2Vec2* targetLocations[];

extern b2Vec2 currentLocation;

extern bool gameOver;

extern int currentTarget;

typedef void(*funcPtr)(b2Body &player);

typedef void(*gravPtr)(b2World &world);