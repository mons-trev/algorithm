#include<iostream>
#include<algorithm>
using namespace std;

long long dp[3][1001];
int cost[3][1001];

long long sol(int n) {
	for (int i = 0; i < 3; i++) {
		dp[i][1] = cost[i][1];
	}
	for (int i = 2; i < n + 1; i++) {
		for (int j = 0; j < 3; j++) {
			if (j == 0) {
				dp[j][i] = min(dp[1][i - 1], dp[2][i - 1]) + cost[j][i];
			}
			if (j == 1) {
				dp[j][i] = min(dp[2][i - 1], dp[0][i - 1]) + cost[j][i];
			}
			if (j == 2) {
				dp[j][i] = min(dp[0][i - 1], dp[1][i - 1]) + cost[j][i];
			}
		}
	}
	
	long long min=dp[0][n];
	for (int i = 1; i < 3; i++) {
		if (min > dp[i][n]) min = dp[i][n];
	}
	return min;
}

int main() {
	int n;
	cin >> n;
	for (int i = 1; i < n + 1; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> cost[j][i];
		}
	}

	cout << sol(n);
}