#include "player.hpp"
using namespace ariel;

Player::Player(string n){ // Constructor
    this->name_=n;
}

Player::Player(){} // Default constructor

string Player::GetName() const{
    return this->name_;
}

int Player::cardesTaken() const{
    return this->cards_won;
}
