#include<iostream>
#include<cmath>
#include<cstring> //memset 쓰려면
#define MAX sqrt(100000000);

using namespace std;

double map[16][16];

double dp[16][1 << 16]; // 열의 갯수 = 2^16

int n;

double sol(int now, int visit) {

	if (visit == (1 << n) - 1) {
		if (map[now][0] == 0.0) { // 종점->시작 불가
			return MAX;
		}
		else {
			return map[now][0];
		}
	}
	if (dp[now][visit] != -1.0) {
		return dp[now][visit];
	}
	//아직 방문하지 않은 곳이라면
	dp[now][visit] = MAX;
	for (int i = 0; i < n; ++i) {
		if (map[now][i] == 0.0) continue; // 방문할 수 없다면
		if ((visit & (1 << i)) == (1 << i)) continue; //이미 방문한 곳이면
		dp[now][visit] = (min(dp[now][visit], map[now][i] + sol(i, visit | 1 << i)));
	}
	return dp[now][visit];
}


int main() {
	cin >> n;
	double list[16][2];
	for (int i = 0; i < n; ++i) {
		cin >> list[i][0];
		cin >> list[i][1];
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			map[i][j] = sqrt(pow(list[i][0] - list[j][0], 2) + pow(list[i][1] - list[j][1], 2));
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < (1 << n) +1 ; ++j) {
			dp[i][j] = -1.0;
		}
	}
	cout << fixed;
	cout.precision(9);
	cout << sol(0, 1); // 시작은 항상 0

}

