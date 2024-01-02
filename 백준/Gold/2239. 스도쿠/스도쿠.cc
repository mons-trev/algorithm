#include<stdio.h>
#include<utility>

using namespace std;

short g[9][9];
pair<short, short> z[81];
short n=0;

bool letscheck(short y, short x, short a) {
	for (short i = 0; i < 9; ++i) {
		if (g[y][i] == a || g[i][x] == a) {
			return false;
		}
	}
	for (short i = (y/3)*3; i / 3 < y / 3 + 1; ++i) {
		for (short j = (x/3)*3; j / 3 < x / 3 + 1; ++j) {
			if (g[i][j] == a) {
				return false;
			}
		}
	}
	return true;
}

bool search(short y, short x, short idx) {

	if (idx == n) {
		return true;
	}
	for (short i = 1; i < 10; ++i) {
		if (!letscheck(y, x, i)) {
			continue;
		}
		g[y][x] = i;
		if (idx == n - 1) return true;
		if (search(z[idx + 1].first, z[idx + 1].second, idx + 1)) {
			return true;
		}
	}
	g[y][x] = 0;
	return false;
}

int main() {
	for (short i = 0; i < 9; ++i) {
		char s[9]; scanf("%s", s);
		for (short j = 0; j < 9; ++j) {
			g[i][j] = (short)(s[j] - 48);
			if (g[i][j] == 0) {
				z[n]={ i,j };
				n++;
			}
		}
	}
	search(z[0].first, z[0].second, 0);

	for (short i = 0; i < 9; ++i) {
		for (short j = 0; j < 9; ++j) {
			printf("%d", g[i][j]);
		}
		printf("\n");
	}
}
