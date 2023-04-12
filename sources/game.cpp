#include "game.hpp"
#include <iostream>

using namespace ariel;  

void Game::printWiner(){cout << this->winner << endl;}
void Game::printLog() const{
    for(unsigned int i = 0; i< this->full_logs.size();i++){
        cout << this->full_logs.at(i) << endl;
    }
}
void Game::printStats() const{
    cout << this->p1.GetName() << ":" << endl;
    cout << "Cards Won: " << this->p1.cardesTaken() <<endl;
    cout << "Turns Won: " << this->p1.get_W_turns() <<endl;
    cout << "Win rate: " << to_string(float(this->p1.get_W_turns())/float(this->turns)*100.0) << "%" << endl;
    cout << "*******************************************" <<endl;
    cout << this->p2.GetName() << ":" << endl;
    cout << "Cards Won: " << this->p2.cardesTaken() <<endl;
    cout << "Turns Won: " << this->p2.get_W_turns() <<endl;
    cout << "Win rate: " << to_string(float(this->p2.get_W_turns())/float(this->turns)*100.0) << "%" << endl;
    cout << "*******************************************" <<endl;
    cout << "All game stats:" << endl;
    cout << " Draw number: " << this->draws << endl;
    cout << " Draw rate: " << to_string(float(this->draws)/float(this->turns)*100.0) << "%" << endl; 
}
void Game::playAll(){while(able_to_play){this->playTurn();}}
void Game::printLastTurn() const{cout << this->turn_log << endl;}

