#include<iostream>
#include<vector>
#include<tuple>
#include<queue>
using namespace std;

int N;
int M;
vector<vector<int>> dp;

int dp_sol() {
	queue<tuple<int, int, int>> q; // 현재, 이전의 칸 수, 점프 수

	q.push( make_tuple(1, 0, 0) );
	//dp[1][0] = 0;
	while (!q.empty()) {
		int present = get<0>(q.front());
		int cnt = get<1>(q.front());
		int sum = get<2>(q.front());
		q.pop();
		if (present == N) {
			return sum;
		}
		for (int i = -1; i < 2; ++i) {
			int go = cnt + i;
			if (go <= 0 || present+go > N || dp[present + go][0] == -2) {
				continue;
			}
			else {
				if (dp[present + go][go] == -1) {
					dp[present + go][go] = sum + 1;
					q.push(make_tuple(present + go, go, sum + 1));
				}
			}
		}
	}
	return -1;
}

int main() {
	cin >> N;
	cin >> M;
	
	for (int i = 0; i <= N; ++i) {
		dp.push_back({});
		for (int j = 0; j*(j+1)/2 <= N; ++j) {
			dp[i].push_back(-1);
		}
	}
	for (int i = 0; i < M; ++i) {
		int tmp; cin >> tmp;
		dp[tmp][0] = -2;
	}

	
	cout << dp_sol();
	
}