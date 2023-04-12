#include "card.hpp"
using namespace ariel;
const int ERROR=-1;
const int ZERO=0;
const int ONE=1;
const int TWO=2;
const int THREE=3;
const int TEN=10;
const int ELEVEN=11;
const int TWELVE=12;
card::card(int v, int s){ // Constructor
    this->val_=v;
    this->suit_=s;
}

card::card(){
    this->val_=ERROR;
    this->suit_=ERROR;
} // Default constructor

int card::GetVal() const{ // Get method
    return this->val_;
}

int card::GetSuit() const{ // Get method
    return this->suit_;
}

string card::print() const{ // prints the description of the card
    string ret="";
    switch (this->GetVal()){ // Convert numeric number to string description
        case ZERO:
            ret+="Ace of ";
            break;
        case TEN:
            ret+="Jack of ";
            break;
        case ELEVEN:
            ret+="Queen of ";
            break;
        case TWELVE:
            ret+="King of ";
            break;
        default:
            ret+= to_string(this->GetVal()+1)+" of ";
            break;
    }

    switch (this->GetSuit()){ //ENUM implematning.
        case ZERO:
            ret+="Spades";
            break;
        case ONE:
            ret+="Clubs";
            break;
        case TWO:
            ret+="Hearts";
            break;
        case THREE:
            ret+="Diamonds";
            break;
        default: // Shouldn't get here!!!!!!
            __throw_logic_error("Invalid Shape for card! :(");
            exit(1);            
    }
    return ret;
}