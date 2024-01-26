#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int n;
vector<long long> list;
int main() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		long long tmp; cin >> tmp;
		list.push_back(tmp);
	}
	long long ans = 3000000000;
	long long anslist[3] = { 0, };
	sort(list.begin(), list.end());
	for (int i = 0; i < n; ++i) {
		long long target = list[i];
		int l = 0;
		int r = n - 1;
		int left = 0;
		int right = n - 1;
		long long sum = 21470000000;
		while (l < r) {
			if (l == i) {
				l++;
				continue;
			}
			if (r == i) {
				r--;
				continue;
			}
			if (abs(target+list[l] + list[r]) < abs(sum)) {
				left = l;
				right = r;
				sum = (target+list[l] + list[r]);
			}
			if (target + list[l] + list[r] > 0) {
				r--;
			}
			else {
				l++;
			}
		}
		if (abs(sum) < abs(ans)) {
			anslist[0] = list[left];
			anslist[1] = list[right];
			anslist[2] = list[i];
			ans = target + list[left] + list[right];
		}
	}
	sort(anslist, anslist + 3);
	for (auto i : anslist) {
		cout << i << " ";
	}
}