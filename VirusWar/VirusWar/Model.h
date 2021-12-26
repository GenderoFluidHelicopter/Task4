#pragma once
//#include "Controller.h"
#include <iostream>
#include <string>
#include "View.h"
#include "Controller.h"
//class Player;


class Gamefield {
    int rows;
    int cols;
public:
    char** matrix;

    Gamefield(int, int);
    
    int get_rows() {
        return rows;
    }

    int get_cols() {
        return cols;
    }

    void place_start(Player&);

    int get_step(Player&);

    int check_possibility(Player&);

    bool check_cell(int, char);

};