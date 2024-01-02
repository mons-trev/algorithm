#include<iostream>
#include<cstring>
#include<cmath>
#include<queue>
#define INF 40000000
using namespace std;

int w[301][301];
int n;
bool visit[301];
int prim() {
	priority_queue<pair<int, pair<int, int>>> q;
	visit[0] = true;
	for (int i = 1; i <= n; ++i) {
		if (!visit[i] && w[0][i]!=0) {
			q.push({ -w[0][i], {0,i} });
		}
	}
	int ans = 0;
	int cnt = 1;
	while (!q.empty()) {
		int from = q.top().second.second;
		if (visit[from]) {
			q.pop();
			continue;
		}
		ans += (-q.top().first);
		visit[from] = true;
		cnt++;
		if (cnt == n + 1) return ans;
		q.pop();
		for (int i = 0; i <= n; ++i) {
			if (!visit[i] && w[from][i] != 0) {
				q.push({ -w[from][i], {from, i} });
			}
		}
	}
	return ans;
}

int main() {
	cin >> n;
	w[0][0] = 0;
	memset(visit, false, sizeof(visit));
	for (int i = 1; i <= n; ++i) { // 0번 노드 추가 한 다음, 프림 알고리즘 시행
		cin >> w[0][i];
		w[i][0] = w[0][i];
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			cin >> w[i][j];
			w[j][i] = w[i][j];
		}
	}
	cout << prim();
}