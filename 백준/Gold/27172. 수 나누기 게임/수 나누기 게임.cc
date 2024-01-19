#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

long n;
vector<int> list;
bool iselement[1000001];
int ans[10000001];
int main() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		int tmp; cin >> tmp;
		list.push_back(tmp);
		iselement[tmp] = true;
	}

	for (int i = 0; i < n; ++i) {
		int target = list[i];
		for (int j = 1; j * j <= target; ++j) {
			if (iselement[j]) {
				if (target % j == 0) {
					ans[j]++;
					ans[target]--;
				}
			}
			if (iselement[target / j]) {
				if ((target % (target / j)) == 0 && (target / j)* (target / j) !=target) {
					ans[target / j] ++;
					ans[target]--;
				}
			}
		}
	}
	for (int i = 0; i < n; ++i) {
		cout << ans[list[i]] << " ";
	}
}