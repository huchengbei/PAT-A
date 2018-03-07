/*
* Problem: 1061. Dating (20)
* Author: HQ
* Time: 2018-03-06
* State: Done
* Memo: 
*/
#include "iostream"
#include "string"
#include "algorithm"
using namespace std;

string fir, sec, thr, fou;

string s2day(char x) {
	string weekdays[] = { "MON","TUE","WED","THU","FRI","SAT","SUN" };
	return weekdays[x - 'A'];
}
int main() {
	cin >> fir >> sec >> thr >> fou;
	string day;
	int hour, minite;
	int lf = min(fir.length(),sec.length());
	bool is_day = true;
	for (int i = 0; i < lf; i++) {
		if (fir[i] == sec[i]) {
			if (is_day) {
				if (fir[i] >= 'A' && fir[i] <= 'G') {
					day = s2day(fir[i]);
					is_day = false;
				}
			}
			else {
				if (fir[i] >= 'A' && fir[i] <= 'N') {
					hour = fir[i] - 'A' + 10;
					break;
				}
				if (isdigit(fir[i])) {
					hour = fir[i] - '0';
					break;
				}
			}
		}
	}
	lf = min(thr.length(),fou.length());
	for (int i = 0; i < lf; i++) {
		if (isalpha(thr[i])) {
			if (thr[i] == fou[i]) {
				minite = i;
				break;
			}
		}
	}
	cout << day << " ";
	printf("%02d:%02d\n", hour, minite);
	system("pause");
	//return 0;
}