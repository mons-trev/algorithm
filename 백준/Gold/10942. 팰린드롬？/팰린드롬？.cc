#include <iostream>
#include<queue>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int n,m;
int list[2001];
vector<pair<int, int>> v;
int dp[2001][2001];


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> list[i];
	}
	cin >> m;
	for (int i = 0; i < m; ++i) {
		int a, b; cin >> a >> b;
		v.push_back({ min(a,b),max(a,b) });
	}
	for (int i = 0; i < m; ++i) {
		int f, t;
		f = v[i].first; t = v[i].second;
		bool flg = false;
		while (f < t) {
			if (dp[f][t] == -1) {
				cout << 0 << "\n";
				flg = true;
				dp[v[i].first][v[i].second] = -1;
				break;
			}
			else if (dp[f][t] == 1) {
				cout << 1 << "\n";
				dp[v[i].first][v[i].second] = 1;
				flg = true;
				break;
			}
			else {
				if (list[f] != list[t]) {
					dp[f][t] = -1;
					flg = true;
					cout << 0 << "\n";
					dp[v[i].first][v[i].second] = -1;
					break;
				}
				else {
					f++;
					t--;
				}
			}
		}
		if (!flg) {
			dp[v[i].first][v[i].second] = 1;
			cout << 1 << "\n";
		}
	}
}