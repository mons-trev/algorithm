#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
#include<queue>

using namespace std;

int n, m;
int dy[4] = { -1, 0, 0, 1 };
int dx[4] = { 0, 1, -1, 0 };
pair<int,pair<int,int>> g[1001][1001];
bool visit[1001][1001];

int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		string s; cin >> s;
		for (int j = 1; j <= m; ++j) {
			g[i][j] = { s[j - 1] - '0' , {false, false} };
		}
	}
	
	memset(visit, false, sizeof(visit));
	queue<pair<bool, pair<int ,pair<int, int>>>> q;

	q.push({ false, {1,{ 1,1 } } });
	while (!q.empty()) {
		bool b = q.front().first;
		int cnt = q.front().second.first;
		int y = q.front().second.second.first;
		int x = q.front().second.second.second;
		q.pop();
		if (y == n && x == m) {
			cout << cnt;
			return 0;
		}
		for (int i = 0; i < 4; ++i) {
			int nexty = y + dy[i];
			int nextx = x + dx[i];
			if (nexty > 0 && nexty < n + 1 && nextx>0 && nextx < m + 1) {
				if (!b) { //벽을 부시지 않았다면
					if (!g[nexty][nextx].second.second && g[nexty][nextx].first == 0) {
						//cout << "this " << nexty << " " << nextx << endl;
						g[nexty][nextx].second.second = true;
						q.push({ b, {cnt + 1 ,{nexty, nextx} } });
					}
					else if (!g[nexty][nextx].second.second && g[nexty][nextx].first == 1) {
						g[nexty][nextx].second.second = true;
						q.push({ !b, {cnt + 1 ,{nexty, nextx} } });
					}
				}

				else {
					if (!g[nexty][nextx].second.first && g[nexty][nextx].first == 0) {
						//cout << "this " << nexty << " " << nextx << endl;
						g[nexty][nextx].second.first = true;
						q.push({ b, {cnt + 1 ,{nexty, nextx} } });
					}

				}
			}
		}
	}
	cout << -1;
}
