#include "Statek.h"
using namespace std;
Ship::Ship(int LENGHT) : LENGHT(LENGHT) {}
// inicjalizujemy długosc statku 
void Ship::add_field(int x, int y) { // kordynaty ktore reprezentuja statek 
    field.push_back(make_pair(x, y));
}
