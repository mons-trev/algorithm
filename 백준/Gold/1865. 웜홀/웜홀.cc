#include<iostream>
#include<cmath>
#include<cstring>
#include<vector>
#include<queue>
#define INF 5000000
using namespace std;
int n, m, w;
int dp[501];
bool sol(vector<vector<pair<int, int>>> &mlist, vector<vector<pair<int, int>>> &wlist, int start) {

	priority_queue<int> pq;
	pq.push(start); dp[start] = 0;

	while (!pq.empty()) {
		int m = pq.top();
		pq.pop();
		for (int i = 0; i < wlist[m].size(); ++i) {
			int a = wlist[m][i].first;
			int b = wlist[m][i].second; // 음수 형태로 나온다
			if (a == start && dp[m] + b < 0) {
				return true;
			}
			if (dp[m] + b < dp[a]) {
				if (dp[a] < 0) {
					return true;
				}
				dp[a] = dp[m] + b;
				pq.push(a);
			}
			//pq.push({ a,-(dp[m] + b) });
		}
		for (int i = 0; i < mlist[m].size(); ++i) {
			int a = mlist[m][i].first;
			int b = mlist[m][i].second; // 1로 다시 간선으로 되돌아갈 때
			if (a == start && dp[m] + b < 0) {
				return true;
			}
			if (dp[m] + b < dp[a]) {
				if (dp[a] < 0) { // 이미 음순데 더 음수가 된다는 건 한 음수 사이클일 때=> true
					return true;
				}
				dp[a] = dp[m] + b;
				pq.push(a);
			}
		}
		
	}
	return false;
}

int main() {
	int tc; cin >> tc;
	while (tc--) {
		vector<vector<pair<int,int>>> mlist;
		vector<vector<pair<int,int>>> wlist;
		
		cin >> n >> m >> w;
		for (int i = 0; i < n+1; ++i) {
			mlist.push_back({});
			wlist.push_back({});
		}
		for (int i = 0; i < m; ++i) {
			int a; int b; int c; cin >> a >> b >> c;
			mlist[a].push_back({ b,c });
			mlist[b].push_back({ a, c });
		}
		for (int i = 0; i < w; ++i) {
			int a; int b; int c; cin >> a >> b >> c;
			wlist[a].push_back({ b,-c });
		}
		bool flag = false;
		for (int i = 0; i <= n; ++i) {
			dp[i] = INF;
		}
		for (int i = 1; i <= n; ++i) {
			if (dp[i] == INF) {
				if (sol(mlist, wlist, i)) {
					cout << "YES" << "\n";
					flag = true;
					break;
				}
			}
		}
		if (!flag) {
			cout << "NO" << "\n";
		}
	}
}