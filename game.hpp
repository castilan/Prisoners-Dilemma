//Angelina Castillo
//project 2
#ifndef GAME_HPP
#define GAME_HPP

#include "constants.hpp"
#include "player.hpp"

// Definition of Game class 
#include<vector>
class Game {
public:
  //inittializes player1 and player2 as new players
	Game();
	// initialize player strategies
	Game(string p1_strategy, string p2_strategy);
	Game(const Game& p);
	~Game();	
	Game& operator = (const Game& p);

	// Play another round -- record each player's decision
	void PlayTurn();

	// Print the results of an individual turn (see sample output)
	void TurnReport(ostream& outs, int round_num) const;

	// Reinitialize list of turns
	void Reset();

	// Reinitialize game and player strategies
	void Reset(string p1_strategy, string p2_strategy);

	// Print game report (see sample output)
	// prints each player's strategy,
	// calls the turn report for every turn, and the total sentences
	friend ostream& operator << (ostream& outs, const Game& g);

private:
  Player* player1;//pointing to player strategy
  Player* player2;//pointing to player strategy
  //try a vector!
  std::vector <Decision> dec_p1;//vector holding player1 decisions
  std::vector <Decision> dec_p2;//vector holding player2 decisions
  std::vector <float> out_p1;//vector of player1 sentences
  std::vector <float> out_p2;//vector of player2 sentences
  int trns;
};

#endif
