#include<iostream>
#include<vector>

using namespace std;


char check[26]; // 방문되지 않았으면 . 으로 초기화
bool al[26] = { false, };

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
		cur = (prev - a%n + n) % n;
		prev = cur;
		if (check[cur] == '?') {
			if (al[b - 'A']) {
				cout << "!";
				return 0;
			}
			al[b - 'A'] = true;
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
	 
	cnt = 0;
	while (cnt<n) {
		cnt++;
		cout << check[cur];
		cur++;
		cur %= n;
	}
}
