#include<iostream>
#include<vector>
#include<cstring>
#include<math.h>
using namespace std;

vector<long long> prime; //소수
vector<long long> dp; //누적합
bool check[4000001];
long long n;

void era() {
	//int nn = sqrt(4000001);
	int cut = 0;
	for (long long i = 2; i*i <= 4000001; ++i) {
		if (!check[i]) {
			prime.push_back(i);
			if (dp.size() > 0) {
				dp.push_back({ dp[dp.size() - 1] + i });
			}
			else {
				dp.push_back(i);
			}
			for (long long j = i * i; j < 4000001; j += i) {
				check[j] = true;
			}
		}
		cut = i;
	}
	for (int i=cut+1; i < 4000001; ++i) {
		if (!check[i]) { 
			prime.push_back({ i });
			dp.push_back({ dp[dp.size() - 1] + i });
		}
	}
}

int main() {
	cin >> n;
	
	era(); // 에라토스테네스 체로 소수 만들기
	
	int ans = 0;

	if (n < 4) { // 2,3,4이 들어오면 경우의 수가 없으므로 0 리턴
		if (n == 1) {
			cout << 0;
			return 0;
		}
		cout << 1;
		return 0;
	}
	
	int left = 0;
	int right = 1;
	int sum = 0;
	for (int i = 0; i < dp.size(); ++i) {
		if (dp[i] >= n) {
			right = i;
			break;
		}
	}
	for (int i = 0; i < right; ++i) {
		if (dp[right] - dp[i] <= n) {
			left = i;
			break;
		}
	}
	if (left == 0) {
		sum = dp[right];
	}
	else {
		sum = dp[right] - dp[left - 1];
	}
	//cout << left << " " << right << " " << sum << endl;
	while (left<right) {
		
		if (sum == n) {
			ans++;
			if (right + 1 < prime.size() && prime[right + 1] <= n) {
				right += 1;
				sum += prime[right];
			}
		}
		else if (sum > n) {
			sum -= prime[left];
			left += 1;
		}
		else {
			if (right + 1 < prime.size() && prime[right + 1] <= n) {
				right += 1;
				sum += prime[right];
			}
		}
	}
	if (!check[n]) ans++;
	cout << ans;
}
