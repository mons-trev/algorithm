#include<iostream>
#include<vector>

using namespace std;

vector<int> a[20001];
int d[20001];

void dfs(int node, int cnt) {
	d[node] = cnt;
	for (int i = 0; i < a[node].size(); i++) {
		if (d[a[node][i]] == 0) {
			dfs(a[node][i], 3 - cnt);
		}
	}
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int u;
		int v;
		cin >> u;
		cin >> v;
		for (int i = 1; i <= u; i++) {
			a[i].clear();
			d[i] = 0;
		}
		
		while (v--) {
			int m;
			int n;
			cin >> m >> n;
			a[m].push_back(n);
			a[n].push_back(m);
		}
		for (int i = 1; i <= u; i++) {
			if (d[i] == 0) {
				dfs(i, 1);
			}
		}
		bool ok = true;
		for (int i = 1; i <= u; i++) {
			int color = d[i];
			for (int j = 0; j < a[i].size();j++) {
				if (color == d[a[i][j]]) {
					ok = false;
				}
			}
		}
		if (ok) {
			cout << "YES\n";
		}
		else {
			cout << "NO\n";
		}
	}
}