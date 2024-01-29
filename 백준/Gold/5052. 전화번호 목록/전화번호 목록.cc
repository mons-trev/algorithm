#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int t;

struct Node {
	int label;
	Node* child[10];
	bool end = false;
};

bool flg = false;

Node* insert(Node* root, string s, int idx) {
	if (root == NULL) { // 노드가 없을 경우
		if (idx != s.size() - 1) {
			Node* n = new Node();
			n->label = s[idx] - '0';
			root = n;
			root->child[s[idx+1]-'0']=insert(root->child[s[idx+1] - '0'], s,idx+1);
		}
		else {
			Node* n = new Node();
			n->label = s[idx] - '0';
			n->end = true;
			return n;
		}
	}
	
	else {//이미 노드가 존재하는 경우
		if (root->end) {
			flg = true;
			if (idx == s.size() - 1) return root;
			else root->child[s[idx+1] - '0'] = insert(root->child[s[idx+1] - '0'], s, idx + 1);
		}
		else {
			if (idx == s.size() - 1) return root;
			else root->child[s[idx+1] - '0']= insert(root->child[s[idx+1] - '0'], s, idx + 1);
		}
	}
	return root;
}


bool cmp(string a, string b) {
	return a.size() < b.size();
}
int main() {
	cin >> t;
	while (t--) {
		flg = false;
		Node* tree[10] = { NULL, };

		vector<string> ph;
		int n; cin >> n;

		for (int i = 0; i < n; ++i) {
			string s; cin >> s;
			ph.push_back(s);
		}
		sort(ph.begin(), ph.end(), cmp); // 길이 순으로 정렬

		for (int i = 0; i < n; ++i) {
			string s = ph[i];
			tree[s[0]-'0'] = insert(tree[s[0] - '0'], s, 0);
			if (flg) break;
		}

		if (flg) cout << "NO\n";

		else cout << "YES\n";
	}
}