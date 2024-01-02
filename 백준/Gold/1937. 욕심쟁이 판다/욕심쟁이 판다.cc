#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<queue>
#include<cmath>
#include<cstring>
using namespace std;

int n;
int g[501][501];
int dp[501][501];
int dy[] = { 0,0,1,-1 };
int dx[] = { 1,-1,0,0 };

int dfs(int cnt, int y, int x) {
	int ret = 0;
	for (int i = 0; i < 4; ++i) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny >= 1 && nx >= 1 && ny <= n && nx <= n) {
			if (g[ny][nx] > g[y][x]) {
				if (dp[ny][nx] ==-1) {
					dp[ny][nx] = 0;
					ret= max(ret, dfs(cnt + 1, ny, nx));
				}
				else {
					ret = max(ret, dp[ny][nx]);
				}
			}
		}
	}
	return dp[y][x] = ret+1;
}

int main() {
	scanf("%d", &n);
	memset(dp, -1, sizeof(dp));
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			scanf("%d", &g[i][j]);
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (dp[i][j] == -1) {
				dp[i][j] = 0;
				ans = max(ans, dfs(1, i, j));
			}
		}
	}
	printf("%d", ans);
}
