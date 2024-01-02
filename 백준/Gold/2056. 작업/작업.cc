#include<iostream>
#include<vector>
#include<cstring>
#include<queue>
#include<cmath>
using namespace std;

int n;
int ti[10001]; // 수행하는데 걸리는 시간
vector<int> adj[10001]; // 인접리스트
int topo[10001]; //선행노드갯수
int dp[10001];

int main() {
	cin >> n;
	memset(topo, 0, sizeof(topo));
	memset(dp, 0, sizeof(dp));
	for (int i = 1; i <= n; ++i) {
		cin >> ti[i];//i를 수행하는데 걸리는 시간
		int a; cin >> a;//i의 선행 노드 갯수
		topo[i] = a;
		for (int j = 0; j < a; ++j) {
			int b; cin >> b;
			adj[b].push_back(i);
		}
	}
	queue<int> q;
	for (int i = 1; i <= n; ++i) {
		if (topo[i] == 0) { 
			dp[i] = ti[i];
			q.push(i);
		}
	}
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		for (int i = 0; i < adj[now].size(); ++i) {
			int next = adj[now][i];
			dp[next] = max(dp[next], dp[now] + ti[next]);
			topo[next]--;
			if (topo[next] == 0) {
				q.push(next);
			}
		}
	}
	int ans = -1;
	for (int i = 1; i <= n; ++i) {
		ans = max(ans, dp[i]);
	}
	cout << ans;
}