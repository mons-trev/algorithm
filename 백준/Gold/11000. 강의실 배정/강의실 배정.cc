#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

int n;
vector<pair<int, int>> c;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;


	for (int i = 0; i < n; ++i) {
		int s, f; cin >> s >> f;
		c.push_back({ s, f });
	}
	
	sort(c.begin(), c.end());

	priority_queue<pair<int, int>> q;

	q.push({ -c[0].second, c[0].first });

	for (int i = 1; i < n; ++i) {
		int st = c[i].first;
		int f = c[i].second;
		if (-q.top().first <= st) {
			q.pop();
			q.push({ -f, st });
		}
		else {
			q.push({ -f, st });
		}
	}
	cout << q.size();
}