#include <iostream>
#include <vector>
#include <algorithm>
#define MOD 1000000007
using namespace std;

int N;

pair<int, int> points[50];
int px[50], py[50];
int ans[51];

void solve(int r, int c) {
    
    
	vector<int> dist;
    
	for (int i = 0; i < N; i++) {
		dist.emplace_back(abs(points[i].first - r) + abs(points[i].second - c));
	}
    
	sort(dist.begin(), dist.end());

	int psum = 0;
	for (int i = 0; i < N; i++) {
		psum += dist[i];
		ans[i + 1] = min(ans[i + 1], psum);
	}
}

int main() {
    
	cin >> N;
	for (int i = 0; i <= N; i++) ans[i] = MOD;
	for (int i = 0; i < N; i++) {
		int &x = px[i], &y = py[i];
		cin >> x >> y; points[i] = make_pair(x, y);
	}

	sort(px, px + N);
	sort(py, py + N);
	for (int r = 0; r < N; r++) {
		int rr = px[r];
		for (int c = 0; c < N; c++) {
			int cc = py[c];
			solve(rr, cc), solve(rr + 1, cc), solve(rr, cc + 1), solve(rr + 1, cc + 1);
		}
	}

	for (int i = 1; i <= N; i++) cout << ans[i] << ' ';
}