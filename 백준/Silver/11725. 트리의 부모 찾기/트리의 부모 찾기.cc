#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<queue>
#include<vector>

using namespace std;

int n;
vector<int> input[100001];

struct Node {
	int label;
	Node* parent;
};

Node* list[100001];

int main() {
	scanf("%d", &n);
	list[1] = new Node();
	list[1]->label = 1;
	list[1]->parent = NULL;
	for (int i = 0; i < n-1; ++i) {
		int a, b;
		scanf("%d %d", &a, &b);
		input[a].push_back(b);
		input[b].push_back(a);
	}
	queue<pair<int,int>> q;
	for (int i = 0; i < input[1].size(); ++i) {
		q.push({ 1,input[1][i] });
	}

	while (!q.empty()) {
		int p = q.front().first;
		int c = q.front().second;
		q.pop();
		list[c] = new Node();
		list[c]->label = c;
		list[c]->parent = list[p];
		for (int i = 0; i < input[c].size(); ++i) {
			int a = input[c][i];
			if (list[a] == NULL) {
				q.push({ c,a });
			}
		}
	}
	for (int i = 2; i <= n; ++i) {
		printf("%d\n", list[i]->parent->label);
	}
}