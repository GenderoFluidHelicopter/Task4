#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include "Model.h"


using namespace std;

int numeration = 1;


Player::Player(char s, char sd) {
	isBot = false;
	symbol = s;
	symbol_D = sd;
	number = numeration++;
}

//void Player::add_cell(pair<char, char> cell) {
//	cells.push_back(cell);
//}