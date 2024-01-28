#include<iostream>
#include<string>

using namespace std;

int dp[1001][1001];

int main() {
	string a, b;
	cin >> a >> b; // a를 열, b를 행
	for (int i = 1; i <= b.size(); ++i) {
		for (int j = 1; j <= a.size(); ++j) {
			if (b[i - 1] == a[j - 1]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}
	int ans = 0;
	for (int i = 1; i <= b.size(); ++i) {
		for (int j = 1; j <= a.size(); ++j) {
			ans = max(ans, dp[i][j]);
		}
	}
	cout << ans;
}
