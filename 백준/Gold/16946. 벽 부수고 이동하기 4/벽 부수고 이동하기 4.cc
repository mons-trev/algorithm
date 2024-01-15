#include<iostream>
#include<cstring>
#include<vector>
#include<queue>

using namespace std;

int n, m;

int g[1001][1001];
vector<pair<int, int>> p;
bool check[1001][1001];
pair<int,int> ans[1001][1001];
int dy[] = { 0,0,1,-1 };
int dx[] = { 1,-1,0,0 };
/* 시간초과
int bfs(int y, int x) {
	memset(check, false, sizeof(check) * sizeof(bool));

	queue<pair<int, int>> q;
	q.push({ y,x });
	check[y][x] = true;
	int cnt = 0;
	while (!q.empty()) {
		int thisy = q.front().first;
		int thisx = q.front().second;
		cnt++;
		q.pop();
		for (int i = 0; i < 4; ++i) {
			int ny = thisy + dy[i];
			int nx = thisx + dx[i];
			if (ny > -1 && nx > -1 && ny < n && nx < m) {
				if (!check[ny][nx]) {
					if (g[ny][nx] == 0) {
						check[ny][nx] = true;
						q.push({ ny,nx });
					}
				}
			}
		}
	}
	return cnt%10;
}
*/

void bfs(int yy, int xx, int c) {
	queue<pair<int, int>> q;
	queue<pair<int, int>> q2;
	q.push({ yy,xx });
	check[yy][xx] = true;
	int cnt = 0;
	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		cnt++;
		q2.push({ y,x });
		for (int i = 0; i < 4; ++i) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny > -1 && nx > -1 && ny < n && nx < m) {
				if (!check[ny][nx]) {
					if (g[ny][nx] == 0) {
						check[ny][nx] = true;
						q.push({ ny,nx });
					}
				}
			}
		}
	}
	while (!q2.empty()) {
		int y = q2.front().first;
		int x = q2.front().second;
		q2.pop();
		ans[y][x].first = c;
		ans[y][x].second = cnt;
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		string a;
		cin >> a;
		for (int j = 0; j < a.size(); ++j) {
			g[i][j] = a[j]-'0';
			if (g[i][j]==0) { // 시간초과로 1이 아닌 0의 덩어리를 찾자
				p.push_back({ i,j });
			}
		}
	}
	/* 시간초과
	for (int i = 0; i < p.size(); ++i) {
		int y = p[i].first;
		int x = p[i].second;
		ans[y][x] = bfs(y, x);
	}
	*/
	// 0 덩어리를 찾자

	for (int i = 0; i < p.size(); ++i) {
		int y = p[i].first;
		int x = p[i].second;
		if (check[y][x]) {
			continue;
		}
		bfs(y, x,i+1);
	}
	/*
	cout << "\n";
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cout << ans[i][j].first << "," << ans[i][j].second << " ";
		}
		cout << "\n";
	}
	cout << "\n";
	*/
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			vector<int> check;
			if (g[i][j] == 0) {
				cout << '0';
			}
			else {
				int pr = 1;
				for (int k = 0; k < 4; ++k) {
					int ny = i + dy[k];
					int nx = j + dx[k];
					if (ny > -1 && nx > -1 && ny < n && nx < m) {
						bool flag = false;
						for (int t = 0; t < check.size(); ++t) {
							if (ans[ny][nx].first == check[t]) {
								flag=true;
								break;
							}
						}
						if (flag) {
							continue;
						}
						pr += ans[ny][nx].second;
						
						check.push_back(ans[ny][nx].first);
					}
				}
				cout << pr % 10;
			}
		}
		cout << "\n";
	}
}