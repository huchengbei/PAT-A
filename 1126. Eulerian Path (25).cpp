/*
* Problem: 1126. Eulerian Path (25)
* Author: HQ
* Time: 2018-03-12
* State: Done
* Memo:
*/
#include "iostream"
using namespace std;

int N,M;
int degree[500 + 5];
int G[500 + 5][500 + 5];
int visit[500 + 5];
int even = 0;
int cnt = 0;

void dfs(int x) {
	visit[x] = 1;
	cnt++;
	for (int i = 1; i <= N; i++) {
		if (!visit[i] && G[x][i])
			dfs(i);
	}
}

int main() {
	cin >> N >>M;
	int x, y;
	fill(degree, degree + 500 + 5, 0);
	fill(visit, visit + 500 + 5, 0);
	for (int i = 0; i < M; i++) {
		cin >> x >> y;
		G[x][y] = 1;
		G[y][x] = true;
		degree[x] ++;
		degree[y] ++;
	}
	bool first = true;
	for (int i = 1; i <= N; i++) {
		if (first) {
			cout << degree[i];
			first = false;
		}
		else
			cout << " " << degree[i];
		if (degree[i] % 2 == 0)
			even++;
	}
	cout << endl;
	dfs(1);
	if(cnt != N)
		cout << "Non-Eulerian" << endl;
	else if (even == N)
		cout << "Eulerian" << endl;
	else if(even == N-2)
		cout << "Semi-Eulerian" << endl;
	else
		cout << "Non-Eulerian" << endl;
	
	system("pause");
}