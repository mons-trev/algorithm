#include<iostream>

using namespace std;

int parent[500000];
int n, m;
int list[1000000][2];

int getparent(int a) {
	if (parent[a] == a) {
		return a;
	}
	else { // 가장 작은 것으로 get 하면서 parent 갱신
		return parent[a]=getparent(parent[a]);
	}
}

bool find(int a, int b) { //사이클 형성 유무
	//사이클 형성되면 true 아니면 false
	int aroot = getparent(a);
	int broot = getparent(b);
	return aroot == broot;

}

void union_group(int a, int b) {
	int aroot = getparent(a);
	int broot = getparent(b);
	if (a < b) {
		parent[broot] = aroot;
	}
	else {
		parent[aroot] = broot;
	}
}

int main() {
	for (int i = 0; i < 500000; ++i) {
		parent[i] = i;
	}
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		cin >> list[i][0] >> list[i][1];
	}
	for (int i = 0; i < m; ++i) {
		int from = list[i][0];
		int to = list[i][1];
		if (to < from) { // 항상 from 은 to 보다 작다
			int tmp = to;
			to = from;
			from = tmp;
		}
		if (find(from, to)) {
			cout << i + 1;
			return 0;
		}
		else {
			union_group(from, to);
		}
	}
	cout << 0;
	return 0;
}