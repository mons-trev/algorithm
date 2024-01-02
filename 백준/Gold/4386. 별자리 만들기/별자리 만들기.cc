#include<iostream>
#include<vector>
#include<cmath>
#include<cstring>
#include<queue>
#include<iomanip>

using namespace std;
int n;
vector<pair<double, double>> star;
double g[101][101];
bool v[101];
int main() {
	cin >> n;
	memset(g, 0, sizeof(g));
	memset(v, false, sizeof(v));
	star.push_back({}); // 0번은 무효
	for (int i = 0; i < n; ++i) {
		double x; double y; cin >> x >> y;
		star.push_back({ x,y });
	}

	for (int i = 1; i < n; ++i) {
		double ix = star[i].first;
		double iy = star[i].second;
		for (int j = i + 1; j <= n; ++j) {
			double jx = star[j].first;
			double jy = star[j].second;
			double dist = (ix - jx) * (ix - jx) + (iy - jy) * (iy - jy);
			dist = sqrt(dist);
			g[i][j] = g[j][i] = dist;
		}
	}
	priority_queue<pair<double, int>> q;
	for (int i = 2; i <= n; ++i) {
		q.push({ -g[1][i],i });
	}
	v[1] = true;
	double ans = 0;
	while (!q.empty()) {
		int now = q.top().second;
		double dis = -q.top().first;
		q.pop();
		if (v[now]) continue;
		ans += dis;
		v[now] = true;
		for (int i = 1; i <= n; ++i) {
			int next = i;
			if (!v[next]) {
				q.push({ -g[now][next], next });
			}
		}
	}
	cout << setprecision(2);
	cout << fixed;
	cout << ans;
}