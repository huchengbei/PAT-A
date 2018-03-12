/*
* Problem: 1122. Hamiltonian Cycle (25)
* Author: HQ
* Time: 2018-03-12
* State: Done
* Memo:  set
*/
#include "iostream"
#include "set"
using namespace std;

int G[200 + 5][200 + 5];

int N, M,K;

int main() {
	cin >> N >> M;
	int x, y;
	for (int i = 0; i < M; i++) {
		cin >> x >> y;
		G[x][y] = 1;
		G[y][x] = 1;
	}
	cin >> K;
	set<int> route;
	for (int i = 0; i < K; i++) {
		int n;
		route.clear();
		cin >> n >> x;
		int start = x;
		int flag = true;
		route.insert(x);
		for (int j = 1; j < n; j++) {
			cin >> y;
			if (!G[x][y])
				flag = false;
			x = y;
			route.insert(y);
		}
		if (flag && route.size() == N && start == y && n == N + 1)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	system("pause");
}