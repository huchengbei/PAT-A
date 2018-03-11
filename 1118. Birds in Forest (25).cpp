/*
* Problem: 1118. Birds in Forest (25)
* Author: HQ
* Time: 2018-03-11
* State: Done
* Memo:
*/
#include "iostream"
#include "vector"
#include "algorithm"
using namespace std;

int father[10000 + 5];
int N,Q;

int getF(int x) {
	int a = father[x];
	if (a != x) {
		father[x] = getF(a);
		return father[x];
	}
	else
		return a;
}

void Union(int x, int y) {
	int a = getF(x);
	int b = getF(y);
	b = b ? b : y;
	if (a != b)
		father[b] = x;
}

int main() {
	cin >> N;
	int x, y,M,K;
	for (int i = 0; i < N; i++) {
		cin >> K;
		cin >> x;
		M = max(M, x);
		if (father[x] == 0)
			father[x] = x;
		for (int j = 1; j < K; j++) {
			cin >> y;
			M = max(M, y);
			Union(x, y);
		}
	}
	int tree = 0, birds = 0;
	int i;
	for (i = 1; i <= M; i++) {
		father[i] = getF(father[i]);
		if (father[i])
			birds++;
		if (father[i] == i)
			tree++;
	}
	cout << tree << " " << birds << endl;
	cin >> Q;
	for (int i = 0; i < Q; i++) {
		cin >> x >> y;
		if (getF(x) == getF(y))
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
	system("pause");
}