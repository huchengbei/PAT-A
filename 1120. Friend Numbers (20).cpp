/*
* Problem: 1120. Friend Numbers (20)
* Author: HQ
* Time: 2018-03-11
* State: Done
* Memo: setµÄÓ¦ÓÃ
*/
#include "iostream"
#include "set"
using namespace std;

set<int> friendId;
int N;

int getSum(int x) {
	int s = 0;
	while (x) {
		s += x % 10;
		x /= 10;
	}
	return s;
}

int main() {
	cin >> N;
	int x;
	for (int i = 0; i < N; i++) {
		cin >> x;
		friendId.insert(getSum(x));
	}
	cout << friendId.size() << endl;
	bool first = true;
	for (set<int>::iterator it = friendId.begin(); it != friendId.end(); it++) {
		if (first) {
			cout << *it;
			first = false;
		}
		else
			cout << " " << *it;
	}
	cout << endl;
	system("pause");
}