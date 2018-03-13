/*
* Problem: 1134. Vertex Cover (25)
* Author: HQ
* Time: 2018-03-13
* State: Done
* Memo: set
*/
#include "iostream"
#include "set"
#include "vector"
using namespace std;

struct Node {
	int b;
	int e;
};

int N, M, K;
set<int> v;
vector<struct Node> edges;

int main() {
	scanf("%d %d",&N, &M);
	int x,y;
	for (int i = 0; i < M; i++) {
		scanf("%d %d", &x, &y);
		struct Node temp = { x,y };
		edges.push_back(temp);
	}
	int n;
	scanf("%d", &K);
	for (int i = 0; i < K; i++) {
		scanf("%d", &n);
		v.clear();
		for (int j = 0; j < n; j++) {
			scanf("%d", &x);
			v.insert(x);
		}
		bool flag = true;
		for (int j = 0; j < M; j++) {
			if (v.find(edges[j].b) == v.end() && v.find(edges[j].e) == v.end()) {
				flag = false;
				break;
			}
		}
		if (flag)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
	
	system("pause");
}