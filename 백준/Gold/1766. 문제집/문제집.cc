#include<iostream>
#include<vector>
#include<cmath>
#include<cstring>
#include<queue>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	vector<short> list[32001];
	short topo[32001] = { 0, };
	vector<short> ans;
	for (int i = 0; i < m; ++i) {
		short a, b;
		cin >> a >> b;
		list[a].push_back(b);
		topo[b]++;
	}
	priority_queue<short> q;
	for (short i = 1; i <= n; ++i) {
		if (topo[i] == 0) {
			q.push(-i);
		}
	}
	while (!q.empty()) {
		short now = -q.top();
		ans.push_back(now);
		q.pop();
		for (int i = 0; i < list[now].size(); ++i) {
			topo[list[now][i]]--;
			if (topo[list[now][i]] == 0) {
				q.push(-list[now][i]);
			}
		}
	}
	for (short i = 0; i < ans.size(); ++i) {
		cout << ans[i] << " ";
	}
}