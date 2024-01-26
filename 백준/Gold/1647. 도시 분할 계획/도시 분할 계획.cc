#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;


vector<pair<int, int>> g[100001];
int n, m;
bool check[100001];
vector<long long> ans;

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; ++i) {
		int from, to, dist;
		scanf("%d %d %d", &from, &to, &dist);
		g[from].push_back({ dist, to });
		g[to].push_back({ dist,from });
	}
	
	priority_queue<pair<int, pair<int, int>>> q;
	for (int i = 0; i < g[1].size(); ++i) {
		q.push({ -g[1][i].first,{1,g[1][i].second } });
	}
	check[1] = true;
	long long sum = 0;
	while (!q.empty()) {
		int dist = -q.top().first;
		int from = q.top().second.first;
		int to = q.top().second.second;
		q.pop();
		if (check[to]) continue;
		else {
			check[to] = true;
			sum += dist;
			ans.push_back({ dist });
		}
		for (int i = 0; i < g[to].size(); ++i) {
			if (!check[g[to][i].second]) {
				q.push({ -g[to][i].first, {to, g[to][i].second} });
			}
		}
	}

	sort(ans.begin(), ans.end());
	
	if (ans.size() == 1) printf("0");
	else {
		printf("%lld", sum - ans[ans.size() - 1]);
	}
}
