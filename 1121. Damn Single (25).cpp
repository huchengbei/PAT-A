/*
* Problem: 1121. Damn Single (25)
* Author: HQ
* Time: 2018-03-11
* State: Done
* Memo: set¡¢mapµÄÓ¦ÓÃ
*/
#include "iostream"
#include "set"
#include "map"
#include "string"
using namespace std;

map<string,string> couple;
set<string> single;
int N,M;


int main() {
	cin >> N;
	string x,y;
	for (int i = 0; i < N; i++) {
		cin >> x>>y;
		couple[x] = y;
		couple[y] = x;
	}
	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> x;
		if (single.find(couple[x]) != single.end())
			single.erase(single.find(couple[x]));
		else
			single.insert(x);
	}
	cout << single.size() << endl;
	bool first = true;
	for (set<string>::iterator it = single.begin(); it != single.end(); it++) {
		if (first) {
			cout << *it;
			first = false;
		}
		else
			cout << " " << *it;
	}
	system("pause");
}