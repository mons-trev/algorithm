#include<iostream>
#include<vector>
#include<queue>
#include<cmath>
#include<cstring>
#include<tuple>
#include<algorithm>
#define INF 3000000000

using namespace std;
int n;
vector<pair<int, int>> x;
vector<pair<int, int>> y;
vector<pair<int, int>> z;
int parent[100001];

int fin(int a) {
	if (parent[a] == a) {
		return a;
	}
	return parent[a]=fin(parent[a]);
}

void uni(int a, int b) {
	a = fin(a);
	b = fin(b);
	if (a < b) {
		parent[b] = a;
	}
	else {
		parent[a] = b;
	}
}

bool cmp(pair<int, int> a, pair<int, int>b) {
	if (a.second < b.second) {
		return true;
	}
	else if (a.second > b.second) {
		return false;
	}
	else {
		return false;
	}
}

//단순하게 node를 담는 벡터를 만들고 mst 알고리즘을 쓰면 시간초과 발생
int main() {
	cin >> n;
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		int ix, iy, iz;
		parent[i] = i;
		cin >> ix >> iy >> iz;
		x.push_back({ i,ix });//노드번호, x
		y.push_back({ i,iy });//노드번호, y
		z.push_back({ i,iz });//노드번호, z
	}
	sort(x.begin(), x.end(), cmp);
	sort(y.begin(), y.end(), cmp);
	sort(z.begin(), z.end(), cmp);
	priority_queue<pair<int, pair<int, int>>> q; //비용, 좌표
	for (int i = 1; i < n; ++i) {
		int prevx = x[i].first;
		int postx = x[i - 1].first;
		int distx = x[i].second - x[i - 1].second;		
		q.push({ -distx,{prevx,postx} });
		int prevy = y[i].first;
		int posty = y[i - 1].first;
		int disty = y[i].second - y[i - 1].second;
		q.push({ -disty,{prevy,posty} });
		int prevz = z[i].first;
		int postz = z[i - 1].first;
		int distz = z[i].second - z[i - 1].second;
		q.push({ -distz,{prevz,postz} });
	}
	while (!q.empty()) {
		int node1 = q.top().second.first;
		int node2 = q.top().second.second;
		int dist = -q.top().first;
		q.pop();
		if (fin(node1) != fin(node2)) { // 사이클이면
			uni(node1, node2);
			ans += dist;
		}
	}
	cout << ans;
}
