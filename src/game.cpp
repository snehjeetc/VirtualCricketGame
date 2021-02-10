#include "game.h"
const char prompt ='>';
Game::Game() {
	teamA.name = "Team-A";
	teamB.name = "Team-B";
	isFirst_innings = false;
}

void Game::intro() {
	//Greeting
	std::cout << "|-------------------------------------------|\n";
	std::cout << "|>>>>>>>>>>>>>>>> CRIC-IN <<<<<<<<<<<<<<<<<<|\n";
	std::cout << "|-------------------------------------------|\n";
	std::cout << "|______Welcome to Virtual-Cricket Game______|\n";
	std::cout << "|-------------------------------------------|\n\n";

	//Instructions
	std::cout << "|-------------------------------------------|\n";
	std::cout << "|============== INSTRUCTIONS ===============|\n";
	std::cout << "|-------------------------------------------|\n";
	std::cout << "|1.) Create two teams (Team-A and Team-B    |\n";
	std::cout << "|    with 4 players each ) from a pool of   |\n";
	std::cout << "|    11 players.\t\t\t    |\n";
	std::cout << "|2.) Lead the toss and decide the choice of |\n";
	std::cout << "|    play.\t\t\t\t    |\n";
	std::cout << "|3.) Each innings will be of 6 balls.\t    |\n";
	std::cout << "|-------------------------------------------|\n\n";

	std::cout << "Press enter to continue\n";
	getchar();
}

void Game::showPlayers() {			//Show pool of players
	std::cout << "|-------------------------------------------|\n";
	std::cout << "|=============POOL OF PLAYERS===============|\n";
	std::cout << "|-------------------------------------------|\n";
	for (int i = 0; i < players_name.size(); i++)
		std::cout << "\t\t[" << i + 1 << "] " << players_name[i] << "\n";
	std::cout << "|-------------------------------------------|\n\n";

	std::cout << "Press enter to continue\n";
	getchar();
}

int Game::index_check(std::vector <int>& index_remain, int inp)
{
	if (inp <= 0 || inp > 11)
	{
		return -2;
	}
	for (int i = 0; i < index_remain.size(); i++)
	{
		if (inp == index_remain[i])
		{
			index_remain.erase(index_remain.begin() + i);
			return inp-1;
		}
	}
	return -1;
}
void Game::selectingPlayers(Team &t, std::vector <int> &index_avail )
{
	std::cout << "Select players from "<<t.name<<"\n";
	int j = 1;
	int ind;
	start:
	while (j <= player_per_team)
	{
		std::cout << "Select player " << j << " from "<<t.name<<"\n";
		std::cout<<prompt;
		std::cin >> ind;
		while (!std::cin)
		{
			std::cout << "Error:  Wrong Input\n";
			std::cout << "\tOnly integer values are accepted\n";
			std::cout << "TRY AGAIN\n";
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
			goto start;
		}
		int index = index_check(index_avail, ind);
		if (index == -1)
		{
			std::cout << "Player has been already selected. Please try again.\n";
			goto start;
		}
		else if (index == -2)
		{
			std::cout << "Error:  Out Of Range input \n";
			std::cout << "\t[1,11] Accepted \n";
			std::cout << "TRY AGAIN\n";
			goto start;
		}
		else
		{
			Player P;
			P.id = index;
			P.name = players_name[index];
			t.players.push_back(P);
			++j;
		}
	}
}
void Game::selectPlayers()
{													//Selection of players from player_pool and print the TEAM-A and TEAM-B
	std::cout << "|-------------------------------------------|\n";
	std::cout << "|======== Create Team-A and Team-B =========|\n";
	std::cout << "|-------------------------------------------|\n\n";
	std::vector <int> index_avail = { 1,2,3,4,5,6,7,8,9,10,11 };
	selectingPlayers(teamA, index_avail);
	selectingPlayers(teamB, index_avail);
	std::cout << "--------------------------\t\t--------------------------" << '\n';
	std::cout << "|=======  Team-A  =======|\t\t|=======  Team-B  =======|" << '\n';
	std::cout << "--------------------------\t\t--------------------------" << '\n';
	for (int i = 0; i < player_per_team; i++)
	{
		std::cout << "|\t";
		std::cout << "[" << i + 1 << "] " << teamA.players[i].name << "\t |";
		std::cout << "\t\t|\t";
		std::cout << "[" << i + 1 << "] " << teamB.players[i].name << "\t |";
		std::cout << '\n';
	}
	std::cout << "--------------------------\t\t--------------------------\n\n";
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
	std::cout << "Press enter to toss\n";
	getchar();
}

