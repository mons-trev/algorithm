#include<iostream>


using namespace std;

int n;
int g[10][10];
bool v[10];

int sol(int x, int sum, int cnt) {
	if (cnt == n) {
		if (g[x][0] != 0) {
			return sum + g[x][0];
		}
	}
	int ret = 1000000000;
	for (int i = 0; i < n; ++i) {
		if (g[x][i] != 0 && !v[i]) {
			v[i] = true;
			ret= min(ret, sol(i, sum + g[x][i], cnt + 1));
			v[i] = false;
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
	v[0] = true; // 0번에서 무조건 시작
	cout << sol(0, 0, 1);
}