#include<iostream>
#include<vector>

using namespace std;
int n;
vector<long long> list;
int main() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		long long tmp; cin >> tmp;
		list.push_back(tmp);
	}
	int l = 0;
	int r = n - 1;
	int left = 0;
	int right = n-1;
	long long sum = 2147000000;
	while (l < r) {
		if (abs(list[l] + list[r]) < abs(sum)) {
			left = l;
			right = r;
			sum = (list[l] + list[r]);
		}
		if (list[l] + list[r] > 0) {
			r--;
		}
		else {
			l++;
		}
	}
	cout << list[left] << " " << list[right];
}