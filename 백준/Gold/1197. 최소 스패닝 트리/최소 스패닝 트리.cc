#include<iostream>
#include<cmath>
#include<vector>
#include<queue>
#include<cstring>

using namespace std;

vector<pair<int,int>> list[10001];
bool visit[10001];

int main() {
	int v, e;
	cin >> v >> e;
	
	for (int i = 0; i < e; ++i) {
		int a, b, c;
		cin >> a >> b >> c;
		list[a].push_back({ b,c });// index,cost
		list[b].push_back({ a,c });
	}
	priority_queue<pair<int, int>> q; // cost, index
	
	memset(visit, false, sizeof(visit));
	for (int i = 0; i < list[1].size(); ++i) {//1번노드부터 넣기
		q.push({ -list[1][i].second, list[1][i].first });
	}
	visit[1] = true;
	int sum = 0;
	int it = 1;
	while (!q.empty()) {
		int now = q.top().second;
		if (visit[now]) {
			q.pop();
			continue;
		}
		sum += -q.top().first;
		visit[now] = true;
		q.pop();
		if (++it == v) {
			break;
		}

		for (int i = 0; i < list[now].size(); ++i) {
			int next = list[now][i].first;
			int c = list[now][i].second;
			if (!visit[next]) {
				q.push({ -c,next });
			}
		}
	}
	cout << sum;
}