#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

using namespace std;

int n, m;
int g[1025][1025];
int cul[1025][1025];

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
		for (int j = 1; j <= ty; ++j) {
			total += cul[j][tx];
		}
		for (int j = 1; j <= fy - 1; ++j) {
			total -= cul[j][tx];
		}
		for (int j = 1; j <= ty; ++j) {
			total -= cul[j][fx-1];
		}
		for (int j = 1; j <= fy - 1; ++j) {
			total += cul[j][fx - 1];
		}
		printf("%d\n", total);
	}
}