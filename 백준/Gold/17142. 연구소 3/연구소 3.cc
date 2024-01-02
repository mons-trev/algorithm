#include<iostream>
#include<cmath>
#include<cstring>
#include<queue>
#include<vector>
#define INF 2501
using namespace std;

int n; int m;
int g[51][51];
vector<pair<int, int>> activatelist;
bool visit[51][51];
int dy[] = { 0,0,1,-1 };
int dx[] = { 1,-1,0,0 };
int d;
int bfs(vector<int>& list) {
	memset(visit, false, sizeof(visit));
	queue<pair<int,pair<int, int>>> q;
	int ans = 0;
	for (int i = 0; i < m; ++i) {
		int y = activatelist[list[i]].first;
		int x = activatelist[list[i]].second;
		//cout << y << "  " << x << endl;
		q.push({ 0,{ y, x } });
		visit[y][x] = true;
	}
	while (!q.empty()) {
		int cnt = q.front().first;
		int y = q.front().second.first;
		int x = q.front().second.second;
		q.pop();
		for (int i = 0; i < 4; ++i) {
			int nexty = y + dy[i];
			int nextx = x + dx[i];
			if (nexty >= 1 && nextx >= 1 && nexty <= n && nextx <= n) {
				if (g[nexty][nextx] == 1) {
					continue;
				}
				else if (g[nexty][nextx] == 2 && !visit[nexty][nextx]) {
					q.push({ cnt + 1, {nexty,nextx} });
					visit[nexty][nextx] = true;
				}
				else {
					if (visit[nexty][nextx]==0 && g[nexty][nextx] == 0) {
						visit[nexty][nextx] = true;
						ans++;
						q.push({ cnt + 1, {nexty, nextx} });
						if (ans == d) {
							return cnt + 1;
						}
					}
				}
			}
		}
	}
	return INF;
}

int sol(int x, int cnt, vector<int> list) {
	if (cnt == m) {
		return bfs(list);
	}
	if (cnt < m && x >= activatelist.size()) {
		return INF;
	}
	int ret = sol(x+1, cnt, list);
	
	list.push_back(x);
	ret = min(ret, sol(x + 1, cnt + 1, list));
	
	return ret;
}

int main() {
	cin >> n >> m;
	d = n * n;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			cin >> g[i][j];
			if (g[i][j] == 1) {
				d -= 1;
			}
			if (g[i][j] == 2) {
				activatelist.push_back({ i,j });
				d -= 1;
			}
		}
	}
	if (d == 0) {
		cout << 0;
		return 0;
	}
	
	vector<int> a;
	int ans = sol(0, 0, a);
	a.push_back(0);
	ans = min(ans, sol(0, 1, a));
	if (ans == INF) {
		cout << -1;
	}
	else {
		cout << ans;
	}
}