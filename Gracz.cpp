#include <iostream>
#include "Gracz.h"
#include <vector>
using namespace std;

Player::Player(string name) {
    this->name = name; // przrypisuje imie gracza do odpowiedniego pola 
}

void Player::set_ship_manual() { //funkcja pozwala graczowi na reczne ustawienie statkow na planczy
    vector<int> ships = {4, 3, 3, 2, 2, 2, 1, 1, 1, 1}; //lista długosci statkow 
    for (int i = 0; i < ships.size(); i++) {// petla po wszystkich statkach 
        bool set = false;
        while (!set) { // dopuki statek nie zostanie ustawiony gracz bedzie probowal ponownie 
            int x, y;
            char ORIEN; // orientacja (pionowa badz pozioma ) statku 
            cout << "Ustaw statek o dlugosci " << ships[i] << " wpisz kordynaty x, y oraz orientacje PIONOWO(W) - POZIOMO(D): ";
            cin >> x >> y >> ORIEN;

            if (board.set_ship(x, y, ships[i], ORIEN)) { // pruba ustawienia statku na planszy 
                set = true;
                cout << "Statek ustawiony pomyślnie!"<< endl;
                board.show_board(false);  
            } else {
                cout << "coś poszło nie tak. Spróbuj ponownie."<< endl;
            }
        }
    }
}

bool Player::shot_opponent(int x, int y) { // funckja umozliwa graczowi wykonanie strzalu w kordynaty na plansze przeciwnika 
    return board.shot(x, y);
}

bool Player::all_ships_destroyed() { // sprawdza czy wszystkie statki gracza zstaly zniszczone 
    return board.if_all_ships_destroyed();
}
