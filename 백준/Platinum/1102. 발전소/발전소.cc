#include<iostream>
#include<cmath>
#include<cstring>

#define MAX 800
using namespace std;

int n, p;
int map[16][16];
int cost[1 << 16];
string s;
int countbit(int taken) {
	if (taken == 0) {
		return 0;
	}
	return taken % 2 + countbit(taken / 2);
}
int dfs(int state) {
	if (countbit(state) >= p) return 0;
	if (cost[state] != -1) return cost[state];
	cost[state] = MAX;
	for (int i = 0; i < n; ++i) {
		if ((state & (1 << i)) == 0) continue;
		for (int j = 0; j < n; ++j) {
			if ((state & (1 << j)) == 0) {
				cost[state] = min(cost[state], map[i][j] + dfs(state | (1 << j)));
			}
		}
	}
	return cost[state];
}
int main() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> map[i][j];
		}
	}
	cin >> s; cin >> p;
	int taken=0;
	for (int i = 0; i < n; ++i) {
		if (s[i] == 'Y') {
			taken |= (1 << i);
		}
	}
	memset(cost, -1, sizeof(cost));

	if (dfs(taken) == MAX) cout << -1;
	else {
		cout << dfs(taken);
	}
}