#pragma once
#include <iostream>
#include "card.hpp" 
using namespace std;

namespace ariel
{
    const int basic_stack=26;
    class Player
    {
        private:
            string name_; // name of the player
            int cards_num=basic_stack; // Basic stack size, start at 26 (52/2)
            int cards_won=0; // Default value
            card* cards;
   
        public:
            Player(string n); // Constructor
            Player(); // Default constructor
            void update_stack(card* s, int win); // Update the players stack
            string GetName() const; // Get the player's name
            int stacksize() const; // Get the player's stack size (Constant method)
            int cardesTaken() const; // Return the number of cards the player won durnig the game (Constant method)
    };
}