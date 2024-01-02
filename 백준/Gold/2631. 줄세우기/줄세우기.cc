#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int main() {
	int n; cin >> n;
	vector<int> arr;
	for (int i = 0; i < n; ++i) {
		int tmp; cin >> tmp;
		arr.push_back(tmp);
	}

	vector<int> dp;
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		int sub = 0;
		for (int j = 0; j < i; ++j) {
			if (arr[i] > arr[j]) {
				sub = max(sub, dp[j]);
			}
		}
		dp.push_back(sub + 1);
		ans = max(ans, dp[i]);
	}
	cout << n - ans;
}