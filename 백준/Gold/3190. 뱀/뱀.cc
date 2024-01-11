#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int n;
int an; // apple num
int dn; // direction num
int g[101][101];
int snake[101][101];
vector<pair<int, char>> d;
pair<int, int> direction[4] = { {0,1}, {1,0}, {0,-1}, {-1,0} };
int main() {
	cin >> n;
	cin >> an;
	for (int i = 0; i < an; ++i) {
		int y, x;
		cin >> y >> x;
		g[y][x] = 1; // 1으로 된 곳이 사과가 있는 곳
	}
	cin >> dn;
	for (int i = 0; i < dn; ++i) {
		int c; char dir;
		cin >> c >> dir;
		d.push_back({ c,dir });
	}

	deque<pair<int, int>> s;
	s.push_back({ 1,1 }); // 뱀의 첫 길이는 1 즉 그래프 한 칸
	int d_n = 0;
	int cnt = 0;
	while (true) {
		cnt++; // 시간 1초 경과
		int dy = direction[d_n].first;		
		int dx = direction[d_n].second;
		int y = s.front().first; // 뱀의 머리 확인
		int x = s.front().second;
		int ny = y + dy;
		int nx = x + dx;
		if (ny > n || nx > n || ny <1 || nx <1) {//벽 만남
			cout << cnt;
			return 0;
		}
		if (snake[ny][nx] != 0) {//뱀의 일부 만남
			cout << cnt;
			return 0;
		}

		//뱀 이동시키기
		s.push_front({ ny,nx });//사과가 있든 말든 헤드는 일단 이동시키기
		snake[ny][nx] = 1;
		
		if (g[ny][nx] == 0) { //사과가 없다면
			snake[s.back().first][s.back().second] = 0; // 꼬리 자르기
			s.pop_back(); // 꼬리 덱에서 없애기
		}
		g[ny][nx] = 0;
		//마지막에 방향 틀어지는지 확인
		if (d.size() > 0) {//방향 리스트가 적어도 하나가 남아있다면 체크
			if (d[0].first == cnt) {
				if(d[0].second == 'L') {
					d_n = abs(d_n - 1 +4) % 4;
				}
				else {
					d_n = (d_n + 1) % 4;
				}
				d.erase(d.begin());
			}
		}
	}
}