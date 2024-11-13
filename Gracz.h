#ifndef GRACZ_H
#define GRACZ_H

#include <string>
#include "Plansza.h"
using namespace std;
class Player {
public:
    string name;
    Board board;
    
    Player(string name);
    void set_ship_manual(); 
    bool shot_opponent(int x, int y);
    bool all_ships_destroyed();
};

#endif
