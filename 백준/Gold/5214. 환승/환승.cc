#include<iostream>
#include<vector>
#include<cmath>
#include<queue>

using namespace std;

vector<int> list[101001];
bool visit[101001] = { false, };

int main() {
	int n, k, m;
	cin >> n >> k >> m;
	for (int i = 1; i <= m; ++i) {
		int h_num = 100000 + i;
		for (int j = 0; j < k; ++j) {
			int a; cin >> a;
			list[a].push_back(h_num);
			list[h_num].push_back(a);
		}
	}
	queue<pair<int, int>> q; //인덱스, 갯수
	q.push({ 1,1 }); //1번부터 시작

	while (!q.empty()) {
		int now = q.front().first;
		int cnt = q.front().second;
		if (visit[now]) {
			q.pop();
			continue;
		}
		visit[now] = true;
		q.pop();
		if (now == n) {
			cout << cnt;
			return 0;
		}
		for (int i = 0; i < list[now].size(); ++i) {
			int next = list[now][i];
			if (!visit[next]) {
				if (next > 100000) {
					q.push({ next,cnt });
				}
				else {
					q.push({ next, cnt + 1 });
				}
			}
		}
	}
	cout << -1;
}