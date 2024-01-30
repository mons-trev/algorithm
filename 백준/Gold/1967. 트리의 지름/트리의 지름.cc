#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

// 말단 노드와 말단 노드 사이의 거리이어야한다
// 그러려면 두 노드 사이의 루트는 반드시 존재해야한다

struct Node {
	short label;
	vector<pair<Node*, short>> child; // 자식 노드, 가중치
	short parent = 0;
};

Node* tree[10001];
int ans = 0;

int findmax(Node* root) {
	if (root->child.size() == 0) {
		return 0;
	}
	vector<int> dist;
	for (int i = 0; i < root->child.size(); ++i) {
		dist.push_back(root->child[i].second + findmax(root->child[i].first));
	}

	sort(dist.begin(), dist.end());

	if (dist.size() > 1) {
		ans = max(ans, dist[dist.size() - 1] + dist[dist.size() - 2]); // 루트의 잎들끼리 더한 값
	}
	ans = max(ans, dist[dist.size() - 1]); //루트와 잎의 거리
	return dist[dist.size() - 1]; //가장 큰 루트와 잎의 거리 리턴
}

int main() {
	int n;
	cin >> n;
	//트리 생성
	for (int i = 0; i < 10001; ++i) {
		tree[i] = new Node();
		tree[i]->label = i;
	}
	tree[1] = new Node();
	tree[1]->label = 1;
	for (int i = 0; i < n-1; ++i) {
		short p, c, d;//부모 라벨, 자식 라벨, 가중치
		cin >> p >> c >> d;
		tree[p]->child.push_back({ tree[c],d });
		
	}

	findmax(tree[1]);

	cout << ans;

}