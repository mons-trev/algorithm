#include<iostream>
#include<vector>
#include<queue>
#include<cmath>
#include<algorithm>
using namespace std;

int n, m, k;
pair<int,int> graph[1001][1001][11];

int dy[] = { 0,0,1,-1 };
int dx[] = { 1,-1,0,0 };

int sol() {
	queue<pair<int, pair<bool, pair<int, pair<int, int>>>>>  q;//낮밤, 뚫은 횟수, 위치
	q.push({ 1, {true,{0, {1,1}} } }); // 총 거리, 닞인지 밤인지, 벽 한번도 안 부심/ 1,1
	
	graph[1][1][0] = { 0,1 };
		while (!q.empty()) {
		int total = q.front().first;
		bool isday = q.front().second.first; // 현재는 이전과 반대 상태
		int cnt = q.front().second.second.first; // 벽 부심
		int y = q.front().second.second.second.first;
		int x = q.front().second.second.second.second;
		q.pop();
		//cout << total << isday << cnt << y << x << endl;
		if (y == n && x == m) {
			return total;
		}
		for (int i = 0; i < 4; ++i) {
			int nexty = y + dy[i];
			int nextx = x + dx[i];
			if (nexty > 0 && nextx > 0 && nexty <= n && nextx <= m) { // 다음으로 갈 수 있다면
				//벽이 없는데 방문한 적이 있다면 패스
				if (graph[nexty][nextx][cnt].first == 1 && cnt < k && graph[nexty][nextx][cnt+1].second == 0) {
						graph[nexty][nextx][cnt+1].second = 1;
						//cout << "부정 잘 되는지" << !isday << endl;
						q.push({ (total + 1), {!isday,{cnt + 1,{nexty,nextx}}} });

				}
			else if (graph[nexty][nextx][cnt].first == 0 && graph[nexty][nextx][cnt].second == 0) { //벽이 아니고 이미 방문한 적이 없다면
				graph[nexty][nextx][cnt].second = 1;
				q.push({ (total + 1), {!isday,{cnt,{nexty,nextx}}} });
			}
			}
		}
	}
	return -1;
}

int main() {

	cin >> n >> m >> k;
	for (int i = 1; i <= n; ++i) {
		string s; cin >> s;
		for (int j = 0; j < m; ++j) {
			for (int t = 0; t <= k; ++t) {
				graph[i][j + 1][t] = { s[j]-'0',0};
			}
		}
	}

	cout << sol();

}
