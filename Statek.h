#ifndef STATEK_H
#define STATEK_H
#include <vector>
using namespace std;
class Ship {
public:
    int LENGHT;
    vector<pair<int, int>> field; 
    
    Ship(int LENGHT);
    void add_field(int x, int y);
};

#endif
