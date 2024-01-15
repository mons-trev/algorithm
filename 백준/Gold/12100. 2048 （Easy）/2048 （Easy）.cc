#include<iostream>
using namespace std;

int n;
int maxx = 0;
bool check[21][21];
//상하좌우 백트래킹

void backtracking(int d, int cnt, int g[21][21]) { //이전에 온 값을 g에 저장
	int gg[21][21];

	if (cnt > 5) {
		for (int i = 1; i < n + 1; ++i) {
			for (int j = 1; j < n + 1; ++j) {
				maxx = max(maxx, g[i][j]);
			}
		}
		//cout << maxx;
		return;
	}
	for (int i = 1; i < n + 1; ++i) {
		for (int j = 1; j < n + 1; ++j) {
			gg[i][j] = g[i][j];//gg를 갱신할 것이기 때문에 똑같이 복사
		}
	}
	//cout << maxx;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			check[i][j] = false;
		}
	}
		//실행
		if (d == 0) { // 북쪽으로 향하는거면 열을 단위로 위쪽에서부터
			for (int j = 1; j <= n; ++j) {//열
				for (int i = 2; i <= n; ++i) { // 행 0번부터
					if (gg[i][j] == 0) {
						continue;
					}
					int k = i-1;
					int prev = k;
					while (k>0) {

						if (gg[k][j] != 0) {
							prev = k;
							break;
						}

						prev = k;
						k--;
					}
					if (prev < 1) {
						prev = 1;
					}
					if (gg[prev][j] == gg[i][j] && !check[prev][j]) {
						if (gg[prev][j] != 0) {
							check[prev][j] = true;
						}
						gg[prev][j] += gg[prev][j];
						gg[i][j] = 0;
					}
					else {
						if (gg[prev][j] == 0) {
							gg[prev][j] = gg[i][j];
							gg[i][j] = 0;
							continue;
						}
						gg[prev + 1][j] = gg[i][j];
						if (prev + 1 != i) {
							gg[i][j] = 0;
						}
					}
					
				}
			}
		}
		if (d == 1) { //남
			for (int j = 1; j <= n; ++j) {//열
				for (int i = n-1; i > 0; --i) { // 행 n번부터
					if (gg[i][j] == 0) {
						continue;
					}
					int k = i + 1;
					int prev = k;
					while (k < n+1) {
					
						if (gg[k][j] != 0) {
							prev = k;
							break;
						}

						prev = k;
						k++;
					}
					if (prev == n + 1) {
						prev--;
					}
					if (gg[prev][j] == gg[i][j] && !check[prev][j]) {
						if (gg[prev][j] != 0) {
							check[prev][j] = true;
						}
						gg[prev][j] *= 2;
						gg[i][j] = 0;
					}
					else {
						if (gg[prev][j] == 0) {
							gg[prev][j] = gg[i][j];
							gg[i][j] = 0;
							continue;
						}
						gg[prev - 1][j] = gg[i][j];
						if (prev - 1 != i) {
							gg[i][j] = 0;
						}
					}
				}
			}
		}
		if (d == 2) { //동
			for (int j = 1; j <= n; ++j) {//행
				for (int i = n-1; i > 0; --i) { // 열 n번부터
					if (gg[j][i] == 0) {
						continue;
					}
					int k = i + 1;
					int prev = k;
					while (k < n+1) {

						if (gg[j][k] != 0) {
							prev = k;
							break;
						}

						prev = k;
						k++;
					}
					if (prev == n + 1) {
						prev--;
					}
					if (gg[j][prev] == gg[j][i] && !check[j][prev]) {
						if (gg[j][prev] != 0) {
							check[j][prev] = true;
						}
						gg[j][prev] *= 2;
						gg[j][i] = 0;
					}
					else {
						if (gg[j][prev] == 0 ) {
							gg[j][prev] = gg[j][i];
							
							gg[j][i] = 0;
							continue;
						}
						gg[j][prev-1] = gg[j][i];
						if (prev - 1 != i) {
							gg[j][i] = 0;
						}
					}
				}
			}
		}
		if (d == 3) { // 서
			for (int j = 1; j <= n; ++j) {//행
				for (int i = 2; i <= n; ++i) { // 열 0번부터
					if (gg[j][i] == 0) {
						continue;
					}
					int k = i - 1;
					int prev = k;
					while (k >= 0) {

						if (gg[j][k] != 0) {
							prev = k;
							break;
						}

						prev = k;
						k--;
					}
					if (prev <1)  {
						prev = 1;
					}
					if (gg[j][prev] == gg[j][i] && !check[j][prev]) {
						if (gg[j][prev] != 0) {
							check[j][prev] = true;
						}
						gg[j][prev] *= 2;
						gg[j][i] = 0;
					}
					else {
						if (gg[j][prev] == 0) {
							gg[j][prev] = gg[j][i];
							gg[j][i] = 0;
							continue;
						}
						gg[j][prev+1] = gg[j][i];
						if (prev + 1 != i) {
							gg[j][i] = 0;
						}
					}
				}
			}
		}
	for (int i = 0; i < 4; ++i) {
		backtracking(i, cnt + 1, gg);
	}
	return;
}

int main() {
	int g[21][21];

	cin >> n;
	for (int i = 0; i < n + 1; ++i) {
		for (int j = 0; j < n + 1; ++j) {
			g[i][j] = 0;
		}
	}

	for (int i = 1; i < n + 1; ++i) {
		for (int j = 1; j < n + 1; ++j) {
			cin >> g[i][j];
		}
	}

	backtracking(-1, 0, g); //방향, 갯수
	cout << maxx;
}