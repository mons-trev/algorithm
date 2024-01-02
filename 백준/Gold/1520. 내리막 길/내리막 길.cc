#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int y, x;
vector<vector<int>> arr; // 높이 그래프
vector<vector<int>> dp; // dp
int dy[4] = { 1,0,0,-1 };
int dx[4] = { 0,1,-1,0 };
//dfs와 dp를 같이 이용해야한다.
int dfsdp(int fy, int fx) {
	if (fy == y-1 && fx == x-1) {
		return 1;
	}
	if (dp[fy][fx] != -1) {
		return dp[fy][fx];
	}
	dp[fy][fx] = 0;
	for (int i = 0; i < 4; ++i) {
		int go_y = fy + dy[i];
		int go_x = fx + dx[i];
		if (go_y > -1 && go_y<y && go_x > -1 && go_x < x && arr[fy][fx] > arr[go_y][go_x]) {//조건에 맞는지 확인
			dp[fy][fx] += dfsdp(go_y,go_x);
		}
	}
	return dp[fy][fx];
}
int main() {
	cin >> y >> x;
	for (int i = 0; i < y; ++i) {
		vector<int> tmp;
		dp.push_back({});
		for (int j = 0; j < x; ++j) {
			int a; cin >> a; tmp.push_back(a);
			dp[i].push_back(-1); // dp는 다 0 으로 초기화
		}
		arr.push_back(tmp);
	}
	cout << dfsdp(0, 0);
}
