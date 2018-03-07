/*
* Problem: 1063. Set Similarity (25)
* Author: HQ
* Time: 2018-03-07
* State: Done
* Memo:
*/
#include "iostream"
#include "algorithm"
#include "vector"
using namespace std;
vector<int> str[50 + 5];
int N,K;

void distinct(vector<int> &a) {
	int i = 1, j = 1;
	for (; j < a.size(); j++) {
		if (a[j] != a[j - 1])
			a[i++] = a[j];
	}
	a.resize(i);
}

double cal(int x, int y) {
	int j = 0;
	int cou = 0;
	for (int i = 0; i < str[x].size(); i++) {
		for (; j < str[y].size(); j++) {
			if (str[x][i] == str[y][j]) {
				cou++;
				j++;
				break;
			}
			if (str[x][i] < str[y][j])
				break;
		}
	}
	return (double)cou / (str[x].size() + str[y].size() - cou);
}

int main() {
	cin >> N;
	int m;
	int x;
	for (int i = 0; i < N; i++) {
		cin >> m;
		for (int j = 0; j < m; j++) {
			cin >> x;
			str[i].push_back(x);
		}
		sort(str[i].begin(), str[i].end());
		distinct(str[i]);
	}
	cin >> K;
	int y;
	for (int i = 0; i < K; i++) {
		cin >> x >> y;
		printf("%.1f%%\n",cal(x-1,y-1) * 100);
	}
	system("pause");
}