/*
* Problem: 1124. Raffle for Weibo Followers (20)
* Author: HQ
* Time: 2018-03-12
* State: Done
* Memo: 
*/
#include "iostream"
#include "vector"
#include "map"
#include "string"
using namespace std;

vector<string> followers;
vector<string> win;
map<string,bool> winner;
int M,N,S;

int main() {
	cin >> M >> N >> S;
	followers.resize(M);
	for (int i = 0; i < M; i++) {
		cin >> followers[i];
	}
	for (int j = 0, i = S - 1; i < M; i++) {
		if (j % N == 0) {
			if (winner[followers[i]])
				continue;
			else {
				winner[followers[i]] = true;
				win.push_back(followers[i]);
			}
		}
		j++;
	}
	if (!win.size())
		cout << "Keep going..." << endl;
	for (int i = 0; i < win.size(); i++) {
		cout << win[i] << endl;
	}
	system("pause");
}