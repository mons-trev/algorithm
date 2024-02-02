#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<queue>
#include<cstring>
#define MAX 100000

using namespace std;

int g[125][125];
bool v[125][125];
int cul[125][125];
int dy[] = { 0,0,1,-1 };
int dx[] = { 1,-1,0,0 };

int main() {
	int t = 1;
	while (true) {
		int n;
		scanf("%d", &n);
		if (n == 0) break;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				scanf("%d", &g[i][j]);
			}
		}
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				cul[i][j] = MAX;
			}
		}
		priority_queue<pair<int, pair<int, int>>> q;
		q.push({ -g[0][0], {0,0} });
		while (!q.empty()) {
			int sum = -q.top().first;
			int y = q.top().second.first;
			int x = q.top().second.second;
			q.pop();
			if (v[y][x]) continue;
			v[y][x] = true;
				for (int i = 0; i < 4; ++i) {
					int ny = y + dy[i];
					int nx = x + dx[i];
					if (ny >= 0 && nx >= 0 && ny < n && nx < n) {
						if (!v[ny][nx]) {
							cul[ny][nx] = min(cul[ny][nx], sum + g[ny][nx]);
							q.push({ -(sum + g[ny][nx]),{ny,nx} });
						}
					}
				}	
		}
		printf("Problem %d: %d\n", t, cul[n-1][n-1]);
		memset(v, false, sizeof(v));
		t++;
	}
}