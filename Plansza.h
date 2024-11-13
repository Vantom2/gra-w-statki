#ifndef PLANSZA_H
#define PLANSZA_H

class Board {
public:
    char board[10][10];
    Board();
        void show_board(bool opponent_view = false);
        bool check_parts(int x, int y, int LENGHT, char ORIEN);
        bool set_ship(int x, int y, int LENGHT, char ORIEN);
        bool shot(int x, int y);
        bool if_all_ships_destroyed();
};

#endif