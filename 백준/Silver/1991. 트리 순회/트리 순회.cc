#include<iostream>
#include<vector>
#include<map>

using namespace std;

int n;

struct Node {
	char left;
	char right;
};

map<char, Node> m;

void pre(char root) {
	if (root == '.') return;
	cout << root;
	pre(m[root].left);
	pre(m[root].right);
}
void in(char root) {
	if (root == '.') return;
	in(m[root].left);
	cout << root;
	in(m[root].right);
}
void post(char root) {
	if (root == '.') return;
	post(m[root].left);
	post(m[root].right);
	cout << root;
}

int main() {
	cin >> n;

	for (int i = 0; i < n; ++i) {
		char root, left, right;
		cin >> root >> left >> right;
		m[root].left = left;
		m[root].right = right;
	}
	
	pre('A');
	cout << "\n";
	in('A');
	cout << "\n";
	post('A');

}