#include<iostream>
#include<vector>
#include<map>
#include<string>

using namespace std;

struct Trie {
	map<string, Trie*> m;

	void insert(vector<string> v, int idx) {
		if (idx == v.size()) return;
		if (m.find((v[idx])) == m.end()) { // 존재하지 않는다면
			Trie* trie = new Trie;
			m[(v[idx])] = trie;
		}
		m[v[idx]]->insert(v, idx + 1);
	}
	void dfs(int d) {
		for (auto& i : m) {
			for (int j = 0; j < d; ++j) {
				cout << "--";
			}
			cout << i.first << "\n";
			i.second->dfs(d + 1);
		}
	}

};

int main() {
	int n;
	cin >> n;
	Trie* root = new Trie; //루트 노드 생성

	for (int i = 0; i < n; ++i) {
		int num; cin >> num;
		vector<string> v;
		for (int j = 0; j < num; ++j) {
			string s;
			cin >> s;
			v.push_back(s);
		}
		root->insert(v, 0);
	}
	root->dfs(0);
}