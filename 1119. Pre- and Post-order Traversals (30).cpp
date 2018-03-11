/*
* Problem: 1119. Pre- and Post-order Traversals (30)
* Author: HQ
* Time: 2018-03-11
* State: Done
* Memo:
*/
#include "iostream"
#include "vector"
#include "set"
using namespace std;

struct Node {
	int data;
	struct Node *left,*right;
};

set<int> pre_left, post_left;
vector<int> pre, post;
bool flag = true;
int N;

void makeTree(struct Node *root, int s1, int s2, int l) {
	root->data = pre[s1];
	if (l == 1) {
		root->left = root->right = NULL;
		return;
	}
	pre_left.clear();
	post_left.clear();
	for (int i = 0; i < l - 1; i++) {
		pre_left.insert(pre[s1 + 1 + i]);
		post_left.insert(post[s2 + i]);
		if (pre_left == post_left)
			break;
	}
	int size = pre_left.size();
	if (size == l - 1) {
		flag = false;
	}
	if (size > 0) {
		root->left = new struct Node;
		makeTree(root->left, s1 + 1, s2, size);
	}
	if (l - 1 - size > 0) {
		root->right = new struct Node;
		makeTree(root->right, s1 + 1 + size, s2 + size, l - 1 - size);
	}
	else
		root->right = NULL;

}

void inOrder(struct Node *root1) {
	static bool first = true;
	if (root1->left != NULL)
		inOrder(root1->left);
	if (first) {
		printf("%d", root1->data);
		first = false;
	}else
		printf(" %d", root1->data);
	if (root1->right != NULL)
		inOrder(root1->right);
}

int main() {
	cin >> N;
	pre.resize(N);
	post.resize(N);
	for (int i = 0; i < N; i++)
		cin >> pre[i];
	for (int i = 0; i < N; i++)
		cin >> post[i];
	struct Node *root = new struct Node;
	makeTree(root,0,0,N);
	printf("%s\n", flag ? "Yes" : "No");
	inOrder(root);
	system("pause");
}