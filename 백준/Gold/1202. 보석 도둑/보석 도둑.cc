#include<stdio.h>
#include<vector>
#include<algorithm>
#include<queue>
#define INF 1000000001
using namespace std;

int n, k;

vector<pair<int, int>> jlist;
vector<int> blist;
vector<vector<pair<int, int>>> sortlist;
vector<pair<int, int>> range;

int main() {
	scanf("%d %d", &n, &k);

	for (int i = 0; i < n; ++i) {
		int m, v; scanf("%d %d", &m, &v);
		jlist.push_back({ m,v }); // 무게, 가격
	}

	sort(jlist.begin(), jlist.end()); // 보석 무게 순으로 정렬
	
	for (int i = 0; i < k; ++i) {
		int m; scanf("%d", &m);
		blist.push_back(m);
	}

	sort(blist.begin(), blist.end()); // 가방 무게순으로 정렬
	
	range.push_back({ -1, blist[0] }); // 인덱스 0 번은 -1< <=blist[0] (ex.2)
	for (int i = 1; i < blist.size(); ++i) {
		if (blist[i] == blist[i - 1]) continue;
		range.push_back({ range[range.size() - 1].second , blist[i] });
	}

	range.push_back({range[range.size()-1].second, INF});

	int idx = 0;

	sortlist.push_back({ {} }); // 처음 범위는 무조건 들어감

	for (int i = 0; i < jlist.size(); ++i) {
		if (jlist[i].first > range[idx].first && jlist[i].first <= range[idx].second) {
			sortlist[idx].push_back({ jlist[i].second, jlist[i].first });
		}
		else {
			idx++;
			sortlist.push_back({ {} });
			while (true) {
				if (jlist[i].first > range[idx].first && jlist[i].first <= range[idx].second) {
					break;
				}
				else {
					idx++;
					sortlist.push_back({ {} });
				}
			}
			sortlist.push_back({ {} });
			sortlist[idx].push_back({jlist[i].second, jlist[i].first});
		}
	}

	sort(sortlist[0].begin(), sortlist[0].end(), greater<>()); // 내림차순으로 정렬


	long long ans = sortlist[0][0].first;
	sortlist[0].erase(sortlist[0].begin()+0);
	priority_queue<pair<int, int>> q;
	for (int i = 0; i < sortlist[0].size(); ++i) {
		q.push({ sortlist[0][i].first, sortlist[0][i].second });
	}
	int rindex = 0;
	for (int i = 1; i < blist.size(); ++i) {
		
		if (!(blist[i] > range[rindex].first && blist[i] <= range[rindex].second)) {
			if (rindex + 1 < sortlist.size()) {
				rindex++;
				for (int j = 0; j < sortlist[rindex].size(); ++j) {
					q.push({ sortlist[rindex][j].first, sortlist[rindex][j].second });
				}
			}
		}
		ans += q.top().first;
		q.pop();
	}
	printf("%ld", ans);
}