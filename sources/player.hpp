#pragma once
#include <iostream>
#include "card.hpp"
#include <vector> 
using namespace std;

namespace ariel
{
    class Player
    {
        private:
            string name_; // name of the player
            vector<card> cards; // Holds the player's deck
            int cards_won=0; // Default value
            int W_tunrs=0; // Default value 
   
        public:
            Player(string n); // Constructor
            Player(); // Default constructor

            void add_card(card c)
            {
                this->cards.insert(this->cards.begin(),c);
            } // Update the players stack
            int get_W_turns() const {return this->W_tunrs;}
            string GetName() const; // Get the player's name
            int stacksize() const {return this->cards.size();} // Get the player's stack size (Constant method)
            int cardesTaken() const; // Return the number of cards the player won durnig the game (Constant method)
            void update_win_truns(){this->W_tunrs+=1;} // Add 1 to num of win turns (for statistics)
            void update_cards_won(int w){this->cards_won+=w;} // Increase the number of cards won (for statistics)

            card pull() // Takes one card out of the deck.
            {
                card c = this->cards.back();
                this->cards.pop_back();
                return c;
            }

            void print_deck(){
                for(unsigned int i=0;i<this->cards.size();i++){
                    cout << this->cards.at(i).print() << endl;
                }
            }
    };
}