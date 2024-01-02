#include<iostream>
#include<vector>
#include<cstring>
#include<cmath>
#include<queue>

using namespace std;


int main() {
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<int> list[501];
		int topo[501] = { 0, };
		int record[501] = { 0, };
		for (int i = 1; i <= n; ++i) {
			cin >> record[i]; //1(i)위부터 꼴등까지 달림
		}
		for (int i = 1; i <= n; ++i) {
			int a = record[i]; // i등의 팀 번호
			for (int j = i + 1; j <= n; ++j) {
				list[a].push_back(record[j]);
				topo[record[j]]++;
			}
		}
		int changed; cin >> changed;
		for (int t = 0; t < changed; ++t) {
			int a; int b; cin >> a >> b;
			int a_index = -1;
			int b_index = -1;
			for (int i = 1; i <= n; ++i) { //등수 조회
				if (record[i] == a) {
					a_index = i;
				}
				if (record[i] == b) {
					b_index = i;
				}
			}
			if (a_index < b_index) { //원래 a가 b보다 앞섰다면
				for (int i = 0; i < list[a].size(); ++i) {
					if (list[a][i] == b) {
						list[a].erase(list[a].begin() + i);
					}
				}
				topo[b]--;
				topo[a]++;
				list[b].push_back(a);
			}
			else {//원래 b가 a보다 앞섰다면
				for (int i = 0; i < list[b].size(); ++i) {
					if (list[b][i] == a) {
						list[b].erase(list[b].begin() + i);
					}
				}
				topo[a]--;
				topo[b]++;
				list[a].push_back(b);
			}
		}
			queue<int> q;
			vector<int> ans;
			
			for (int i = 1; i <= n; ++i) {
				if (topo[i] == 0) q.push(i);
			}
			if (q.empty()) {
				cout << "IMPOSSIBLE" << endl;
				continue;
			}
			bool whole = false;
			int it = 1;
			while (!q.empty()) {
				if (q.size() > 1) {
					cout << "?" << endl; 
					whole = true;
					break;
				}
				int m = q.front();
				ans.push_back(m);
				it++;
				q.pop();
				bool flag = false;
				for (int i = 0; i < list[m].size(); ++i) { //topo 감소
					int next = list[m][i];
					topo[next]--;
					if (topo[next] < 0) {
						cout << "IMPOSSIBLE" << endl;
						flag = true;
						whole = true;
						break;
					}
					if (topo[next] == 0) q.push(next);
				}
				if (flag) break;
			}
			if (it < n) {
				cout << "IMPOSSIBLE" << endl;
				continue;
			}
			if (!whole) {
				for (int i = 0; i < ans.size(); ++i) {
					cout << ans[i] << " ";
				}
			}
			
			cout << endl;
		}
}