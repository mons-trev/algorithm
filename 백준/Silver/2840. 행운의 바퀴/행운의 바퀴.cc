#include<iostream>
#include<vector>

using namespace std;

char check[30]; // 방문되지 않았으면 . 으로 초기화
bool al[50] = { false, };

int main() {
	int n, k; cin >> n >> k;
	
	int cnt = 0;
	int prev = 0;
	int cur = 0;
	for (int i = 0; i < n; ++i) {
		check[i] = '?';
	}
	vector<pair<int, char>> v;
	for (int i = 0; i < k; ++i) {
		int a; char b;
		cin >> a >> b;
		v.push_back({ a,b });
	}
	for (int i = 0; i < k; ++i) {
		int a = v[i].first;
		char b = v[i].second;
		
		cur = prev+ a;
		cur %= n;
		prev = cur;
		if (check[cur] == '?') {
			if (al[b - '0']) {
				cout << "!";
				return 0;
			}
			al[b - '0'] = true;
			cnt++;
			check[cur] = b;
		}
		else if(check[cur] == b){
			continue;
		}
		else {
			cout << "!";
			return 0;
		}
	}
	//0 1 2 3 4
	//  A  
	cnt = 0;
	while (cnt<n) {
		cnt++;
		cout << check[cur];
		cur=cur-1+n;
		cur %= n;
	}
}