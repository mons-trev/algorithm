#include <iostream>
#include<vector>
#include<stack>
using namespace std;

vector<long long> list;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	list.push_back(0);

	for (int i = 1; i <= n; ++i) {
		long long tmp; cin >> tmp;
		list.push_back(tmp);
	}

	list.push_back(0);
	stack<int> s; // ids 저장

	s.push(0);

	long long ans = 0;

	for (int i = 1; i <= n+1; ++i) {
		if (s.empty() || list[s.top()] <= list[i]) {
			s.push(i);
		}
		else {
			while (true) {
				if (s.empty() || list[s.top()] <= list[i]) {
					break;
				}
				else {
					long long idx = s.top();
					long long h = list[s.top()];
					s.pop();
					ans = max(ans, (i-1-s.top()) * h);
				}
			}
			s.push(i);
		}
	}
	
	cout << ans;
}