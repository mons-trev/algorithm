#include<iostream>
#include<queue>

using namespace std;

int main() {
	int n; cin >> n;
	
	priority_queue<int> q;

	for (int i = 0; i < n; ++i) {
		int a; cin >> a;
		q.push(-a);
	}
	int cnt = 0;
	int ans = 0;
	while (true) {
		if (cnt == n - 1) break;
		int num1 = -q.top();
		q.pop();
		int num2 = -q.top();
		q.pop();
		q.push(-(num1 + num2));
		ans += num1 + num2;
		cnt++;
	}
	cout << ans;
}