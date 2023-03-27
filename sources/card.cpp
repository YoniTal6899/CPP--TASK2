#include "card.hpp"
using namespace ariel;

card::card(int v, string s, bool f){ // Constructor
    this->val_=v;
    this->suit_=s;
    this->flipped_=f;
}

card::card(){} // // Default constructor

int card::GetVal() const{
    return this->val_;
}

bool card::IsShowed() const{
    return this->flipped_;
}

string card::GetSuit() const{
    return this->suit_;
}

void card::flip(){   // Switch between 1 & 0  (Simulates True/False)
    this->flipped_= !this->flipped_;
}

string card::toString() const{
    return "";
}