/*
* Problem: 1127. ZigZagging on a Tree (30)
* Author: HQ
* Time: 2018-03-13
* State: Done
* Memo: ¶ÓÁÐ Õ» ½¨Ê÷
*/
#include "iostream"
#include "queue"
#include "stack"
#include "vector"
using namespace std;

struct Node {
	int data = 0;
	struct Node * left = NULL;
	struct Node * right = NULL;
};

int N;
vector<int> inorder, postorder;

int findPos(int x,int s,int l) {
	for (int i = 0; i < l; i++) {
		if (inorder[s + i] == x)
			return s + i;
	}
	return -1;
}

struct Node * makeTree(int s1, int s2, int n) {
	struct Node *root = NULL;
	int x = postorder[s2 + n - 1];
	int pos = findPos(x, s1, n);
	if (pos != -1) {
		root = new struct Node;
		root->data = x;
		if (pos - s1 > 0)
			root->left = makeTree(s1, s2, pos - s1);
		if (s1 + n - pos - 1> 0)
			root->right = makeTree(pos + 1, s2 + pos - s1, s1 + n - pos - 1);
	}
	return root;
}

void levelOrder(struct Node * root) {
	queue<struct Node *> q;
	stack<struct Node *> s;
	struct Node * temp;
	q.push(root);
	bool first = true;
	bool left = false;
	int cnt = 0, num = 1, tempnum = 0;
	while (!q.empty()) {
		temp = q.front();
		q.pop();
		if (first) {
			cout << temp->data;
			first = false;
		}
		else
			cout << " " << temp->data;
		if (left) {
			if (temp->left != NULL) {
				s.push(temp->left);
				tempnum++;
			}
			if (temp->right != NULL) {
				s.push(temp->right);
				tempnum++;
			}
		}
		else {
			if (temp->right != NULL) {
				s.push(temp->right);
				tempnum++;
			}
			if (temp->left != NULL) {
				s.push(temp->left);
				tempnum++;
			}
		}
		cnt++;
		if (cnt == num) {
			num = tempnum;
			tempnum = 0;
			cnt = 0;
			left = !left;
			while (!s.empty()) {
				q.push(s.top());
				s.pop();
			}
		}
	}
}

int main() {
	cin >> N;
	inorder.resize(N);
	postorder.resize(N);
	for (int i = 0; i < N; i++)
		cin >> inorder[i];
	for (int i = 0; i < N; i++)
		cin >> postorder[i];
	struct Node * root;
	root = makeTree(0, 0, N);
	levelOrder(root);
	cout << endl;
	system("pause");
}