#include<iostream>
#include<vector>
#include<string>
#include<cstring>
using namespace std;

int main() {
	int ans = 0;
	int start = 1;
	int n;
	cin >> n;
	while (start <= n) { // n보다 작을 때까지 예를 들어 15면 15까지
		int sum = start;
		int a = start;
		while (sum <= n) {
			if (sum == n) {
				ans++;
				break;
			}
			a++;
			sum += a;
		}
		start++;
	}
	cout << ans;
}