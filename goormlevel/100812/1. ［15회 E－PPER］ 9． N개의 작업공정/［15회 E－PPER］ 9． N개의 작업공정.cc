#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int parentnum[101];
long long t[101]={0,};
vector<vector<int>> list(101);
int main() {
	int n, r;
	cin >> n >> r;
	
	for(int i=1; i<=n; ++i) {
		cin >> t[i];
	}
	
	for(int i=1; i<=r; ++i) {
		int p, c; cin >> p >> c;
		// cout << p << c << endl;
		parentnum[c]++;
		list[p].push_back(c);
	}
	int f; cin >> f;
	priority_queue<pair<int,pair<int, int>>> q; // 시간, layer, 인덱스
	for(int i=1; i<=n; ++i) {
		// cout << parentnum[i] << endl;
		if(parentnum[i]==0) {
			q.push({-t[i],{1,i}});
		}
	}
	
	long long levellist[101]={0,};
	
	
	while(!q.empty()) {
		long long ti= -q.top().first;
		int level= q.top().second.first;
		int idx= q.top().second.second;
		// cout << ti << " "<< level << " " << idx << "\n";
		
		q.pop();
		
		levellist[level]=max(levellist[level],levellist[level-1]+ti);

		if(idx==f) {
			cout << levellist[level];
		 	break;
		}
		
		for(int i=0; i<list[idx].size(); ++i) {
			int tar= list[idx][i];
			parentnum[tar]--;
			if(parentnum[tar]==0) {
				q.push({-t[tar], {level+1, tar}});
			}
		}
		
	}
	// long long ans=0;
	// for(int i=0; i<=r+1; ++i) {
	// 	// cout << levellist[i] << endl;
	// 	ans=max(ans, levellist[i]);
	// }
	// cout << ans;
}