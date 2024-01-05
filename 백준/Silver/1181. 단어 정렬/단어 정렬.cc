#include<algorithm>
#include<iostream>
#include<vector>
#include<set>

using namespace std;

int main() {
	int n;
	cin >> n;
	set<string> cal;
	vector<vector<string>> list(51);
	for (int i = 0; i < n; ++i) {
		string s; cin >> s;
		if (!cal.count(s)) {
			list[s.size()].push_back(s);
			cal.insert(s);
		}
	}
	for (int i = 0; i < list.size(); ++i) {
		sort(list[i].begin(), list[i].end());
		for (int j = 0; j < list[i].size(); ++j) {
			cout << list[i][j] << "\n";
		}
	}
}