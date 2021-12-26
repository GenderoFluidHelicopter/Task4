//#include "VirusWar.h"
#include "Model.h"
#include "Controller.h"
#include "View.h"

using namespace std;

Gamefield g(8, 8);
View v;
Player p1('x', 'X');
Player p2('o', 'O');

int play() {
	g.place_start(p1);
	g.place_start(p2);

	while (1) {
		int zxc = 0;
		while (1) {
			v.display(g);
			zxc = g.get_step(p1);
			if (zxc == 2) {
				cout << "Player X defeated\n\n";
				getchar();
				return 0;
			}

			if (zxc)
				break;
		}

		while (1) {
			v.display(g);
			int zxc = g.get_step(p2);

			if (zxc == 2) {
				cout << "Player O defeated\n\n";
				getchar();
				return 0;
			}

			if (zxc)
				break;
		}
	}

}


int main() {
	
	int choice = 0;

	v.print_menu();
	cin >> choice;

	switch (choice) {
	case 1: {
		p2.setBot(false);
		play();
		break;
	}
	case 2: {
		p2.setBot(true);
		play();
		break;
	}
		
	case 0: break;

		// Error
	default:
		choice = 228;
		break;
	}
	
	return 0;
}