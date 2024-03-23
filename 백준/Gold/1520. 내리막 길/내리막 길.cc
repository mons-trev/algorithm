#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<map>
#include <iomanip>

using namespace std;


int dy[4] = {0,1,0,-1};
int dx[4] = {1,0,-1,0};
int g[500][500];
int dp[500][500];
int n, m;

int dfs(int y, int x) {
	if (y == n - 1 && x == m - 1) {
		dp[y][x] = 1;
		return 1;
	}

	for (int i = 0; i < 4; ++i) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny >= 0 && nx >= 0 && ny < n && nx < m) {
			if (g[ny][nx] < g[y][x]) {
				if (dp[ny][nx] == -1) {
					dp[ny][nx] = 0;
					dp[y][x] += dfs(ny, nx);
				}
				else {
					dp[y][x] += dp[ny][nx];
				}
				
			}
		}
	}
	return dp[y][x];
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> g[i][j];
			dp[i][j] = -1;
		}
	}
	dp[0][0] = 0;
	cout << dfs(0, 0);
}