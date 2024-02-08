#include <iostream>
#include<queue>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int r, c;
char g[1501][1501];
bool visit[1501][1501];
int net[1500 * 1500 + 1];
bool netv[1500 * 1500 + 1];

vector<pair<int, int>> v;

int dy[] = { 0,1,-1, 0 };//남북동서
int dx[] = { -1,0,0,1 };


void makenet(int yy, int xx) {
	queue<pair<int, int>> q;
	q.push({ yy,xx });
	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		
		for (int i = 0; i < 4; ++i) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (!(ny > 0 && nx > 0 && ny <= r && nx <= c)) continue;
			if (g[ny][nx] != 'X' && !(netv[c * (ny - 1) + nx])) {
				netv[c * (ny - 1) + nx] = true;
				net[c * (ny - 1) + nx] = c * (yy - 1) + xx;
				q.push({ ny, nx });
			}
		}
	}
}

int find(int a) {
	if (a == net[a]) {
		return a;
	}
	else {
		return net[a]=find(net[a]);
	}
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> r >> c;

	priority_queue<pair<int, pair<int, int>>> q;

	for (int i = 1; i < r*c + 1; ++i) {
		net[i] = i;
	}
	
	for (int i = 1; i <= r; ++i) {
		string s; cin >> s;
		for (int j = 1; j <= c; ++j) {
			g[i][j] = s[j-1];
			if (g[i][j] == 'L') {
				q.push({ -1, {i,j} });
				v.push_back({ i,j });
			}
			else if (g[i][j] == '.') {
				q.push({ -1, {i,j} });
			}
		}
	}


	for (int i = 1; i <= r; ++i) {
		for (int j = 1; j <= c; ++j) {
			if (g[i][j] != 'X' && !netv[c * (i - 1) + j]) {
				netv[c * (i - 1) + j] = true;
				makenet(i, j);
			}
		}
	}


	int t = 1;

	while (true) {
		
		while (!q.empty()) {
			int cc = -q.top().first;
			int y = q.top().second.first;
			int x = q.top().second.second;
			if (cc != t) break;
			q.pop();
			if (g[y][x] == 'L') {
				q.push({ -(cc + 1), {y, x} });
			}
			for (int i = 0; i < 4; ++i) {
				int ny = y + dy[i];
				int nx = x + dx[i];
				if (!(ny > 0 && nx > 0 && ny <= r && nx <= c)) continue;
					if (g[ny][nx] == 'X') {
						g[ny][nx] = '.';
						q.push({ -(cc + 1), {ny, nx} });
						vector<int> p;
						p.push_back(c * (ny - 1) + nx);
						for (int k = 0; k < 4; ++k) {
							int ky = ny + dy[k];
							int kx = nx + dx[k];
							if (!(ky > 0 && kx > 0 && ky <= r && kx <= c)) continue;
							else {
								int tar = c * (ky - 1) + kx;
								if (netv[tar]) {
									p.push_back( find(tar) );
								}
							}
						}
						netv[c * (ny - 1) + nx] = true;
						sort(p.begin(), p.end());
						for (int i = 1; i < p.size(); ++i) {
							net[p[i]] = p[0];
						}
					}
			}
		}
		/*
		for (int i = 1; i <= r; ++i) {
			for (int j = 1; j <= c; ++j) {
				cout << g[i][j] << " ";
			}
			cout << endl;
		}
		*/

		//cout << find(net[c * (v[0].first - 1) + v[0].second]) << " " << find(net[c * (v[1].first - 1) + v[1].second]) << "\n";
		if (find(net[c * (v[0].first - 1) + v[0].second]) == find(net[c * (v[1].first - 1) + v[1].second])) {
			cout << t;
			return 0;
		}
		t++;
	}

}

