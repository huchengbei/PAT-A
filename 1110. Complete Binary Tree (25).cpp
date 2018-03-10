/*
* Problem: 1110. Complete Binary Tree (25)
* Author: HQ
* Time: 2018-03-10
* State: Done
* Memo:
*/
#include "iostream"
#include "string"
#include "vector"
using namespace std;
string node[20 + 2][2];
bool visit[20 + 2] = { false };
int tree[20 + 2];
bool flag = true;

int N;

void makeTree(int pos, int x) {
	if (pos > N || x >= N) {
		return;
	}
	tree[pos] = x;
	if (flag && node[x][0][0] != '-')
		makeTree(pos * 2, stoi(node[x][0]));
	if (flag && node[x][1][0] != '-')
		makeTree(pos * 2 + 1, stoi(node[x][1]));
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin>>node[i][0]>>node[i][1];
		if (node[i][0][0] != '-') {
			visit[stoi(node[i][0])] = true;
		}
		if (node[i][1][0] != '-') {
			visit[stoi(node[i][1])] = true;
		}
	}
	fill(tree, tree+N+1, -1);
	int i;
	for (i = 0; i < N; i++) {
		if (!visit[i])
			break;
	}
	makeTree(1, i);
	for(int j = 1; j <= N; j++)
		if (tree[j] == -1) {
			printf("NO %d\n", i);
			flag = false;
			break;
		}
	if(flag)
		printf("YES %d\n", tree[N]);
	system("pause");
}
