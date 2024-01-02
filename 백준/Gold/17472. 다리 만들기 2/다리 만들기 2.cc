#include<iostream>
#include<vector>
#include<queue>
#include<cmath>
#include<algorithm>
using namespace std;

int n, m;
int g[11][11];
int visit[11][11];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int parent[7];
vector<pair<int, int>> list[7];
vector<vector<vector<pair<int, int>>>> bridge(7, vector<vector<pair<int, int>>>(7,vector<pair<int, int>>(0)));

void dfs(int y, int x, int cnt) {
	visit[y][x] = true;
	g[y][x] = cnt;
	list[cnt].push_back({ y,x });
	for (int i = 0; i < 4; ++i) {
		int nexty = y + dy[i];
		int nextx = x + dx[i];
		if (nexty > 0 && nextx > 0 && nexty < n + 1 && nextx < m + 1) {
			if (!visit[nexty][nextx] && g[nexty][nextx] == 1) {
				dfs(nexty, nextx, cnt);
			}
		}
	}
}

int find(int a) {
	if (parent[a] == a) {
		return a;
	}
	return parent[a] = find(parent[a]);
}

void unite(int a, int b) {
	int roota = find(a);
	int rootb = find(b);
	if (roota < rootb) {
		parent[rootb] = roota;
	}
	else {
		parent[roota] = rootb;
	}
}

void makebridge(int isl_num, int y, int x, int k) {
	int cnt = 0;
	bool flag = false;
	int node;
	vector<pair<int, int>> tmp;
	while (y > 0 && x > 0 && y <= n  && x <= m ) {
		y += dy[k];
		x += dx[k];
		if (y<1 || y>n || x<1 || x>m) {
			break;
		}
		if (g[y][x] == isl_num) {
			break;
		}
		if (g[y][x] != 0 && g[y][x] != isl_num) {
			flag = true;
			node = g[y][x];
			break;
		}
		cnt++;
		tmp.push_back({ y,x });
	}
	if (flag && cnt>1) {
		if (bridge[isl_num][node].size() == 0) {
			bridge[isl_num][node] = tmp;
		}
		else if (tmp.size() < bridge[isl_num][node].size()) {
			bridge[isl_num][node] = tmp;
		}
	}
}

int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			cin >> g[i][j];
		}
	}
	int cnt = 1;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			if (!visit[i][j] && g[i][j]==1) {
				dfs(i, j, cnt);
				cnt++;
			}
		}
	}
	cnt--;
	for (int i = 1; i <= cnt; ++i) {
		parent[i] = i;
	}
	for (int i = 1; i <= cnt; ++i) {
		for (int j = 0; j < list[i].size(); ++j) {
			int y = list[i][j].first;
			int x = list[i][j].second;
			for (int k = 0; k < 4; ++k) {
				makebridge(i, y, x, k);
			}
		}
	}
	int ans = 0;
	priority_queue<pair<int, pair<int, int>>> q;
	for (int i = 1; i <= cnt; ++i) {
		for (int j = 1; j <= cnt; ++j) {
			if (bridge[i][j].size() != 0) {
				q.push({ -(int)bridge[i][j].size(), {i,j} });
			}
		}
	}
	int it = 0;
	while (!q.empty()) {
		int node1 = q.top().second.first;
		int node2 = q.top().second.second;
		int distance = -q.top().first;
		
		q.pop();
		if (it == cnt-1) {
			cout << ans;
			return 0;
		}
		if (find(node1) != find(node2)) {
			it++;
			unite(node1, node2);
			ans += distance;
		}
	}
	if (it == cnt - 1) {
		cout << ans;
	}
	else {
		cout << -1;
	}
}