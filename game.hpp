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
	Game();
    //initializes player1 and player2 as new players

	Game(string p1_strategy, string p2_strategy);
    // initialize player strategies

    Game(const Game& p);
	~Game();	
	Game& operator = (const Game& p);
	void PlayTurn();
    // Play another round -- record each player's decision

	void TurnReport(ostream& outs, int round_num) const;
    // Print the results of an individual turn (see sample output)

	void Reset();
    // Reinitialize list of turns

	void Reset(string p1_strategy, string p2_strategy);
    // Reinitialize game and player strategies

	friend ostream& operator << (ostream& outs, const Game& g);
    // Print game report (see sample output)
    // prints each player's strategy,
    // calls the turn report for every turn, and the total sentences
private:
  Player* player1;//pointing to player strategy
  Player* player2;//pointing to player strategy

  std::vector <Decision> dec_p1;//vector holding player1 decisions
  std::vector <Decision> dec_p2;//vector holding player2 decisions
  std::vector <float> out_p1;//vector of player1 sentences
  std::vector <float> out_p2;//vector of player2 sentences
  int trns;
};

#endif
