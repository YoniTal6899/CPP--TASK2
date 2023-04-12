#pragma once
#include <iostream>
#include "player.hpp"
#include "card.hpp"
#include <vector>
#include <algorithm>
#include <random>
using namespace std;

const int FOUR=4;
const int THIRTEEN=13;
namespace ariel
{
    class Game
    {
        private:
            Player& p1;
            Player& p2; // Players of the game
            vector<card> start_deck; // Stores the 52 cards that will be dealed to the players
            bool able_to_play; // If the game can be played?
            string winner; // winner name
            int draws; // For statistics
            int turns; // For statistics
            int curr_stack; // Current number of cards in the stack
            string turn_log; // Description of the current turn
            vector<string> full_logs; // Stores all the logs
            bool curr_turn; // Determine if the turn is over or we are in darw situation
   
        public:            
            Game(Player& P1, Player& P2) : p1(P1), p2(P2)  // Constructor
            {
                if(&p1 == &p2){this->able_to_play=false; return;} // One player can't play with himself
                this->able_to_play=true;
                this->draws=0;
                this->turns=0;
                this->curr_stack=0;
                this->curr_turn=true;
                this->turn_log="";
                this->winner="Not decided yet...";  
                for(int i=0;i<THIRTEEN;i++)  // Create 52 cards
                {
                    for(int j=0;j<FOUR;j++)
                    {
                        card c(i,j);
                        this->start_deck.push_back(c);
                    }
                }
                this->shuffle_();
                while(!this->start_deck.empty()) // Deal to each player 1 card from the suffeled deck
                {
                    card c= this->start_deck.back();
                    this->start_deck.pop_back();
                    this->p1.add_card(c);
                    c= this->start_deck.back();
                    this->start_deck.pop_back();
                    this->p2.add_card(c);
                }
            }


            void playTurn()
            {
                if(able_to_play)
                {
                    if(this->p1.stacksize()==0 || this->p2.stacksize()==0) // Game over
                    {
                        this->able_to_play=false;
                        if(this->p1.cardesTaken() > this->p2.cardesTaken()){this->winner=this->p1.GetName();}
                        else if(this->p2.cardesTaken() > this->p1.cardesTaken()){this->winner=this->p2.GetName();}
                        else {this->winner="Draw!";}
                        return;
                    }
                    this->curr_stack=0;
                    this->turns+=1;
                    this->turn_log="";
                    card c1= this->p1.pull();
                    this->turn_log+= this->p1.GetName() + " played " + c1.print() + " ";
                    card c2= this->p2.pull();
                    this->turn_log+= this->p2.GetName() + " played " + c2.print() +". ";
                    this->curr_stack+=2;
                    this->curr_turn = true;
                    while(this->curr_turn) // Main loop to determine the winner of the turn
                    {
                        if(c1.GetVal()!= c2.GetVal()) // No draw, detrmine the winner for this round
                        {
                            if(c1.GetVal()==0) // Player1 got ace
                            {
                                if(c2.GetVal()==1) // Player2 got '2'. Player 2 wins the round
                                {
                                    this->curr_turn=false;
                                    this->p2.update_cards_won(this->curr_stack);
                                    this->p2.update_win_truns();
                                    this->turn_log+= this->p2.GetName() + " wins.";
                                }
                                else // Ace beats anything but 2. Player1 wins the round
                                {
                                    this->curr_turn=false;
                                    this->p1.update_cards_won(this->curr_stack);
                                    this->p1.update_win_truns();   
                                    this->turn_log+= this->p1.GetName() + " wins.";
                                }
                            }

                            else if(c2.GetVal()==0) // Player2 got ace
                            {
                                if(c1.GetVal()==1) // Player1 got '2'. Player 1 wins the round
                                {
                                    this->curr_turn=false;
                                    this->p1.update_cards_won(this->curr_stack);
                                    this->p1.update_win_truns();
                                    this->turn_log+= this->p1.GetName() + " wins.";
                                }
                                else // Ace beats anything but 2. Player2 wins the round
                                {
                                    this->curr_turn=false;
                                    this->p2.update_cards_won(this->curr_stack);
                                    this->p2.update_win_truns();   
                                    this->turn_log+= this->p2.GetName() + " wins.";
                                }
                            }

                            else // No aces involved
                            {
                                if(c1.GetVal() > c2.GetVal())
                                {
                                    this->curr_turn=false;
                                    this->p1.update_cards_won(this->curr_stack);
                                    this->p1.update_win_truns();
                                    this->turn_log+= this->p1.GetName() + " wins."; 
                                }
                                else
                                {
                                    this->curr_turn=false;
                                    this->p2.update_cards_won(this->curr_stack);
                                    this->p2.update_win_truns();
                                    this->turn_log+= this->p2.GetName() + " wins.";
                                }
                            }
                        }

                        else // Draw!
                        {
                            this->turn_log+= " Draw. ";
                            this->draws+=1;
                            if(this->p2.stacksize() < 2 && this->p1.stacksize() < 2){
                                this->curr_turn = false;
                                return;
                            }
                            // Hidden cards
                            c1 = this->p1.pull();
                            c2 = this->p2.pull();
                            
                            // Playing cards
                            c1 = this->p1.pull();
                            c2 = this->p2.pull();
                            this->turn_log+= this->p1.GetName() + " played " + c1.print() +" ";
                            this->turn_log += this->p2.GetName() + " played " + c2.print()+".";
                            this->curr_stack +=4;
                        }
                    }

                } else {__throw_runtime_error("Unable to play!");}

                this->full_logs.push_back(this->turn_log);
            }


            void printWiner();
            void printLog() const;
            void printStats() const;
            void playAll();
            void printLastTurn() const;

            void shuffle_() // Shuffle the deck (Permutation of the vector) *took from internet*
            {
                random_device rd;
                mt19937 rng(rd());
                shuffle(this->start_deck.begin(), this->start_deck.end(), rng);
            }

            void print_deck()
            {
                for(unsigned int i=0;i<this->start_deck.size();i++){
                    cout << this->start_deck.at(i).print() << endl;
                }
            }
    };
}