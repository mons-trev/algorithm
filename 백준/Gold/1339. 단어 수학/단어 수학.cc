#include<iostream>
#include<cmath>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;

int match[30];
string list[10];
vector<pair<int, char>> v;
int in[30];
int main() {
	int n; cin >> n;
	memset(in, -1, sizeof(in));
	for (int i = 0; i < n; ++i) {
		string s; cin >> s;
		int len = s.size();
		list[i] = s;
		for (int j = 0; j < len; ++j) {
			char c = s[j];
			int idx = c - 'A';
			if (in[idx] != -1) {
				v[in[idx]].first += pow(10, len - j-1);
			}
			else {
				v.push_back({ pow(10, len - j-1), c });
				in[idx] = v.size() - 1;
			}
		}
	}
	
		sort(v.begin(), v.end(), greater<>());
		int pointer = 9;
		for (int i = 0; i < v.size(); ++i) {
			v[i].first = pointer--;
			match[v[i].second - 'A'] = v[i].first;
		}
		int ans = 0;
		for (int i = 0; i < n; ++i) {
			int len = list[i].size();
			for (int j = 0; j < len; ++j) {
				char c = list[i][j];
				ans = ans + (match[c-'A'] * pow(10, len-j-1));
			}
		}
		cout << ans;
}