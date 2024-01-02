#include<iostream>
#include<vector>
#include<cmath>
#include<queue>


using namespace std;

int main() {

	int n; cin >> n;
	vector<int> list[501];
	int dp[501];
	int cnt = 0;
	int time[501];
	int topo[501] = { 0, };
	while (true) {
		cnt++;
		if (cnt > n) break;
		cin >> time[cnt];
		while (true) {
			int a;
			cin >> a;
			if (a == -1) {
				break;
			}
			list[a].push_back(cnt);
			topo[cnt]++;
		}
	}
	
	queue<int> q;
	for (int i = 1; i <= n; ++i) {
		if (topo[i] == 0) {
			q.push(i);
		}
		dp[i] = time[i];
	}
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		for (int i = 0; i < list[now].size(); ++i) {
			int next = list[now][i];
			topo[next]--;
			dp[next] = max(dp[next], dp[now] + time[next]);
			if (topo[next] == 0) {
				q.push(next);
			}
		}
	}
	for (int i = 1; i <= n; ++i) {
		cout << dp[i] << endl;
	}
}