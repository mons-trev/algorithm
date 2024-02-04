#include<stdio.h>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

vector<int> v[12]; // 행: 포지션 , 열: 선수 능력치

int main() {
	int n, k;
	scanf("%d %d", &n, &k);
	priority_queue<int> q[12];
	for (int i = 0; i < n; ++i) {
		int p, k; 	scanf("%d %d", &p, &k);
		q[p].push(k);
	}

	for (int i = 0; i < k; ++i) {
		for (int j = 1; j < 12; ++j) {
			if (!q[j].empty()) {
				int k = q[j].top();
				q[j].pop();
				if (k - 1 < 0) {
					q[j].push(0);
				}
				else {
					q[j].push(k - 1);
				}
			}
		}
	}

	int sum = 0;
	for (int i = 1; i < 12; ++i) {
		if (!q[i].empty()) {
			sum += q[i].top();
		}
	}
	printf("%d", sum);
	
}