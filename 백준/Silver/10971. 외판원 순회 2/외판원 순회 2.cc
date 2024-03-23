#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

vector<pair<int, int>> v;

int n;
int g[10][10];

bool visit[10];

int back(int x, int cnt) {
	if (cnt >= n) {
		if (g[x][0] != 0) {
			return g[x][0];
		}
		else return 100000000;
	}
	int ret = 100000000;
	for (int i = 0; i < n; ++i) {
		if (!visit[i] && g[x][i]!=0) {
			visit[i] = true;
			ret = min(ret, g[x][i] + back(i, cnt + 1));
			visit[i] = false;
		}
	}
	return ret;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> g[i][j];
		}
	}
	
	visit[0] = true;
	cout << back(0, 1);

}