//Angelina Castillo
//project 2
#ifndef PLAYER_H
#define PLAYER_H

#include "constants.hpp"
#include <vector>
// Definition of player class
// You may add any other private member variables or functions you need
class Player {

public:

	// --- You MUST implement the following functions ---
        Player(); 
        Player(string desired_strategy); // initialize strategy
        Player(const Player& p);
        ~Player();
  //operator = reassigns strategy to Player p's strategy
  //returns the player
        Player& operator = (const Player& p);
        string GetStrategy() const {return strategy; }  // accessor function for strategy
  //returns next decision made by Player based on the round number turn_num
  //takes a vector of decisions for implementing a previous decision if needed for TIT_FOR_TAT
  Decision MakeNextDecision(vector<Decision>d, int turn_num);

private:
        string strategy; // should be one of the possible_strategies from constants.hpp	
};

#endif
