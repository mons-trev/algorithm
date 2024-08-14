#include<stdio.h>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;

int n, m;
int g[9][9];
vector<pair<int, int> > list;
vector<pair<int, int >> virus;
vector<vector<pair<int, int>>> walls;
int dy[] = { 0,0,-1,1 };
int dx[] = { 1,-1,0,0 };
int origin = 0;
void makelist(vector<pair<int, int>> a, int i) {
	if (a.size() == 3) {
		walls.push_back(a);
		return;
	}
	if (i > list.size() - 1) return;
	makelist(a, i + 1);
	a.push_back(list[i]);
	makelist(a, i + 1);
	return;
}

int bfs() {
	bool visit[9][9];
	int org = 64;
	queue<pair<int, int >> oq;
	for (int k = 0; k < virus.size(); ++k) {
		oq.push(virus[k]);
	}
	for (int i = 0; i < walls.size(); ++i) {

		int ans = 0;

		memset(visit, false, sizeof(visit));

		for (int j = 0; j < 3; ++j) {
			visit[walls[i][j].first][walls[i][j].second] = true;
		}

		queue<pair<int, int >> q = oq;
		for (int k = 0; k < virus.size(); ++k) {
			visit[virus[k].first][virus[k].second] = true;
		}
		while (!q.empty()) {
			int y = q.front().first;
			int x = q.front().second;
			ans++;
			q.pop();
			for (int j = 0; j < 4; ++j) {
				int ny = y + dy[j];
				int nx = x + dx[j];
				if (ny >= 1 && nx >= 1 && ny <= n && nx <= m) {
					if (g[ny][nx] == 1) continue;
					if (visit[ny][nx]) continue;
					if (g[ny][nx] == 0 && !visit[ny][nx]) {
						q.push({ ny,nx });
						visit[ny][nx] = true;
					}
				}
			}
		}
		if (ans < org) org = ans;
	}
	return n * m - org - 3 - origin;
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			scanf("%d", &g[i][j]);
			if (g[i][j] == 0) {
				list.push_back({ i,j });
			}
			else if (g[i][j] == 2) {
				virus.push_back({ i,j });
			}
			else {
				origin += 1;
			}
		}
	}
	vector<pair<int, int>> a;
	makelist(a, 0);
	printf("%d", bfs());
}