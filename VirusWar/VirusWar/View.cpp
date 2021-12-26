#include "View.h"
#include "Model.h"
#include <windows.h>
#include <iostream>

using namespace std;

void View::display(Gamefield field) {
	system("cls");
	cout << "    ";
	for (int i = 1; i <= field.get_cols(); i++)
		cout << "|" << i;
	cout << endl;
	for (int i = 0; i < field.get_rows(); i++) {
		cout << "   " << i + 1;
		for (int j = 0; j < field.get_cols(); j++)
			cout << "|" << field.matrix[i][j];
		cout << "|" << i + 1 << endl;
	}
	cout << "    ";
	for (int i = 1; i <= field.get_cols(); i++)
		cout << "|" << i;
	cout << endl;
}

void View::print_menu() {
	system("CLS");
	cout << "VirusWar" << endl << endl;
	cout << "Please choose an option" << endl;
	cout << "1 - Play Game versus the human!" << endl;
	cout << "2 - Play Game versus the computer!" << endl;
	cout << "0 - Exit." << endl;
	cout << ": ";
}
