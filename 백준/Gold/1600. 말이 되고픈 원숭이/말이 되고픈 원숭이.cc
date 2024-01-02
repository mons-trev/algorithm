#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<queue>

using namespace std;
int k, w, h; //열, 행
int g[201][201];
int visit[201][201][31];
int dx[] = { 1,1,2,2,-1,-1,-2,-2 };
int dy[] = { -2,2,-1,1,2,-2,1,-1 };
int ddx[] = { 0,0,1,-1 };
int ddy[] = { 1,-1,0,0 };
int sol() {
	queue<pair<int, pair<int, pair<int, int>>>> q; // 몇번 점프했는지, 인덱스
	q.push({ 0, { 0, {1,1} } });
	visit[1][1][0] = 1;
	while (!q.empty()) {
		int total = q.front().first;
		int cnt = q.front().second.first;
		int y = q.front().second.second.first;
		int x = q.front().second.second.second;
		q.pop();
		if (y == h && x == w) {
			return total;
		}
		for (int i = 0; i < 8; ++i) {
			int nexty = y + dy[i];
			int nextx = x + dx[i];
			if (nexty >= 1 && nextx >= 1 && nexty <= h && nextx <= w && cnt<k) {
				if (g[nexty][nextx] == 0 && visit[nexty][nextx][cnt + 1] == 0) {
					visit[nexty][nextx][cnt + 1] = 1;
					q.push({ total + 1,{ cnt + 1, {nexty,nextx} } });
				}
				else if (g[nexty][nextx] == 1) continue;
			}
		}
		for (int i = 0; i < 4; ++i) {
			int nexty = y + ddy[i];
			int nextx = x + ddx[i];
			if (nexty >= 1 && nextx >= 1 && nexty <= h && nextx <= w) {
				if (g[nexty][nextx] == 0 && visit[nexty][nextx][cnt] == 0) {
					visit[nexty][nextx][cnt] = 1;
					q.push({ total + 1,{ cnt, {nexty,nextx} } });
				}
				else if (g[nexty][nextx] == 1) continue;
			}
		}
	}
	return -1;
}

int main() {
	scanf("%d %d %d", &k, &w, &h);
	for (int i = 1; i <= h; ++i) {
		for (int j = 1; j <= w; ++j) {
			scanf("%d", &g[i][j]);
		}
	}
	printf("%d", sol());
}