#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

using namespace std;

int n, m;
int g[1025][1025];
int cul[1025][1025];
int dp[1025][1025];

int main() {
	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			scanf("%d", &g[i][j]);
			cul[i][j] = cul[i][j - 1] + g[i][j];
		}
	}
	for (int i = 0; i < m; ++i) {
		int fy, fx, ty, tx;
		scanf("%d %d %d %d", &fy, &fx, &ty, &tx);
		int total = 0;


		if (dp[ty][tx] != 0) {
			total += dp[ty][tx];
		}

		else {
			for (int j = 1; j <= ty; ++j) {
				total += cul[j][tx];
			}
			dp[ty][tx] = total;
		}


		if (dp[fy - 1][tx] != 0) {
			total -= dp[fy - 1][tx];
		}
		else {
			int sum2 = 0;
			for (int j = 1; j <= fy - 1; ++j) {
				sum2 += cul[j][tx];
			}
			dp[fy - 1][tx] = sum2;
			total -= sum2;
		}

		if (dp[ty][fx-1] != 0) {
			total -= dp[ty][fx-1];
		}
		else {
			int sum2 = 0;
			for (int j = 1; j <= ty; ++j) {
				sum2 += cul[j][fx - 1];
			}
			dp[ty][fx - 1] = sum2;
			total -= sum2;
		}
		
		
		
		if (dp[fy - 1][fx - 1] != 0) {
			total += dp[fy - 1][fx - 1];
		}
		else {
			int sum2 = 0;
			for (int j = 1; j <= fy - 1; ++j) {
				sum2 += cul[j][fx - 1];
			}
			dp[fy - 1][fx - 1] = sum2;
			total += sum2;
		}
		printf("%d\n", total);
	}
}