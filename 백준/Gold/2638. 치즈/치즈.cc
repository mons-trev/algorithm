//#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<queue>

using namespace std;

int main() {
	char g[101][101];
	short n, m;
	short dy[] = { 1,-1,0,0 };
	short dx[] = { 0,0,1,-1 };
	short t = 0;
	scanf("%hd %hd", &n, &m);

	for (short i = 1; i <= n; ++i) {
		for (short j = 1; j <= m; ++j) {
			scanf(" %c", &g[i][j]);
			if (g[i][j] == '1') {
				t++;
			}
		}
	}
	priority_queue<pair<short, pair<short, short>>> air;
	air.push({ 0, {1,1} });
	g[1][1] = 'a';
	short a = 0;
	while (!air.empty()) {
		short y = air.top().second.first;
		short x = air.top().second.second;
		short cnt = -air.top().first;
		air.pop();
		for (short i = 0; i < 4; ++i) {
			short ny = y + dy[i];
			short nx = x + dx[i];
			if (nx >= 1 && ny >= 1 && ny <= n && nx <= m) {
				if (g[ny][nx] == 'a') continue;
				else if(g[ny][nx] != '0'){
					if (g[ny][nx] == '1') {
						g[ny][nx] = '2';
						continue;
					}
					else {
						a++;
						if (a == t) {
							printf("%hd", cnt + 1);
							return 0;
						}
						air.push({ -(cnt + 1), {ny, nx} });
						g[ny][nx] = 'a';
					}
				}
				else {
					g[ny][nx] = 'a';
					air.push({ -cnt, {ny,nx} });
				}
			}
		}
	}
}
