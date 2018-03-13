/*
* Problem: 1132. Cut Integer (20)
* Author: HQ
* Time: 2018-03-13
* State: Done
* Memo: ×Ö·û´®
*/
#include "iostream"
#include "string"
using namespace std;

string s;
int N,Z, A, B;

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> s;
		int l = s.size();
		Z = A = B = 0;
		for (int j = 0; j < l / 2; j++) {
			A = A * 10 + s[j] - '0';
			Z = Z * 10 + s[j] - '0';
		}
		for (int j = l / 2; j < l; j++) {
			B = B * 10 + s[j] - '0';
			Z = Z * 10 + s[j] - '0';
		}
		if(A == 0 || B == 0)
			cout << "No" << endl;
		else if (Z % A != 0)
			cout << "No" << endl;
		else if((Z / A) % B != 0)
			cout << "No" << endl;
		else
			cout << "Yes" << endl;
	}
	system("pause");
}