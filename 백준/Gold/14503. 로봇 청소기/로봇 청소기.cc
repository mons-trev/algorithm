#include<iostream>
#include<vector>
//#include<Windows.h>
using namespace std;

int n, m;
int g[50][50];

int dy[]= {-1,0,1,0};
int dx[] = {0, 1,0,-1};

void display(int y, int x) {
	cout << "\n";
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (y == i && x == j) {
				cout << "x" << " ";
				continue;
			}
			cout << g[i][j] << " ";
		}
		cout << "\n";
	}
	
}

int dfs(int y, int x, int d, int cnt) {
	//cout << cnt << endl;
	//display(y,x);
	//Sleep(500);
	if (y >= n || x >= m || y < 0 || x < 0 || g[y][x]==-1) { //후진했는데 벽 나오는 경우
		return cnt;
	}
	//int ny = y + dy[d];
	//int nx = x + dx[d];
	//if (!(ny >= n || nx >= m || ny < 0 || nx < 0)) {
		//if (g[ny][nx] == 0) {
		//	g[ny][nx] = 1;
		//	return dfs(ny, nx, d, cnt + 1);
		//}

		else {
			for (int i = 0; i < 4; ++i) {
				d = (d - 1 + 4) % 4;
				int ny = y + dy[d];
				int nx = x + dx[d];
				if (!(ny >= n || nx >= m || ny < 0 || nx < 0) && g[ny][nx] == 0) {
					g[ny][nx] = 1;
					return dfs(ny, nx, d, cnt + 1);
				}
			}
		}
	//}
	
	return dfs(y - dy[d], x - dx[d], d, cnt);
}

int main() {
	cin >> n >> m;
	int y, x;
	cin >> y >> x;
	int d;
	cin >> d;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> g[i][j];
			if (g[i][j] == 1) g[i][j] = -1;
		}
	}
	int cnt = 0;
	if (g[y][x] == 0) {
		cnt++;
		g[y][x] = 1;
	}
	cout << dfs(y, x, d, cnt);
}
