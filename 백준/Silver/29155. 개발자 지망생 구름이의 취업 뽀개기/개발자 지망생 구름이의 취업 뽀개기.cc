#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<algorithm>
#include<vector>

using namespace std;

int plist[6];
vector<int> pro[6];

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i < 6; ++i) {
		scanf("%d", &plist[i]);
	}
	int ans = 240; // 난이도가 다른걸 넘어갈 때 걸리는 시간
	for (int i = 0; i < n; ++i) {
		int p,rate;
		scanf("%d %d", &p, &rate);
		pro[p].push_back(rate);
	}
	for (int i = 1; i < 6; ++i) {
		sort(pro[i].begin(), pro[i].end());
	}
	for (int i = 1; i < 6; ++i) {
		int cnt = plist[i];
		ans += pro[i][0];
		if (cnt == 1) {
			continue;
		}
		else {
			for (int j = 1; j < cnt; ++j) {
				ans += (pro[i][j] - pro[i][j - 1]) + pro[i][j];
			}
		}
	}
	printf("%d", ans);
}