void Game::toss()
{
	std::cout << "|-------------------------------------------|\n";
	std::cout << "|=================Let's Toss================|\n";
	std::cout << "|-------------------------------------------|\n\n";
	std::cout << "|---> ---> ---> Tossing the coin ---> --->  |\n";
	Sleep(1000);
	std::cout << "..";
	Sleep(2000);
	std::cout << "...\n";
	srand(time(NULL));
	int choice = rand() % 2;
	switch (choice)
	{
	case 0: std::cout << "Team A won the toss\n";
		tossWinner(teamA);
		break;
	case 1: std::cout << "Team B won the toss\n";
		tossWinner(teamB);
		break;
	}
}
void Game::tossWinner(Team winningTeam)
{
	int ch;
	std::cout << "Enter 1 to bat or 2 to bowl\n";
	std::cout << "1.) Bat \n2.) Bowl\n";
	std::cout<<prompt;
	std::cin >> ch;
	while (!std::cin)
	{
		std::cin.clear();
		std::cout << "Error:  Wrong Input\n";
		std::cout << "\tOnly integer values are accepted\n";
		std::cout << "TRY AGAIN\n";
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
		std::cout << prompt;
		std::cin >> ch;
	}
	switch (ch)
	{
	case 1: std::cout << winningTeam.name << " won the toss and elected to bat first \n";
		if (winningTeam.name.compare("Team-A") == 0)
		{
			batting_team = &teamA;
			bowling_team = &teamB;
		}
		else
		{
			batting_team = &teamB;
			bowling_team = &teamA;
		}
		break;
	case 2:	std::cout << winningTeam.name << " won the toss and elected to bowl first \n";
		if (winningTeam.name.compare("Team-A") == 0)
		{
			batting_team = &teamB;
			bowling_team = &teamA;
		}
		else
		{
			batting_team = &teamA;
			bowling_team = &teamB;
		}
		break;
	default: std::cout << "Invalid input\n Try again\n";
		tossWinner(winningTeam);
		break;
	}
}
void Game::swap(Team** a, Team** b)
{
	Team* temp = *a;
	*a = *b;
	*b = temp;
}
void Game::Inning(int inn_no)
{
	if (inn_no == 1)
	{
		isFirst_innings = true;
	}
	else if (inn_no == 2)
	{
		isFirst_innings = false;
	}
	else {
		std::cout << "Ivalid Argument";
		return;
	}
	if (isFirst_innings)																							//if its first INNING
	{
		std::cout << "|-------------------------------------------|\n";
		std::cout << "|***********First Innings Starts************|\n";
		std::cout << "|-------------------------------------------|\n\n";
		std::cout << "Press enter to continue \n";
		getchar();
		batsman = &batting_team->players[0];
		bowler = &bowling_team->players[0];
	}
	else
	{																																		//if its 	second INNING
		std::cout << "|-------------------------------------------|\n";
		std::cout << "|***********Second Innings Starts***********|\n";
		std::cout << "|-------------------------------------------|\n\n";
		std::cout << "Press enter to continue \n";
		getchar();
		swap(&batting_team, &bowling_team);
		batsman = &batting_team->players[0];
		bowler = &bowling_team->players[0];
	}
	std::cout << batting_team->name << " - " << batsman->name << " is batting.\n";
	std::cout << bowling_team->name << " - " << bowler->name << " is bowling.\n";
	for (int i = 1; i <= MAX_DELIVERY; i++)
	{
		std::cout << "Press enter to bowl\n";
		getchar();
		srand((unsigned)time(0));
		int runs = rand() % 7;
		if (!play(runs))
		{
			break;
		}
	}
	if (isFirst_innings)																	//Display after First innings
	{
		std::cout << "\t\t" << "|||FIRST INNINGS ENDS|||" << "\n";
		std::cout << batting_team->name << "\t" << batting_team->tot_runs << "-" << batting_team->tot_wickets_lost << " (" << bowling_team->tot_balls_bowled << ")\n";
		std::cout << bowling_team->name << "\t" << " needs " << batting_team->tot_runs + 1 << " to win the match\n";
		std::cout << "Press enter to start second innings\n";
		getchar();
	}
	else
	{
		std::cout << "\t\t" << "|||SECOND INNINGS ENDS|||" << "\n";							//Display after 2nd innings
		std::cout << batting_team->name << "\t" << batting_team->tot_runs << "-" << batting_team->tot_wickets_lost << " (" << bowling_team->tot_balls_bowled << ")\n";
		decideWinner();
	}
}
bool Game::play(int runs)
{
	if (runs != 0)		//1,2,3,4,5,6
	{
		std::cout << bowler->name << " to " << batsman->name << " "<<runs << " runs \n";
		batsman->runs_scored += runs;
		batsman->ball_played += 1;
		bowler->ball_bowled += 1;
		bowler->runs_given += runs;
		batting_team->tot_runs += runs;
		bowling_team->tot_balls_bowled += 1;
		std::cout << "|---------------------------------------------------------------|\n";
		std::cout << "|" << batting_team->name << " " << batting_team->tot_runs << " - " << batting_team->tot_wickets_lost << " (" << bowling_team->tot_balls_bowled << ")\t|";
		std::cout << "\t" << batsman->name << " " << batsman->runs_scored << " (" << batsman->ball_played << ")\t" << bowler->name << " " << bowler->ball_played << "-" << bowler->runs_given << "-" << bowler->wickets_taken << "\t|\n";
		std::cout << "|---------------------------------------------------------------|\n\n";
	}
	else
	{
		std::cout << bowler->name << " to " << batsman->name << " OUT! \n";
		batsman->ball_played = +1;
		bowler->ball_bowled += 1;
		bowler->wickets_taken += 1;
		batting_team->tot_wickets_lost += 1;
		bowling_team->tot_balls_bowled += 1;
		std::cout << "|---------------------------------------------------------------|\n";
		std::cout << "|" << batting_team->name << " " << batting_team->tot_runs << " - " << batting_team->tot_wickets_lost << " (" << bowling_team->tot_balls_bowled << ")\t|";
		std::cout << "\t" << batsman->name << " " << batsman->runs_scored << " (" << batsman->ball_played << ")\t" << bowler->name << " " << bowler->ball_played << "-" << bowler->runs_given << "-" << bowler->wickets_taken << "\t|\n";
		std::cout << "|---------------------------------------------------------------|\n\n";
		if(batting_team->tot_wickets_lost < player_per_team)
			{
			int next_Player = batting_team->tot_wickets_lost;
			batsman = &batting_team->players[next_Player];
			}
	}
	if ((batting_team->tot_wickets_lost == 4) || ((isFirst_innings == false) && (batting_team->tot_runs > bowling_team->tot_runs)))
		return false;
	else
		return true;
}

