/*
* Problem: 1123. Is It a Complete AVL Tree (30)
* Author: HQ
* Time: 2018-03-12
* State: Done
* Memo: 平衡二叉树、完全二叉树
*/
#include "iostream"
#include "algorithm"
#include "queue"
using namespace std;

typedef struct Node {
	int data = -1;
	struct Node * left = NULL;
	struct Node *  right = NULL;
};

int N;

int deap(struct Node * root) {
	if (root == NULL)
		return 0;
	return max(deap(root->left), deap(root->right)) + 1;
}

void leftRotate(struct Node * &root) {
	struct Node *  temp;
	temp = root;
	root = root->right;
	temp->right = root->left;
	root->left = temp;
}

void rightRotate(struct Node *  &root) {
	struct Node *  temp;
	temp = root;
	root = root->left;
	temp->left = root->right;
	root->right = temp;
}

void insert(struct Node* &root, int x,int &pos) { // pos 0:本位插入，1左边，2右边
	if (root->data == -1) {
		root->data = x;
		return;
	}
	int p = 0;
	if (x < root->data) {
		if (root->left == NULL)
			root->left = new Node;
		pos = 1;
		insert(root->left, x,p);
	}
	else {
		if (root->right == NULL)
			root->right = new Node;
		pos = 2;
		insert(root->right, x,p);
	}
	int l = deap(root->left);
	int r = deap(root->right);
	if (l - r > 1) {
		if (p == 1) {
			rightRotate(root);
		}
		if (p == 2) {
			leftRotate(root->left);
			rightRotate(root);
		}
	}
	if (r - l > 1) {
		if (p == 1) {
			rightRotate(root->right);
			leftRotate(root);
		}
		if (p == 2) {
			leftRotate(root);
		}
	}
}


int main() {
	struct Node * root = new Node;
	cin >> N;
	int x;
	for (int i = 0; i < N; i++) {
		cin >> x;
		int pos = 0;
		insert(root, x, pos);
	}
	queue<struct Node*> q;
	struct Node * temp;
	q.push(root);
	bool first = true;
	bool end = false, flag = true;
	while (!q.empty()) {
		temp = q.front();
		q.pop();
		if (end && (temp->left != NULL || temp->right != NULL))
			flag = false;
		if (temp->left == NULL && temp->right != NULL)
			flag = false;
		if (temp->left != NULL)
			q.push(temp->left);
		else
			end = true;
		if (temp->right != NULL)
			q.push(temp->right);
		else
			end = true;
		if (first) {
			cout << temp->data;
			first = false;
		}else
			cout << " " << temp->data;
	}
	cout << endl << (flag ? "YES" : "NO") << endl;
	system("pause");
}