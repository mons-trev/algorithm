#include<iostream>
#include<cmath>
#include<cstring>
#include<queue>
#define INF 10001
using namespace std;
int n, m;
int graph[1001][1001];
bool v[1001];
int main() {
	cin >> n >> m;
	memset(v, false, sizeof(v));
	for (int i = 0; i <= n; ++i) {
		for (int j = 0; j <= n; ++j) {
			graph[i][j] = INF;
		}
	}
	for (int i = 0; i < m; ++i) {
		int f, t, c;
		cin >> f >> t >> c;
		graph[f][t] = min(graph[f][t],c);
		graph[t][f] = min(graph[t][f],c);
	}

	int ans = 0;
	priority_queue<pair<int, int>> q; //비용, 인덱
	//1번 노드부터 시작

	for (int i = 2; i <= n; ++i) {
		q.push({ -graph[1][i], i });
	}
	v[1] = true;
	while (!q.empty()) {
		int now = q.top().second;
		int cost = -q.top().first;
		q.pop();
		if (v[now]) {
			continue;
		}
		v[now] = true;
		ans += cost;
		for (int i = 2; i <= n; ++i) {
			int next = i;
			if (!v[next]) {
				q.push({ -graph[now][next], next });
			}
		}
	}
	cout << ans;
}