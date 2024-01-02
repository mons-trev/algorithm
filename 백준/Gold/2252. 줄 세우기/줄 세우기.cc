#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;

int n, m;
vector<int> list[100001];
int topo[32001];
vector<int> ans;
int main() {
	cin >> n >> m;
	memset(topo, 0, sizeof(topo));
	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		topo[b]++;
		list[a].push_back(b);
	}
	queue<int> q;
	for (int i = 1; i <= n; ++i) {
		if (topo[i] == 0) {
			q.push(i);
		}
	}
	while (!q.empty()) {
		int m = q.front();
		q.pop();
		ans.push_back(m);
		for (int i = 0; i < list[m].size(); ++i) {
			topo[list[m][i]]--;
			if (topo[list[m][i]] == 0) {
				q.push(list[m][i]);
			}
		}
	}
	for (int i = 0; i < ans.size(); ++i) {
		cout << ans[i] << " ";
	}
}