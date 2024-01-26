#include<iostream>
#include<queue>
#define INF 100000000
using namespace std;

int g[1001][1001];
int n, m, x;
int ans[1001];
bool check[1001];


int main() {
	cin >> n >> m >> x;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			g[i][j] = INF;
		}
	}
	for (int i = 1; i <= m; ++i) { //단방향 입력
		int from, to, dist;
		cin >> from >> to >> dist;
		g[from][to] = dist;
	}

	for (int i = 1; i <= n; ++i) {
		if (i == x) continue;

		priority_queue<pair<int,pair<int, int>>> q;
		//작은 것이 앞에 나와야 하므로 거리에 음수 붙이기

		for (int j = 1; j <= n; ++j) check[j] = false;
		check[i] = true;

		for (int j = 1; j <= n; ++j) { // 첫번째 원소 큐에 넣기
			if (i == j) continue;
			if (g[i][j] == INF) continue;
			q.push({ -g[i][j],{i,j} });
		}
		while (!q.empty()) {
			int dist = -q.top().first;
			int from = q.top().second.first;
			int to = q.top().second.second;
			check[to] = true;
			q.pop();
			if (to == x) {
				//cout << i << dist << from << to << endl;
				ans[i] = dist;
				break;
			}
			for (int j = 1; j <= n; ++j) {
				if (to == j || check[j] || g[to][j]==INF) continue;
				else {
					q.push({ -(dist+g[to][j]), {to,j} });
				}
			}
		}

	}

	priority_queue<pair<int, pair<int, int>>> q;
	for (int j = 1; j <= n; ++j) check[j] = false;
	check[x] = true;
	for (int i = 1; i <= n; ++i) { // 첫번째 원소 큐에 넣기
		if (x == i) continue;
		if (g[x][i] == INF) continue;
		q.push({ -g[x][i],{x,i} });
	}

	while (!q.empty()) {
		int dist = -q.top().first;
		int from = q.top().second.first;
		int to = q.top().second.second;
		q.pop();
		if (check[to]) continue;
		else {
			check[to] = true;
			ans[to] += dist;
		}
		for (int i = 1; i <= n; ++i) {
			if (g[to][i] == INF || check[i]) continue;
			else {
				q.push({ -(dist + g[to][i]), {to, i} });
			}
		}
	}


	int max = 0;
	for (int i = 1; i <= n; ++i) {
		if (ans[i] > max) {
			max = ans[i];
		}
	}
	cout << max;
}