#include "player.hpp"
using namespace ariel;

Player::Player(string n){ // Constructor
    this->name_=n;
}

Player::Player(){} // Default constructor

void Player::update_stack(card* s, int win){
    // Needs to implemant
}

int Player::stacksize() const{
    return this->cards_num;
}

string Player::GetName() const{
    return this->name_;
}

int Player::cardesTaken() const{
    return this->cards_won;
}

