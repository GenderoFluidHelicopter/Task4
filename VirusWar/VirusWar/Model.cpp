#include "Model.h"
#include "Controller.h"
#include <iostream>
#include <stdlib.h> 
#include <time.h>
#include <windows.h>

Gamefield::Gamefield(int height, int width) {
    // allocating memory for matrix
    rows = height;
    cols = width;
    matrix = new char* [rows];
    for (int i = 0; i < rows; i++) {
        matrix[i] = new char[cols];
    }
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            matrix[i][j] = ' ';
}


int Gamefield::check_possibility(Player& p) {
    int poss = 0;
    for (int i = 1; i <= 8; i++) {
        for (int j = 1; j <= 8; j++) {
            int pos = i * 10 + j;
            if(check_cell(pos, p.get_symbol()))
                poss++;
        }
    }
    return poss;
}


int Gamefield::get_step(Player& p) {

    int poss = check_possibility(p);
    if (!poss) {
        return 2;
    }


    if (!p.get_isBot()) {

        cout << endl << endl;
        cout << "Player " << p.get_symbol() << " turn: ";
        string step_s;

        cin >> step_s;
        if ((step_s.length() == 2) && (isdigit(step_s[0])) && (isdigit(step_s[1]))) {
            if (check_cell(stoi(step_s), p.get_symbol())) {
                int xy_pos = stoi(step_s);
                int x = xy_pos / 10 - 1;
                int y = xy_pos % 10 - 1;

                pair<char, char> new_pos = make_pair(step_s[0], step_s[1]);
                if (matrix[x][y] == ' ') {
                    matrix[new_pos.first - 49][new_pos.second - 49] = p.get_symbol();
                }
                else {
                    matrix[new_pos.first - 49][new_pos.second - 49] = p.get_symbol_D();
                }

                return 1;
            }
        }
    }
    else { //bot
        vector <pair<int, int>> all_moves;
        for (int i = 1; i <= 8; i++) {
            for (int j = 1; j <= 8; j++) {
                int pos = i * 10 + j;
                if (check_cell(pos, p.get_symbol())) {
                    pair<char, char> new_pos = make_pair(i-1, j-1);
                    all_moves.push_back(new_pos);
                    
                }
            }
        }
        srand(time(NULL));


        int rand_index = rand() % (all_moves.size());
        int x = all_moves[rand_index].first;
        int y = all_moves[rand_index].second; 

        Sleep(250);
        if (matrix[x][y] == ' ') {
            matrix[x][y] = p.get_symbol();
        }
        else {
            matrix[x][y] = p.get_symbol_D();
        }

        return 1;
    }

    return 0;
}

void Gamefield::place_start(Player& p) {

    if (p.get_number() == 1) {
        //p.add_cell(make_pair(0, 0));
        matrix[0][0] = p.get_symbol();
        //p.add_cell(make_pair(0, 1));
        matrix[0][1] = p.get_symbol();
        //p.add_cell(make_pair(1, 0));
        matrix[1][0] = p.get_symbol();
    }
    else {
        //p.add_cell(make_pair(rows - 1, cols - 1));
        matrix[rows - 1][cols - 1] = p.get_symbol();
        //p.add_cell(make_pair(rows - 2, cols - 1));
        matrix[rows - 2][cols - 1] = p.get_symbol();
        //p.add_cell(make_pair(rows - 1, cols - 2));
        matrix[rows - 1][cols - 2] = p.get_symbol();
    }
}

bool Gamefield::check_cell(int pos, char s) {
    int x = pos / 10 - 1;
    int y = pos % 10 - 1;
    // 0 - нельзя, 1 - можно
    //проверить клетку на занятость
    if (matrix[x][y] == s)
        return 0;

    //проверить клетку на мегакрипа
    if ((matrix[x][y] == 'X') || (matrix[x][y] == 'O'))
        return 0;

    //проверяем соседей

    //1
    if (y != cols - 1)
        if (matrix[x][y + 1] == s)
            return 1;
    //2
    if ((y != cols - 1) && (x != 0))
        if (matrix[x - 1][y + 1] == s)
            return 1;
    //3
    if (x != 0)
        if (matrix[x - 1][y] == s)
            return 1;
    //4
    if ((y != 0) && (x != 0))
        if (matrix[x - 1][y - 1] == s)
            return 1;
    //5
    if (y != 0)
        if (matrix[x][y - 1] == s)
            return 1;
    //6
    if ((y != 0) && (x != rows - 1))
        if (matrix[x + 1][y - 1] == s)
            return 1;
    //7
    if (x != rows - 1)
        if (matrix[x + 1][y] == s)
            return 1;
    //8
    if ((y != cols - 1) && (x != rows - 1))
        if (matrix[x + 1][y + 1] == s)
            return 1;
    return 0;
}