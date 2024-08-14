#include<iostream>
#include<queue>

using namespace std;

int n, m;
vector<vector<int>> arrlist;
bool visit[101];
int main() {
	cin >> n >> m;
	for (int i = 0; i <= n; ++i) {
		arrlist.push_back({});
	}
	for (int i = 0; i < m; ++i) {
		int from; cin >> from;
		int to; cin >> to;
		arrlist[from].push_back(to);
		arrlist[to].push_back(from);
	}
	queue<int> q;
	visit[1] = true;
	for (int i = 0; i < arrlist[1].size(); ++i) {
		q.push(arrlist[1][i]);
		visit[arrlist[1][i]] = true;
	}
	int ans = 0;
	while (!q.empty()) {
		int from = q.front();
		ans++;
		q.pop();
		for (int i = 0; i < arrlist[from].size(); ++i) {
			if (!visit[arrlist[from][i]]) {
				q.push(arrlist[from][i]);
				visit[arrlist[from][i]] = true;
			}
		}
	}
	cout << ans;
}