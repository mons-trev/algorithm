#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

int w[31];
int dp[31][15001];
int main() {
	int n; cin >> n;

	w[0] = 0;
	for (int i = 1; i <= n; ++i) {
		cin >> w[i];
	}

	// dp 돌리기

	for (int i = 0; i <= n; ++i) {
		for (int j = 0; j < 15001; ++j) {
			if (i == 0) {
				if (j == 0) dp[i][j] = 1;
				else {
					dp[i][j] = 0;
				}
			}
			else {
				if (dp[i - 1][j] > 0) {
					dp[i][j + w[i]]++;
					//can[j + w[i]] = true;
					dp[i][abs(j - w[i])]++;
					//can[abs(j - w[i])] = true;
					dp[i][j]++;
					//can[j] = true;
				}
			}
		}
	}

	int b; cin >> b;
	for (int i = 0; i < b; ++i) {
		int tmp; cin >> tmp;
		if (tmp > 15000) cout << "N";
		else {
			if (dp[n][tmp]) cout << 'Y';
			else cout << "N";
		}
		cout << " ";
	}

}