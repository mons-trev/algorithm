#include <iostream>
#include <queue> // bfs
#include <cstring> // memset

using namespace std;

int row, col;
int graph[100][100];
bool visited[100][100];
int dir[4][2] = { {1,0},{0,1},{-1,0},{0,-1} };
int result, time;

bool bfs() {
	visited[0][0] = true;
	int cnt = 0;
	queue<pair<int, int>> q;
	q.push({ 0,0 });
	time++;
	while (!q.empty()) {
		int r = q.front().first;
		int c = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nr = r + dir[i][0];
			int nc = c + dir[i][1];
			if (nr >= 0 && nr < row && nc >= 0 && nc < col && !visited[nr][nc]) {
				//인접한 칸이 0이면 계속 탐색
				if (graph[nr][nc] == 0) {
					q.push({ nr,nc });
				}
				//인접한 칸이 치즈면 치즈를0으로 바꿔주고 카운팅
				else {
					graph[nr][nc] = 0;
					cnt++;
				}
				visited[nr][nc] = true;
			}
		}
	}

	if (cnt == 0) {
		cout << --time << '\n' << result;
		return true;
	}

	else {
		result = cnt;
		return false;
	}
}
int main() {
	
	cin >> row >> col;
	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < col; ++j) {
			cin >> graph[i][j];
		}
	}
	
	//치즈가 모두 녹아서 없어질 때까지
	while (true) {
		if (bfs())
			break;
		memset(visited, false, sizeof(visited));
	}
}