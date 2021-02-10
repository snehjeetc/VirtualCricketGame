//============================================================================
// Name        : Virtual-Cricket-Game.cpp
// Author      : Snehjeet Chatterjee
// Version     : 1
// Copyright   : Your copyright notice
// Description : CRIC-IN C++ APP, Project for Internshala course
// Date		   : 25-08-2020
//============================================================================

#include "game.h"
int main()
{
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);
	Game G;
	G.intro();
	G.showPlayers();
	G.selectPlayers();
	G.toss();
	G.Inning(1);
	G.Inning(2);
	std::cout<<"Press enter to exit";
	getchar();
	return 0;
}
