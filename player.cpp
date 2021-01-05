//Angelina Castillo
//project 2
#include <iostream>
#include "player.hpp"
#include <vector>
using namespace std;

Player::Player(){
  strategy= "ALWAYS_SILENT";
}

Player::Player(string desired_strategy){
  strategy=desired_strategy;
}

Player::Player(const Player& p){
  strategy=p.GetStrategy();
}
Player::~Player(){}

Player& Player::operator =(const Player& p){
  strategy=p.GetStrategy();  
  return *this;
}

Decision Player::MakeNextDecision(vector<Decision>d,int turn_num){
  if(strategy=="ALWAYS_SILENT"){return SILENT;}
  else if(strategy=="ALWAYS_SNITCH"){return SNITCH;}

  else if(strategy=="SPECIAL"){//SPECIAL is switches in between snitch every other turn
    if(turn_num%2==0){return SNITCH;}//switches by using remainder of turn_num/2
    else{return SILENT;}
  } 
  else if(turn_num==0){return SILENT;}//if it during first turn return silent for TIT_FOR_TAT

  else if(strategy=="TIT_FOR_TAT"){return d[d.size()-1];}
  
  
  else{return UNKNOWN;}
}
