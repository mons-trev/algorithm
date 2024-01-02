#include<iostream>
#include<cmath>
#include<cstring>
#define MAX 16000000;
using namespace std;

int map[16][16];

int dp[16][1 << 16]; // 열의 갯수 = 2^16

int n;

int sol(int now, int visit) {
	if (visit == (1 << n) - 1) {
		if (map[now][0] == 0) { // 종점->시작 불가
			return MAX;
		}
		else {
			return map[now][0];
		}
	}
	if (dp[now][visit] != -1) {
		return dp[now][visit];
	}
	//아직 방문하지 않은 곳이라면
	dp[now][visit] = MAX;
	for (int i = 0; i < n; ++i) {
		if (map[now][i] == 0) continue; // 방문할 수 없다면
		if ((visit & (1 << i)) == (1 << i)) continue; //이미 방문한 곳이면
		dp[now][visit] = min(dp[now][visit], map[now][i] + sol(i, visit | 1 << i));
	}
	return dp[now][visit];
}


int main() {
	cin >> n;
	
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> map[i][j];
		}
	}

	memset(dp, -1, sizeof(dp));

	cout << sol(0, 1); // 시작은 항상 0

}