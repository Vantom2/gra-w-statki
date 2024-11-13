#include <iostream>
#include <ctime>
#include <cstdlib>
#include "Plansza.h"
using namespace std;
Board::Board() {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            board[i][j] = '~'; 
        }
    }
}


bool Board::set_ship(int x, int y, int LENGHT, char ORIEN) { //funckja do ustawiania statkow na planszy 
    if (!check_parts(x, y, LENGHT, ORIEN)) return false; // sprawdzamy czy statek zmiesci sie na planszy na kordynatach

    if (ORIEN == 'D') { //orientacja pozioma 
        if (y + LENGHT > 10) return false; 
        for (int i = 0; i < LENGHT; i++) {
            board[y][x + i] = '-';
        }
    } else if (ORIEN == 'W') { //orientacja pionowa
        if (x + LENGHT > 10) return false; 
        for (int i = 0; i < LENGHT; i++) {
            board[y + i][x] = '-'; // oznacza statek na planszy
        }
    }

    return true;// jesli statek zostal poprawnie ustawiony zwracamy true 
}

bool Board::check_parts(int x, int y, int LENGHT, char ORIEN) {
    if (ORIEN == 'D') { 
        if (y + LENGHT > 10) return false; 
        for (int i = -1; i <= LENGHT; i++) {
            for (int j = -1; j <= 1; j++) {
                int nx = x + j;
                int ny = y + i;
                if (nx >= 0 && nx < 10 && ny >= 0 && ny < 10 && board[nx][ny] != '~') {
                    return false;
                }
            }
        }
    } else if (ORIEN == 'W') { 
        if (x + LENGHT > 10) return false; 
        for (int i = -1; i <= LENGHT; i++) {
            for (int j = -1; j <= 1; j++) {
                int nx = x + i;
                int ny = y + j;
                if (nx >= 0 && nx < 10 && ny >= 0 && ny < 10 && board[nx][ny] != '~') {
                    return false;
                }
            }
        }
    }
    return true;
}
void Board::show_board(bool opponent_view) {
    cout << "   ";
    for (int i = 0; i < 10; i++) {
        cout << i << " ";
    }
   cout << endl;

    for (int i = 0; i < 10; i++) {
        cout << i << "  ";
        for (int j = 0; j < 10; j++) {
            if (opponent_view && board[i][j] == '-') {
                cout << "~ ";  
            } else {
                cout << board[i][j] << " "; 
            }
        }
        cout << endl;
    }
}

bool Board::shot(int x, int y) { //strzelamy na podane kordynaty
//jesli trafiono w pole gdzie jest statek(-) zmieniamy pole na(*) oznaczajace trafiony statek, nastepnie pokazujemy graczowi info o trafieniu 
    if (board[x][y] == '-') {
        board[x][y] = '*';
        cout << "Trafiony!"<< endl;
        return true;
    } else if (board[x][y] == '~') {
        board[x][y] = 'P'; // zmieniamy pole na p oznaczajace pudlo 
        cout << "Pudło!"<< endl;
        return false;
    } else if (board[x][y] == '*' || board[x][y] == 'P') { //jesli strzal zostal wykonany na to pole pokazujemy graczowi info o tym ze traci kolejke 
        cout << "To pole zostało już trafione! Tracisz kolejke."<< endl;
        return false; // zwracamy falsz informujaca o tym ze gracz taci kolejke 
    }
    return false;
}

bool Board::if_all_ships_destroyed() { // sprawdza czy wszystkie  statki zostaly zniczone 
// przechodzimy przez wszsytkie wiersze na planszy 
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (board[i][j] == '-') {
                return false;
            }
        }
    }
    return true;
}
