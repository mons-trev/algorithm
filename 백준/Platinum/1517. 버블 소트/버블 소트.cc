#include<iostream>
#include<vector>
#define INF 2000000000

using namespace std;

int n;
int arr[500001]; // 1~n까지
long long sum = 0;

vector<int> divide(int left, int right) {
	if (right - left < 1) {
		vector<int> a; a.push_back(arr[left]);
		return a;
	}
	vector<int> leftarr = divide(left, (left + right) / 2);
	vector<int> rightarr = divide(((left + right) / 2) +1, right);
	leftarr.push_back(INF);
	rightarr.push_back(INF);
	int leftsize = leftarr.size()-1;
	int rightsize = rightarr.size() - 1;
	int i = 0;
	int j = 0;
	vector<int> conquer;
	bool flag = false;
	while (leftarr[i] != INF || rightarr[j] != INF) {
		if (leftarr[i] < rightarr[j]) {
			if (rightarr[j] == INF && flag && leftarr[i]!=leftarr[i-1]) {
				sum+= leftsize - 1 - i + rightsize;
			}
			conquer.push_back(leftarr[i]);
			i++;
			flag = false;
		}
		else if (leftarr[i] == rightarr[j]) {
			conquer.push_back(leftarr[i]);
			conquer.push_back(rightarr[j]);
			i++; j++;
			flag = true;
		}
		else {
			conquer.push_back(rightarr[j]);
			j++;
			sum += leftsize - i;
			flag = false;
		}
	}
	return conquer;
}

void merge_sort() {
	divide(1, n);
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> arr[i];
	}
	merge_sort();
	cout << sum;
}
