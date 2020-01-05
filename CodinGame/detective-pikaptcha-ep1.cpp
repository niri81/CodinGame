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

std::map<pair<int, int>, char> grid; //y, x, tile

struct Tile {
	int x;
	int y;
	int down(int, int);
	int top(int, int);
	int left(int, int);
	int right(int, int);
};

int Tile::left(int x, int y) {
	x--;
	if (grid[{y, x}] != '1') {
		return 0;
	}
	else {
		return 1;
	}
}

int Tile::right(int x, int y) {
	x++;
	if (grid[{y, x}] != '1') {
		return 0;
	}
	else {
		return 1;
	}
}

int Tile::top(int x, int y) {
	y++;
	if (grid[{y, x}] != '1') {
		return 0;
	}
	else {
		return 1;
	}
}

int Tile::down(int x, int y) {
	y--;
	if (grid[{y, x}] != '1') {
		return 0;
	}
	else {
		return 1;
	}
}

int main()
{
	
	int width;
	int height;
	cin >> width >> height; cin.ignore();
	for (int i = 0; i < height; i++) { //y
		string line;
		getline(cin, line);
		stringstream ss(line);
		for (int j = 0; j < width; j++) { //x
			if (line.at(j) == '0') {
				grid[{i, j}] = '1';
			} else grid[{i, j}] = line.at(j);
		}
	}

	for (int y = 0; y < height; y++) {
		string out;
		for (int x = 0; x < width; x++) {
			int passages;
			if (grid[{y, x}] == '#') {
				out.append("#");
			} else {
				Tile temp;
				temp.x = x;
				temp.y = y;
				passages = temp.down(x, y) + temp.top(x, y) + temp.left(x, y) + temp.right(x, y);
				out.append(to_string(passages));
			}
		}
		cout << out << endl;
	}
}