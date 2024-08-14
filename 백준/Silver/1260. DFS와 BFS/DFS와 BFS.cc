#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;

int n, m, v;
vector<int> list[1001];
vector<int> dfsres;
vector<int> bfsres;
bool visit[1001];

void dfs(int node, int cnt) {
	if (!visit[node]&& (cnt == n)) {
		dfsres.push_back(node);
		visit[node] = true;
		return;
	}
	visit[node] = true;
	dfsres.push_back(node);
	for (int i = 0; i < list[node].size(); ++i) {
		if (!visit[list[node][i]]) {
			dfs(list[node][i], cnt + 1);
		}
	}
	return;
}

void bfs(int node) {
	queue<int> q;
	q.push(node);
	visit[node] = true;
	while (!q.empty()) {
		int m = q.front();
		q.pop();
		bfsres.push_back(m);
		for (int i = 0; i < list[m].size(); ++i) {
			if (!visit[list[m][i]]) {
				q.push(list[m][i]);
				visit[list[m][i]] = true;
			}
		}
	}

}

int main() {
	cin >> n >> m >> v;
	for (int i = 0; i < m; ++i) {
		int a, b; cin >> a >> b;
		list[a].push_back(b);
		list[b].push_back(a);
	}
	
	for (int i = 1; i <= n; ++i) {
		sort(list[i].begin(), list[i].end());
	}
	dfs(v,1);
	memset(visit, false, sizeof(visit));
	bfs(v);
	for (int i = 0; i < dfsres.size(); ++i) {
		cout << dfsres[i] << " ";
	}
	cout << "\n";
	
	for (int i = 0; i < bfsres.size(); ++i) {
		cout << bfsres[i] << " ";
	}
	
}