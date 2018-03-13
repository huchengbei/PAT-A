/*
* Problem: 1133. Splitting A Linked List (25)
* Author: HQ
* Time: 2018-03-13
* State: Done
* Memo: Á´±í
*/
#include "iostream"
#include "vector"
using namespace std;

struct Node {
	int data;
	int next;
};

int N,K;
int start;
vector<struct Node> addrs;

int main() {
	scanf("%d %d %d", &start, &N, &K);
	int x;
	int add, next;
	addrs.resize(1000000);
	for (int i = 0; i < N; i++) {
		scanf("%d %d %d", &add, &x, &next);
		struct Node temp = { x,next };
		addrs[add] = temp;
	}
	bool first = true;
	int s = start;
	while (s != -1) {
		if (addrs[s].data < 0) {
			if (first)
				first = false;
			else
				printf(" %05d\n", s);
			printf("%05d %d", s, addrs[s].data);
		}
		s = addrs[s].next;
	}
	s = start;
	while (s != -1) {
		if (addrs[s].data >= 0 && addrs[s].data <= K) {
			if (first)
				first = false;
			else
				printf(" %05d\n", s);
			printf("%05d %d", s, addrs[s].data);
		}
		s = addrs[s].next;
	}
	s = start;
	while (s != -1) {
		if (addrs[s].data > K) {
			if (first)
				first = false;
			else
				printf(" %05d\n", s);
			printf("%05d %d", s, addrs[s].data);
		}
		s = addrs[s].next;
	}
	cout << " -1"<< endl;
	system("pause");
}