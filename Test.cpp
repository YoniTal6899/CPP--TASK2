#include "doctest.h"

#include <iostream>
#include <string>
using namespace std;

#include "sources/player.hpp"
#include "sources/card.hpp"
#include "sources/game.hpp"
using namespace ariel;

TEST_CASE("First Initializations"){

    card eight_petrozillia(8,"Petrozillia",true);
    Player yoni("Yoni");
    Player eyal("Eyal");
    Game g1(yoni,eyal);

    CHECK_NOTHROW(eight_petrozillia.flip());
    CHECK_NOTHROW(eight_petrozillia.GetSuit()); 
    CHECK_NOTHROW(eight_petrozillia.GetVal());
    CHECK_NOTHROW(eight_petrozillia.IsShowed());   
    CHECK(eight_petrozillia.GetSuit()=="Petrozillia");
    CHECK(eight_petrozillia.GetVal()==8);
    CHECK(eight_petrozillia.IsShowed()==false);

    eight_petrozillia.flip();
    CHECK(eight_petrozillia.IsShowed()==true);
    eight_petrozillia.flip();
    CHECK(eight_petrozillia.IsShowed()==false);
    CHECK(eight_petrozillia.toString()=="");
    

    CHECK(yoni.GetName()=="Yoni");
    CHECK(yoni.stacksize()==26);
    CHECK(yoni.cardesTaken()==0);
    CHECK(eyal.GetName()=="Eyal");
    CHECK(eyal.stacksize()==26);
    CHECK(eyal.cardesTaken()==0);

    CHECK_NOTHROW(g1.playTurn());
    CHECK_NOTHROW(g1.printWiner());
    CHECK_NOTHROW(g1.printLog());
    CHECK_NOTHROW(g1.printStats());
    CHECK_NOTHROW(g1.playAll());
    CHECK_NOTHROW(g1.printLastTurn());            

}