#include <iostream>
#include <algorithm>

using namespace std;

int arr[1000];
int in [1000];
int dp[1000];

void go(int a) {
	
	if (arr[a] < 0) {
		cout << in[a] << " ";
		return;
	}
	go(arr[a]);
	cout << in[a]<< " ";
	
}

int main() {
	int a;
	cin >> a;
	
	for (int i = 0; i < a; i++) {
		cin >> in[i];
	}
	
	for (int i = 0; i < a; i++) {
		dp[i] = 1;
		arr[i] = -1;
		for (int j = 0; j < i; j++) {
			if (in[j] < in[i] && dp[i] < dp[j] + 1) {
				dp[i] = dp[j] + 1;
				arr[i] = j;
			}
		}
	}
	/*
	for (int i = 0; i < a; i++) {
		cout << arr[i] << " ";
	}
	*/
	
	int maxvalue=dp[0];
	int maxidx = 0;

	for (int i = 0; i < a-1; i++) {
		if (maxvalue < dp[i + 1]) {
			maxvalue = dp[i + 1];
			maxidx = i+1;
		}
	}
	cout << maxvalue << "\n";

	go(maxidx);



}