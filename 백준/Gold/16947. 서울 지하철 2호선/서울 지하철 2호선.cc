#include<iostream>
#include<cstring>
using namespace std;

int n;
int graph[3000][3000];
int con[3000];
bool visit[3000];
int start=-1;

bool find_con(int prev, int now) {
	for (int i = 0; i < n; ++i) {
		if (i == prev) continue;
			if (graph[now][i]==1) {
				if (visit[i]) { //순환 한바퀴 돌음
					start = i;
					con[i] = 0;
					return true;
				}
				if (!visit[i]) {
					visit[i] = true;
					if (find_con(now, i)) {
						con[i] = 0;
						if (i == start) {
							return false;
						}
						return true;
					}
				}
			}
		}
	return false;
}

int find_dist(int prev, int now) {
	if (con[now] >= 0) {
		return con[now];
	}
	for (int i = 0; i < n; ++i) {
		if (prev == i) continue;
		if (graph[now][i]==1 && find_dist(now,i)> -1) {
			return con[now] = find_dist(now, i) + 1;
		}
	}
	return -1;
}

int main() {
		cin >> n;
		memset(con, -1, sizeof(con));
		for (int i = 0; i < n; ++i) {
			int x; int y; cin >> x >> y;
			graph[x - 1][y - 1] = graph[y - 1][x - 1] = 1; // 갈 수 있으면 1로 초기화
		}
		visit[0] = true;
		find_con(0, 0);

		for (int i = 0; i < n; ++i) {
			if (con[i]!=-1) {
				cout << con[i] << " ";
				continue;
			}
			cout << find_dist(i,i) << " ";
	}
}
