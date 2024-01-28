#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<vector>

using namespace std;
vector<int> list;
struct Node {
	int label;
	Node* left=NULL;
	Node* right=NULL;
};

Node* insertNode(Node* root, int tar) {

	if (root == NULL) {
		Node* n = new Node();
		n->label = tar;
		return n;
	}
	if (tar < root->label) {
		root->left = insertNode(root->left, tar);
	}
	else if (tar > root->label) {
		root->right = insertNode(root->right, tar);
	}
	return root;
}

void postSearch(Node* root) {
	if (root==NULL) {
		return;
	}
	postSearch(root->left);
	postSearch(root->right);
	printf("%d\n", root->label);
	return;
}

int main() {
	Node* root = NULL;
	int lb;
	scanf(" %d", &lb);
	list.push_back(lb);
	while (scanf(" %d",&lb)!=EOF) {
		list.push_back(lb);
	}
	for (auto i : list) {
		root = insertNode(root, i);
	}
	postSearch(root);
}