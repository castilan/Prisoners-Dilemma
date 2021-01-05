//Sample test file for Project 2
//Angelina Castillo
//project 2 - Prisoners Dilemma

#include <iostream>
#include "constants.hpp"
#include "game.hpp"

using namespace std;

int main() {
	int num_rounds=0;	// number of rounds per game - chosen by user
	string tmp;		    // to collect user input after "press any key"
	Game g;	            // object for the game being played - will reset after each game

	// Ask the user how many rounds
	// If they give an invalid input or input is <= 0, exit
	cout << "How many turns do you want to play?\n";
	cin >> num_rounds;
	cin.get();

	if (num_rounds <= 0) {
		return 0;
	}

	// Loop over all combinations of player strategies and print game report
	for (const auto & p1_strategy : possible_strategies) {

	    for (const auto & p2_strategy : possible_strategies) {
			cout << endl;
			g.Reset(p1_strategy, p2_strategy);

			for (int i=1; i <= num_rounds; i++) {
				g.PlayTurn();
			}
			cout << g;
			cout << "Press ENTER to continue: ";
			getline(cin, tmp);			
		}
	
	}

	return 0;
}