void Game::decideWinner()
{
	if (batting_team->tot_runs > bowling_team->tot_runs)
	{
		std::cout << "---------------------------------------------\n";
		std::cout << "\t" << batting_team->name << " WON THE MATCH\t\n";
		std::cout << "---------------------------------------------\n\n";
		std::cout<<"Press enter to view score card";
		getchar();
		scoreCard(batting_team, bowling_team);
		scoreCard(bowling_team, batting_team);
	}
	else if (batting_team->tot_runs < bowling_team->tot_runs)
	{
		std::cout << "---------------------------------------------\n";
		std::cout << "\t" << bowling_team->name << " WON THE MATCH\t\n";
		std::cout << "---------------------------------------------\n\n";
		std::cout<<"Press enter to view score card";
		getchar();
		scoreCard(bowling_team, batting_team);
		scoreCard(batting_team, bowling_team);
	}
	else
	{
		std::cout << "---------------------------------------------\n";
		std::cout << "\t\tMATCH TIED\n";
		std::cout << "---------------------------------------------\n\n";
		std::cout<<"Press enter to view score card";
		getchar();
		scoreCard(batting_team, bowling_team);
		scoreCard(bowling_team, batting_team);
	}
	std::cout << "\t\t|||MATCH ENDS|||\n";
}

void Game::scoreCard(Team* team1, Team* team2)
{
	std::cout << team1->name << " " << team1->tot_runs << "-" << team1->tot_wickets_lost << " (" << team2->tot_balls_bowled << ")\n";
	std::cout << "=================================================\n";
	std::cout << "|PLAYER\t\t\tBATTING\t\tBOWLING\t|\n";
	for (int i = 0; i < team1->players.size(); i++)
	{
		std::cout << "|-----------------------------------------------|\n";
		std::cout << "|" << "[" << i + 1 << "]" << team1->players[i].name << "\t\t" << team1->players[i].runs_scored << "(" << team1->players[i].ball_played << ")" << "\t\t" << team1->players[i].ball_bowled << "-" << team1->players[i].runs_given << "-" << team1->players[i].wickets_taken << "\t|\n";
	}
	std::cout << "=================================================\n\n";
}
