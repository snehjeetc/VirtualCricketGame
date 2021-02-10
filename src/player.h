#ifndef PLAYER_H
#define PLAYER_H
#include<string>
class Player {
public:
	//Attributes
	std::string name;
	int id;
	int runs_scored, ball_played;											//for batsman
	int ball_bowled, runs_given, wickets_taken;								//for bowler

	//Methods
	Player();
};
#endif

