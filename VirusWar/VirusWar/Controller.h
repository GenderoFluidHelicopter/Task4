#pragma once

#include <vector>
#include <string>
#include <map>
#include <utility>
//#include "Model.h"

//class Gamefield;

using namespace std;

class Player {
	char symbol;
	char symbol_D;
	int step;
	int number;
	bool isBot;
public:
	Player(char, char);

	char get_symbol() {
		return symbol;
	}

	int get_number() {
		return number;
	}

	//void add_cell(pair<char, char>);

	bool get_isBot() {
		return isBot;
	}

	char get_symbol_D() {
		return symbol_D;
	}

	void setBot(bool a) {
		this->isBot = a;
	}
};
