#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<cstring>
#include<queue>
#define INF 401;
using namespace std;

int n, m;
short g[21][21];
short dp[21][21][5]; // 상하좌우 최대

short dy[] = { 0,0,-1,1 };
short dx[] = { 1,-1,0,0 };

short bitcount(int a) {
	short cnt = 0;
	for (int i = 0; i < 26; ++i) {
		if ((a & (1 << i) )> 0) {
			cnt++;
		}
	}
	return cnt;
}

int bfs() {
	memset(dp, 0, sizeof(dp));
	int init = 1 << 26;
	init |= (1 << g[1][1]);
	queue <pair<int, pair<short, short>>> q; // 움직인 횟수
	q.push({ init,{1,1}} );
	for (int i = 0; i < 4; ++i) {
		dp[1][1][i] = INF;
	}
	dp[1][1][4] = 1;
	while (!q.empty()) {
		short y = q.front().second.first;
		short x = q.front().second.second;
		int a= q.front().first;
		int cnt = bitcount(a);
		q.pop();
		for (short i = 0; i < 4; ++i) {
			short ny = y + dy[i];
			short nx = x + dx[i];
			if (ny >= 1 && nx >= 1 && ny <= n && nx <= m) {
				if ((a & (1<<g[ny][nx]))>0) continue; // 한번 방문한 것이라면 패스
				else if (cnt+1 >= dp[ny][nx][i]) {
					dp[ny][nx][i] = cnt + 1;
					int b = a; b|=1<<g[ny][nx];
					if (dp[ny][nx][i] > dp[ny][nx][4]) {
						dp[ny][nx][4] = dp[ny][nx][i];
					}
					q.push({ b, {ny,nx}} );
				}
			}
		}
	}
	short ans = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			ans = max(ans, dp[i][j][4]);
		}
	}
	return ans;
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; ++i) {
			char a[20]; scanf("%s", &a);
		for (int j = 1; j <= m; ++j) {
			g[i][j] = a[j-1] - 'A'; //알파벳 대신 숫자를 넣는다 
		}
	}
	
	printf("%d", bfs());
}
