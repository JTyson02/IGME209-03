// ConsoleApplication10.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <conio.h>
using namespace std;

class MovableObject
{
public:
	int xPos;
	int yPos;
	void PrintPos()
	{
		cout << "X:" << xPos << " Y:" << yPos << endl;
	}
};

class Player : public MovableObject
{
public:
	char* name;
	Player()
	{
		cout << "player ctor" << endl;
		name = new char[15];
	}

	~Player()
	{
		cout << "player dtor" << endl;
		delete[] name;
	}
};

class Monster : public MovableObject
{
public:
	int damage;
};

int main()
{
	//Monster *boss = new Monster();
	//Player *pOne = new Player();
	MovableObject *boss = new Monster();
	MovableObject *pOne = new Player();
	Monster *fakeMonster = (Monster*)pOne;

	// add code here

	cout << &boss << "\n" << &pOne << "\n" << &fakeMonster << "\n" << endl;
	
	boss->xPos = 12;
	boss->yPos = 50;

	pOne->xPos = 60;
	pOne->yPos = 10;

	fakeMonster->xPos = 25;
	fakeMonster->yPos = 25;


	boss->PrintPos();

	pOne->PrintPos();

	fakeMonster->PrintPos();

	boss = nullptr;
	pOne = nullptr;

	delete boss;
	delete pOne;
	delete fakeMonster; //This line is causing the crash. It's a dangling pointer

	_getch();
    return 0;
}

