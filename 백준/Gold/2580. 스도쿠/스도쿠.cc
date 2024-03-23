#include<iostream>
#include<vector>

using namespace std;


int g[9][9];
vector<pair<int, int>> zeros;

bool check(int a, int y, int x) {
	for (int i = 3 * (y / 3); i < 3 * (y / 3) + 3; ++i) {
		for (int j = 3 * (x / 3); j < 3 * (x / 3) + 3; ++j) {
			if (a == g[i][j]) {
				return false;
			}
		}
	}
	for (int i = 0; i < 9; ++i) {
		
		if (a == g[y][i]) {
			return false;
			
		}
		if (a == g[i][x])
			return false;
	}
	return true;
}

bool back(int idx) {

	if (idx >= zeros.size()) return true;
	int y = zeros[idx].first;
	int x = zeros[idx].second;
	
	for (int i = 1; i < 10; ++i) {
		if (check(i, y, x)) {
			g[y][x] = i;
			if (back(idx + 1)) {
				return true;
			}
			g[y][x] = 0;
		}
	}
	//g[y][x] = 0;
	return false;
}

int main() {
	
	for (int i = 0; i < 9; ++i) {
		for (int j = 0; j < 9; ++j) {
			cin >> g[i][j];
			if (g[i][j] == 0) {
				zeros.push_back({ i,j });
			}
		}
	}

	back(0);


	for (int i = 0; i < 9; ++i) {
		for (int j = 0; j < 9; ++j) {
			cout << g[i][j] << " ";
		}
		cout << "\n";
	}
}
