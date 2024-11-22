#include<iostream>
#include<queue>
#include<vector>
#include<cstring>

using namespace std;
typedef long long ll;
ll dist[504];
int n,m;
vector<pair<pair<int,int>, int>> v;

void belman() {
	dist[1] = 0;
	for(int i=1; i<=n-1; i++) {
		for(int j=0; j<v.size(); j++){
			int st = v[j].first.first;
			int en = v[j].first.second;
			int cost = v[j].second;
			if(dist[st] == 1e9) continue;
			if(dist[en] > dist[st] + cost) dist[en] = dist[st] + cost;
		}
	}
	
	for(int j=0; j<v.size(); j++){
		int st = v[j].first.first;
		int en = v[j].first.second;
		int cost = v[j].second;
		if(dist[st] == 1e9) continue;
		if(dist[en] > dist[st] + cost){
			cout << -1;
			return;
		}
	}
	for(int i=2; i<=n; i++){
		if(dist[i] == 1e9) cout << -1 << '\n';
		else cout << dist[i] << '\n';
	}
}

int main(void){
	cin >> n >> m;
	
	for(int i=0; i<=500; i++) dist[i] = 1e9;
	
	for(int i=0; i<m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v.push_back({{a,b}, c});
	}
	
	belman();
	return 0;
}