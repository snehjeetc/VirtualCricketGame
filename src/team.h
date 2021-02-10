#ifndef TEAM_H
#define TEAM_H
#include<vector>
#include "player.h"
class Team {
public:
	//Attributes
	std::string name;
	int tot_runs;
	int tot_wickets_lost;
	int tot_balls_bowled;
	std::vector <Player> players;

	Team();
};
#endif

