#pragma once
#include <iostream>
using namespace std;

namespace ariel
{
    class card
    {
        private:
            int val_; // value of the card, between 1-13
            string suit_; // Shape of card
            bool flipped_; // If the card is showed or hidden 
   
        public:
            card(int v, string s, bool f); // Constructor
            card(); // Default constructor
            int GetVal() const;   // Get the value of the card (Constant method)
            string GetSuit() const; // Get the shape of the card
            bool IsShowed() const; // Return if the card is showed or upside down (Constant method)
            void flip();  // Flip the card (Non-constant method)
            string toString() const; // To string
    };
}