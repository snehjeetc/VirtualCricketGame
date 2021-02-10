#ifndef GAME_H
#define GAME_H
#include<iostream>
#include<cstdlib>
#include<ctime>
#include<windows.h>
#include<limits>
#include "team.h"


class Game {
public:
	//Attributes
	Team teamA, teamB;
	const int player_per_team = 4, MAX_DELIVERY = 6;
	std::vector <std::string> players_name = { "Virat","Rohit","Dhawan","Pant","Karthik","KL Rahul","Jadeja","Hardik","Bumrah","BKumar","Ishant" };
	bool isFirst_innings;
	Team* batting_team, * bowling_team;
	Player* batsman, * bowler;
	//Methods
	Game();
	void intro();														//Greet Users and shows basic game instructions
	void showPlayers();													//Show the pool of players
	void selectingPlayers(Team &t,std::vector <int>& index_avail);		//helps the user to select unique player in each team
	void selectPlayers();												//SelectPlayers For the teamA and teamB
	int index_check(std::vector <int>& index_remain, int inp);			//Checks the given input is in range and doesn't select player more than once
	void toss();														//tossing decides which team wins the toss
	void tossWinner(Team winningTeam);									//let the user decides what the winning team does after winning the toss
	void Inning(int inn_no);											//Play the innings by checking whether its first or second
	bool play(int runs);												//update scores and checks whether the innings has to be stopped or not
	void swap(Team** a, Team** b);										//swap two pointer variables
	void decideWinner();												//decides which team is team is winner
	void scoreCard(Team* team1, Team* team2);							//display the score card of the team

};
#endif

