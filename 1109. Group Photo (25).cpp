/*
* Problem: 1109. Group Photo (25)
* Author: HQ
* Time: 2018-02-08
* State: Done
* Memo: ÅÅÐò ÊÖ¶¯Ä£Äâ
*/
#include "iostream"
#include "string"
#include "algorithm"
#include "vector"
using namespace std;

struct Stu {
	string name;
	int height;
};

int cmp(struct Stu a, struct Stu b) {
	if (a.height == b.height)
		return a.name < b.name;
	return a.height > b.height;
}

vector<struct Stu> students;
int N = 0, K = 0;

void printAns() {
	int m = N / K;
	int start = 0;
	int n;
	bool first;
	for (int row = 1; row <= K; row++) {
		first = true;
		n = N - (K - row) * m - start;
		int i = n >> 1 << 1;
		while (i) {
			if (first) {
				cout << students[start + i - 1].name;
				first = false;
			}else
				cout << " " << students[start + i - 1].name;
			i = i - 2;
		}
		i = 1;
		while (i <= n) {
			if (first) {
				cout << students[start + i - 1].name;
				first = false;
			}
			else
				cout << " " << students[start + i - 1].name;
			i = i + 2;
		}
		start += n;
		cout << endl;
	}
}

int main() {
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		struct Stu temp;
		cin >> temp.name >> temp.height;
		students.push_back(temp);
	}
	sort(students.begin(), students.end(), cmp);
	printAns();
	system("pause");
	return 0;
}