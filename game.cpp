//Angelina Castillo
//Game.cpp; Initializes players and turns
#include "constants.hpp"
#include "game.hpp"

Game::Game(){
  player1= new Player;
  player2= new Player;
  trns=0;
}
Game::Game(string p1_strategy, string p2_strategy){  
  player1 = new Player(p1_strategy);
  player2 = new Player(p2_strategy);
  trns=0;
}
Game::Game(const Game& p){
  trns = p.trns;
  player1=p.player1;
  player2=p.player2;
  out_p1=p.out_p1;
  out_p2=p.out_p2;
  dec_p1=p.dec_p1;
  dec_p2=p.dec_p2;
}
Game::~Game()= default;

Game& Game::operator = (const Game& p){
  trns = p.trns;
  player1=p.player1;
  player2=p.player2;
  out_p1=p.out_p1;
  out_p2=p.out_p2;
  dec_p1=p.dec_p1;
  dec_p2=p.dec_p2;
}

void Game::PlayTurn(){
  Decision p1_turn = SILENT;//both set to silent by default
  Decision p2_turn = SILENT;
 
  p1_turn =  player1->MakeNextDecision(dec_p2, trns);
  dec_p1.push_back(p1_turn);
  
  p2_turn = player2->MakeNextDecision(dec_p1, trns);
  dec_p2.push_back(p2_turn);
  //adds sentences to the out vector based on the decision of MakeNextDecision
  if(p1_turn==SILENT and p2_turn==SILENT){
    out_p1.push_back(sentence_if_both_silent);
    out_p2.push_back(sentence_if_both_silent);
  } 
  else if(p1_turn==SNITCH and p2_turn==SNITCH){
    out_p1.push_back(sentence_if_both_snitch);
    out_p2.push_back(sentence_if_both_snitch);
  }
  else if(p1_turn==SNITCH and p2_turn==SILENT){
    out_p1.push_back(sentence_for_lone_snitch);
    out_p2.push_back(sentence_for_lone_silent);
  }
  else if(p2_turn==SNITCH and p1_turn==SILENT){
    out_p2.push_back(sentence_for_lone_snitch);
    out_p1.push_back(sentence_for_lone_silent);
  }
  trns++;
}

void Game::TurnReport(ostream& outs, int round_num) const {
  if(trns==0){return;}
  if(round_num==1){
    outs<<"*****************************************"<<endl;
    outs<<"GAME REPORT"<<endl;
    outs<<"Player 1 strategy: "<<player1->GetStrategy()<<endl;
    outs<<"Player 2 strategy: "<<player2->GetStrategy()<<endl;
  }
  string decision_p1;//empty string for decision
  //decsion string added into decision_p1 or decision_p2
  if(dec_p1.at(round_num-1)==SILENT){
    decision_p1="silent";
  }
  else if(dec_p1.at(round_num-1)==SNITCH){
    decision_p1="snitch";
  }
  else if(dec_p1.at(round_num-1)==UNKNOWN){
    decision_p1="unknown";
  } 

  string decision_p2;
  if(dec_p2.at(round_num-1)==SILENT){
    decision_p2="silent";
  }
  else if(dec_p2.at(round_num-1)==SNITCH){
    decision_p2="snitch";
  }
  else if(dec_p2.at(round_num-1)==UNKNOWN){
    decision_p2="unknown";
  }
  
  outs<<"*************** TURN "<<round_num<<" ******************"<<endl;
  outs<<"Player 1: "<<decision_p1<<endl;
  outs<<"Player 2: "<<decision_p2<<endl;
  outs<<endl;
  outs<<"Player 1 sentence: "<<out_p1.at(round_num-1)<<endl;
  outs<<"Player 2 sentence: "<<out_p2.at(round_num-1)<<endl;
  
}

void Game::Reset(){
  dec_p1.clear();//empties vectors to reset 
  dec_p2.clear();
  out_p1.clear();
  out_p2.clear();
  trns=0;
}
void Game::Reset(string p1_strategy, string p2_strategy){
  Reset();
  player1 = new Player(p1_strategy);
  player2 = new Player(p2_strategy);

}

ostream& operator <<(ostream& outs, const Game& g){
  //loops through TurnReport for all rounds of g
  for(int i=1;i==g.trns; i++){
    g.TurnReport(outs, i);
  }
  //adds together for final sentences
  float p1_sum = 0;
  for(int i = 0; i < g.out_p1.size(); i++){
    p1_sum = p1_sum + g.out_p1.at(i);
  }
  float p2_sum = 0;
  for(int i = 0; i < g.out_p2.size(); i++){
    p2_sum = p2_sum + g.out_p2.at(i);
  }
  
  outs<<"*****************************************"<<endl;
  outs<<"Player 1's total sentence: "<<p1_sum<<endl;
  outs<<"Player 2's total sentence: "<<p2_sum<<endl;  
  outs<<"*****************************************"<<endl;
  return outs;
}
