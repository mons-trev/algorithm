#include<iostream>
#include<vector>
#include<queue>
#define INF 9876543
using namespace std;

vector<pair<int, int>> list[20001];
int main() {
	int v, e;
	cin >> v >> e;
	int des; 
    cin >> des;
	int dp[20001];
	bool visit[20001] = { false, };
	for (int i = 0; i < e; ++i) {
		int a, b, c;
		cin >> a >> b >> c;
		list[a].push_back({ b,c });
	}
	for (int i = 1; i <= v; ++i) {
		dp[i] = INF;
	}
	priority_queue<pair<int, int>> q;
	q.push({ 0, des });
	dp[des] = 0;

    while (!q.empty()) {
		int now = q.top().second;
		int dis = -q.top().first;
		if (visit[now]) {
			q.pop();
			continue;
		}
		visit[now] = true;
		q.pop();
		for (int i = 0; i < list[now].size(); ++i) {
			int next = list[now][i].first;
			int from_to = list[now][i].second;
			if (!visit[next]) {
				if (dis + from_to < dp[next]) {
					dp[next] = dis + from_to;
					q.push({ -(dis + from_to), next });
				}
			}
		}
		}
	for (int i = 1; i <= v; ++i) {
		if (dp[i] == INF) {
			cout << "INF\n";
		}
		else {
			cout << dp[i] << "\n";
		}
	}
}