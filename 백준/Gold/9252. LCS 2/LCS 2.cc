#include<iostream>
#include<cmath>

using namespace std;
int dp[1001][1001];
string s1;
string s2;

string dfs(int y, int x) {
	if (dp[y][x] == 0 || y < 1 || x < 1) {
		return "";
	}

	if (dp[y][x] > dp[y][x - 1] && dp[y][x] > dp[y - 1][x]) {
		//cout << y<<x << s1[x] << endl;
		return dfs(y - 1, x - 1) + s1[x-1];
	}
	else if (dp[y][x - 1] == dp[y][x]) {
		return dfs(y, x - 1);
	}
	else {
		return dfs(y - 1, x);
	}
}

int main() {
	cin >> s1;
	cin >> s2;
	//cout << s1.size() << " " << s2.size() << endl;
	//s2 행 s1 열
	for (int i = 0; i <= s2.size(); ++i) {
		for (int j = 0; j <= s1.size(); ++j) {
			dp[i][j] = 0;
		}
	}

	for (int i = 1; i <= s2.size(); ++i) {
		char c = s2[i - 1];
		for (int j = 1; j <= s1.size(); ++j) {
			char c2 = s1[j - 1];
			if (c == c2) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}
	

	string ans = "";
	
	ans = dfs(s2.size(), s1.size());

	if (dp[s2.size()][s1.size()] == 0) {
		cout << dp[s2.size()][s1.size()]; return 0;
	}
	cout << dp[s2.size()][s1.size()] << "\n" << ans;

}