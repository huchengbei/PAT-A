/*
* Problem: 1117. Eddington Number(25)
* Author: HQ
* Time: 2018-03-11s
* State: Done
* Memo:
*/
#include "iostream"
#include "vector"
#include "algorithm"
using namespace std;

vector<int> dis;
int N;

int main() {
	cin >> N;
	int x;
	for (int i = 0; i < N; i++) {
		cin >> x;
		dis.push_back(x);
	}
	sort(dis.begin(), dis.end());
	int i;
	for (i = N; i > 0; i--) {
		if (dis[N - i] > i) {
			break;
		}
	}
	cout << i << endl;
	system("pause");
}