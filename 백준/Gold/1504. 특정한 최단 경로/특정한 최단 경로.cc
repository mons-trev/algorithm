#include<iostream>
#include<queue>
#include<vector>
#include<cstring>
#define inf 8000000
using namespace std;

int n, e;
int fi, se;
vector<vector<pair<int,int>>> g(801);
int dik[801];

void resetdik() {
	for (int i = 1; i <= n; ++i) {
		dik[i] = inf;
	}
}
int di(int start, int end) {
	resetdik();
	if (start == end) return 0;
	priority_queue<pair<int, int>> q;
	q.push({ 0,start });
	while (!q.empty()) {
		int cnt = -q.top().first;
		int now = q.top().second;
		q.pop();
		for (int i = 0; i < g[now].size(); ++i) {
			int next = g[now][i].first;
			int dist = g[now][i].second;
				if (dik[next] > cnt + dist) {
					dik[next] = cnt + dist;
					q.push({ -cnt - dist, next });
				}
			}
	}
	if (dik[end] == inf) {
		return -1;
	}
	return dik[end];
}
int main() {
	cin >> n >> e;
	
	for (int i = 0; i < e; ++i) {
		int from, to, dist;
		cin >> from >> to >> dist;
		g[from].push_back({ to,dist });
		g[to].push_back({ from,dist });
	}
	cin >> fi >> se;
	if (e == 0) {
		cout << -1;
		return 0;
	}
	int starttofi = di(1, fi);
	int starttose = di(1, se);
	int fitose = di(fi, se);
	int fitoend = di(fi, n);
	int setoend = di(se, n);
	//cout << starttofi << " " << starttose << " " << fitose << " " << fitoend << " " << setoend << endl;
	if ((starttofi == -1 && starttose==-1)|| (fitoend == -1 && setoend == -1) || fitose == -1) {
		cout << -1;
	}
	else if (starttofi == -1 && starttose != -1) {
		if (fitoend == -1) {
			cout << -1;
		}
		else {
			cout << starttose + fitose + fitoend;
		}
	}
	else if (starttofi != -1 && starttose == -1) {
		if (setoend == -1) {
			cout << -1;
		}
		else {
			cout << starttofi + fitose + setoend;
		}
	}
	else {
		cout << min(starttose + fitose + fitoend, starttofi + fitose + setoend);
	}
}