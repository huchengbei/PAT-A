/*
* Problem: 1125. Chain the Ropes (25)
* Author: HQ
* Time: 2018-03-12
* State: Done
* Memo: 优先队列
*/
#include "iostream"
#include "queue"
#include "functional"
using namespace std;

priority_queue<double, vector<double>, greater<double> > ropes;
int N;

int main() {
	cin >> N;
	double x,y;
	for (int i = 0; i < N; i++) {
		cin >> x;
		ropes.push(x);
	}
	while (ropes.size() > 1) {
		x = ropes.top();
		ropes.pop();
		y = ropes.top();
		ropes.pop();
		ropes.push((x + y) / 2);
	}
	cout << (int)ropes.top() << endl;
	system("pause");
}