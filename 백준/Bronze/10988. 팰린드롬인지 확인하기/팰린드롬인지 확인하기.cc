#include <iostream>
#include<queue>
#include<vector>
#include<string>
#include<cstring>

using namespace std;

/*
int r, c;
char g[1500][1500];
pair<int,int> parent[1500][1500];
bool visit[1500][1500];
vector<pair<int, int>> v;

int dy[] = { 0,1,-1, 0 };//남북동서
int dx[] = { -1,0,0,1 };

void dfs(int y, int x, int oy, int ox) {
	
	for (int i = 0; i < 4; ++i) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny >= 0 && nx >= 0 && ny < r && nx < c) {
			if (g[ny][nx] != 'X' && parent[ny][nx].first!=-1) {
				parent[y][x] = { oy,ox };
				dfs(ny, nx, oy, ox);
			}
		}
	}
}


int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> r >> c;
	priority_queue<pair<int, pair<int, int>>> q;

	for (int i = 0; i < r; ++i) {
		string s; cin >> s;
		for (int j = 0; j < c; ++j) {
			g[i][j] = s[j];
			parent[i][j] = { -1,-1 };
			if (g[i][j] == 'L') {
				q.push({ -1, {i,j} });
				v.push_back({ i,j });
			}
			else if (g[i][j] == '.') {
				q.push({ -1, {i,j} });
			}
		}
	}

	int t = 1;
	while (true) {
		
		while (!q.empty()) {
			int cc = -q.top().first;
			int y = q.top().second.first;
			int x = q.top().second.second;
			if (cc != t) break;
			q.pop();
			if (g[y][x] != 'L') {
				q.push({ -(cc+1), {y, x} });
			}
			for (int i = 0; i < 4; ++i) {
				int ny = y + dy[i];
				int nx = x + dx[i];
				if (!(ny >= 0 && nx >= 0 && ny < r && nx < c)) continue;
					if (g[ny][nx] == 'X') {
						g[ny][nx] = '.';
						q.push({ -(cc + 1), {ny, nx} });
						int dkx = ny + dy[0];
						int dky = nx + dx[0];
						for (int k = 1; k < 4; ++k) {
							int nkx = ny + dy[k];
							int nky = nx + dx[k];
							if (parent[dkx][dky] != parent[nkx][nky]) {
								u(dkx, dky, nkx, nky);
							}
						}
						
					}
			}
		}
		
		memset(visit, false, sizeof(visit));
		visit[v[0].first][v[0].second] = true;
		if (dfs(v[0].first,v[0].second)) {
			cout << t;
			return 0;
		}
		t++;
	}

}

*/

string s;
 
int main() {
	cin >> s;
	int right = s.size() - 1;
	int left = 0;
	while (right >= left) {
		if (s[left] != s[right]) {
			cout << 0;
			return 0;
		}
		right--;
		left++;
	}
	cout << 1;
	return 0;
}