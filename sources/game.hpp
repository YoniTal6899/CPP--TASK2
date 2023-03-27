#pragma once
#include <iostream>
#include "player.hpp"
using namespace std;

namespace ariel
{
    class Game
    {
        private:
            Player* p1,p2; // Pointers to the players of the game
   
        public:
            Game(Player p1, Player p2); // Consructor
            Game(); // Default constructor
            void playTurn();
            void printWiner();
            void printLog();
            void printStats();
            void playAll();
            void printLastTurn();
    };
}