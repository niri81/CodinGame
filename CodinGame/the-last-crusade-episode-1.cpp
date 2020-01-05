#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <sstream>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

map<pair<int, int>, int> grid;

int main()
{
	int W; // number of columns.
	int H; // number of rows.
	cin >> W >> H; cin.ignore();
	for (int i = 0; i < H; i++) {
		string LINE;
		getline(cin, LINE); // represents a line in the grid and contains W integers. Each integer represents one room of a given type.
		
		stringstream ss(LINE);
		for (int j = 0; j < W; j++) {
			string temp;
			ss >> temp;
			grid[{j, i}] = stoi(temp);
		}
	}
	int EX; // the coordinate along the X axis of the exit (not useful for this first mission, but must be read).
	cin >> EX; cin.ignore();

	// game loop
	while (1) {
		int XI;
		int YI;
		string POS;
		cin >> XI >> YI >> POS; cin.ignore();

		switch (grid[{XI, YI}])
		{
		case 1:
		case 3:
		case 7:
		case 8:
		case 9:
		case 12:
		case 13:
			YI++;
			break;

		case 2:
		case 6:
			if (POS == "RIGHT") {
				XI--;
			}
			else XI++;
			break;

		case 4:
			if (POS == "TOP") {
				XI--;
			}
			else YI++;
			break;

		case 5:
			if (POS == "TOP") {
				XI++;
			}
			else YI++;
			break;

		case 10:
			XI--;
			break;

		case 11:
			XI++;
			break;

		default:
			break;
		}


		// One line containing the X Y coordinates of the room in which you believe Indy will be on the next turn.
		cout << XI << " " << YI << endl;
	}
}