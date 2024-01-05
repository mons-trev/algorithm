#include<iostream>
#include<vector>

using namespace std;

int n, m;
int graph[500][500];
bool visit[500][500];
int dy[] = { 0,0,1,-1 };
int dx[] = { 1,-1,0,0 };

int dfs(int y, int x, int cnt, int sum) {
	if (cnt == 4) {
		return sum;
	}
	int ret = 0;
	for (int i = 0; i < 4; ++i) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (!(ny >= n || nx >= m || ny < 0 || nx < 0)) { // 접근할 수 없는 곳이면 가지도 말자

			if (!visit[ny][nx]) {
				visit[ny][nx] = true;
				ret = max(ret, dfs(ny, nx, cnt + 1, sum + graph[ny][nx]));
				visit[ny][nx] = false;
			}
		}
	}
	return ret;
}

int row(int y, int x) {
	if (y + 2 >= n) {
		return 0;
	}
	int a = 0;
	int b = 0;
	if (x + 1 < m) {
		a = graph[y][x] + graph[y + 1][x] + graph[y + 2][x] + graph[y + 1][x + 1];
	}
	if (x - 1 >= 0) {
		b = graph[y][x] + graph[y + 1][x] + graph[y + 2][x] + graph[y + 1][x - 1];
	}
	return max(a, b);
}

int col(int y, int x) {
	if (x + 2 >= m) {
		return 0;
	}
	int a = 0;
	int b = 0;
	if (y + 1 < n) {
		a = graph[y][x] + graph[y][x+1] + graph[y][x+2] + graph[y + 1][x + 1];
	}
	if (y - 1 >= 0) {
		b = graph[y][x] + graph[y][x+1] + graph[y][x+2] + graph[y - 1][x + 1];
	}
	return max(a, b);
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> graph[i][j];
		}
	}
	int maxx = 0;
	for (int i = 0;i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			visit[i][j] = true;
			maxx=max(maxx,dfs(i, j,1,graph[i][j]));
			visit[i][j] = false;
			int com = max(row(i, j), col(i, j));
			maxx = max(maxx, com);
		}
	}
	cout << maxx;
}
