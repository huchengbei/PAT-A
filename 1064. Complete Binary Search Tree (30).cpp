/*
* Problem: 1064. Complete Binary Search Tree (30)
* Author: HQ
* Time: 2018-03-07
* State: Done
* Memo: ½¨Ê÷¡¢·ÖÖÎ
*/
#include "cmath"
#include "iostream"
#include "vector"
#include "algorithm"
using namespace std;

vector<int> seq, tree;
int N;

void change(int pos, int b, int e) {
	if (b > e)
		return;
	int length = e - b + 1;
	if (length == 1) {
		tree[pos] = seq[b];
		return;
	}
	int left;
	int level = (int)(log(length) / log(2)) + 1;
	int lastlevel = length - pow(2, level - 1) + 1;
	int mid = pow(2, level - 2);
	if (lastlevel >= mid)
		left = mid * 2 - 1;
	else
		left = mid * 2 - 1 + lastlevel - mid;
	tree[pos] = seq[b + left];
	change(pos*2,b, b + left - 1);
	change(pos*2+1,b + left + 2 - 1,e);
}

int main() {
	cin >> N;
	int x;
	for (int i = 0; i < N; i++) {
		cin >> x;
		seq.push_back(x);
	}
	tree.resize(N + 1);
	sort(seq.begin(),seq.end());
	change(1,0,seq.size() - 1);
	for (int i = 1; i < N; i++)
		cout << tree[i]<< " ";
	cout << tree[N] << endl;
	system("pause");
}
