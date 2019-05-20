#include <iostream>
#include <Windows.h>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#include "const.h"
#include "game.hpp"

#include "sca.hpp"

Game::Game() 
{
	SetCursorVisibility(false);
	readFileMap();
	RenderMap();
}
Game::~Game() 
{ 
	delete &amap[LVL_Y][LVL_X];
}

void Game::go()
{
	while (!running) {
		mainloop();
	}
}


// in mainloop wird das ganze spiel wiedergegebn
void Game::mainloop()
{
	
	cin.get();
}

// in RenderMap wird die map gerendert
void Game::RenderMap() 
{
	{
		for (int y = 0; y < LVL_Y; y++) {
			for (int x = 0; x < LVL_X; x++) {
				cout << amap[y][x];
			}
			cout << endl;
		}
	}
}

// in readFileMap() wird die map aus einer datei gelesen und in ein 2D Array gesteckt
void Game::readFileMap()
{
	ifstream fmap{ "map.txt" };
	if (!fmap.is_open()) { cout << "Error Loading File!"; }
	if (fmap.is_open())
	{
		for (int y = 0; y < LVL_Y; y++) {
			for (int x = 0; x < LVL_Y; x++)
			{
				fmap >> amap[y][x];
			}
		}
	}
	fmap.close();
} 
