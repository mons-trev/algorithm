#include <iostream>
#include<queue>

using namespace std;

int l[5000001];

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n; int L;
	cin >> n >> L;
	priority_queue<pair<int, int>> q;
	for (int i = 1; i <= n; ++i) {
		cin >> l[i];

	}
	
	for (int i = 1; i <= n; ++i) {
		q.push({ -l[i],i });
		
		while (!q.empty()) {
			int mpoint = q.top().second;
			if ((mpoint < i-L+1)) {
				q.pop();
			}
			else {
				break;
			}
		}
		
		cout << -q.top().first << " ";
	}
}