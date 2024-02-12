#include<iostream>
#include<vector>

using namespace std;

bool dp[2001][2001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	vector<int> list;


	for (int i = 0; i < n; ++i) {
		int tmp; cin >> tmp;
		list.push_back(tmp);
	}
	int m;
	cin >> m;
	
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (i == j) {
				dp[i][j] = true;
			}
			else if (j - i == 1) {//길이가 2라면
				if (list[j] == list[i]) {
					dp[i][j] = true;
				}
				else {
					dp[i][j] = false;
				}
			}
		}

	}
		for (int j = 2; j < n; ++j) {
			int y = 0; int x = j;
			while (true) {
				if (y >= n || x >= n) break;
				if (list[y] == list[x]) {
					dp[y][x] = dp[y + 1][x - 1];
				}
				else {
					dp[y][x] = false;
				}
				y++; x++;
			}
		}
	for (int i = 0; i < m; ++i) {
		int a, b; cin >> a >> b;
		//f.push_back({ min(a, b), max(a, b) });
		cout << dp[a-1][b-1] << "\n";
	}
	
}