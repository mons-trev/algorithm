#include<iostream>
#include<vector>
using namespace std;

vector<int> list;
vector<long long> dp;
int n, s;


int main() {
	cin >> n >> s;
	list.push_back(0);
	dp.push_back(0);
	for (int i = 0; i < n; ++i) {
		int tmp; cin >> tmp;
		list.push_back(tmp);
		dp.push_back(dp[dp.size() - 1] + tmp);
		//cout << list[i] << " " << dp[i] << endl;
		
	}
	
	int left = 0;
	int right = 1;
	int sum = 0;
	int ans = n + 2;
	for (int i = 1; i < dp.size(); ++i) {
		if (dp[i] >= s) {
			right = i;
			break;
		}
	}

	for (int i = 0; i < right; ++i) {
		if (dp[right] - dp[i] >= s) {
			left = i;
		}
	}
	if (left == right) {
		sum = list[right];
	}
	else {
		sum = dp[right] - dp[left];
	}
	while (right<=n) {

		if (sum >= s) {
			//cout << left << " " << right << " " << sum << "\n";

			ans = min(ans, right - left);
			if (left + 1 < right) {
				left++;
				sum -= list[left];
			}
			else {
				if (right + 1 > n) {
					break;
				}
				right++;
				sum += list[right];
			}
		}
		
		else {
			if (right + 1 <= n) {
				sum += list[right + 1];
				right++;
			}
			else {
				break;
			}
		}
	}
	if (ans == n + 2) {
		cout << 0;
	}
	else {
		cout << ans;
	}
}