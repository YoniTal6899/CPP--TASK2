#pragma once
#include <iostream>
using namespace std;

namespace ariel
{
    class card
    {
        private:
            int val_; // value of the card, between 1-13
            int suit_; // Shape of card. ENUM based.
   
        public:
            card(int v, int s); // Constructor
            card(); // Default constructor
            int GetVal() const;   // Get the value of the card (Constant method)
            int GetSuit() const; // Get the shape of the card
            string print() const; // To string
    };
}