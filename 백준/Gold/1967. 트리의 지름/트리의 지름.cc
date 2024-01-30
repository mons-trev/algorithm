#include<stdio.h>
#include<vector>
#include<algorithm>

using namespace std;

struct Node {
	vector<pair<Node*, short>> child; // 자식 노드, 가중치
};

Node* tree[10001];
int ans = 0;

int findmax(Node* root) {
	if (root->child.size() == 0) {
		return 0;
	}
	vector<int> dist;
	for (short i = 0; i < root->child.size(); ++i) {
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
	short n;
	scanf("%d", &n);
	//트리 생성
	for (short i = 0; i < 10001; ++i) {
		tree[i] = new Node();
	}
	tree[1] = new Node();
	for (short i = 0; i < n-1; ++i) {
		short p, c, d;//부모 라벨, 자식 라벨, 가중치
		scanf("%d %d %d", &p, &c, &d);
		tree[p]->child.push_back({ tree[c],d });
	}

	findmax(tree[1]);

	printf("%d", ans);

}