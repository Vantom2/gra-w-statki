#include <iostream>
#include "Gracz.h"
using namespace std;
void game_play(int& win_player1, int& win_player2) { //głowna funkcja gry 
    Player player1("Gracz 1"); // tworzenie graczy 
    Player player2("Gracz 2");

    player1.set_ship_manual(); //stawianie statkow 
    player2.set_ship_manual();

    bool end = false; //zmienna mowiaca o zakonczeniu gry 
    int round = 1; //aktualna tura 

    while (!end) {
        Player& akt_player = (round == 1) ? player1 : player2; // ogolna petla gry trwa puki jakic gracz nie wygra 
        Player& opponent = (round == 1) ? player2 : player1; // okreslamy ktory gracz jest aktywny 1/2

        cout << akt_player.name << " twoja kolej "<< endl;
        akt_player.board.show_board(false); // wyswietlamy plansze gracza 

        int x, y; 
        bool correct = false; // sprawdzamy czy kordynaty sa ok 
        while (!correct) {
            cout << "Podaj kordynaty strzału (x y): "; 
            cin >> x >> y;

            if (x >= 0 && x < 10 && y >= 0 && y < 10) { //sprawdzamy czy kordynaty sa w poprawynym zakresie 
                correct = true;
                if (akt_player.shot_opponent(x, y)) {
                    if (opponent.all_ships_destroyed()) {// sprawdzamy czy przeciwnik ma zniczone wszystkie statki 
                        cout << "Brawo! " << akt_player.name << " wygrał!"<< endl; 
                        if (round == 1) { 
                            win_player1++;
                        } else {
                            win_player2++;
                        }
                        cout << "może jeszcze raz? (T/N): ";
                        char choice;
                        cin >> choice;
                        if (choice == 'T' || choice == 't') {
                            game_play(win_player1, win_player2);
                            return;
                        } else {
                            return; //kocznymy aktualna gre 
                        }
                    } else {
                        cout << "znowu twoja kolej " << endl;
                    }
                } else {
                    round = (round == 1) ? 2 : 1; // jesli strzal byl chybiony zmieniamy ture
                }
            } else {
                cout << "złe kordynaty! Wprowadź liczby od 0 do 9."<< endl;
            }
        }
    }
}

int main() {
    int win_player1 = 0;
    int win_player2 = 0;

    while (true) {
        game_play(win_player1, win_player2);
        cout << "Wyniki: "<< endl;
        cout << "Gracz 1: " << win_player1 << " wygranych"<< endl;
        cout << "Gracz 2: " << win_player2 << " wygranych"<< endl;
    }

    return 0;
}
