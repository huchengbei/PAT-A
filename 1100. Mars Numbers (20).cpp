/*
* Problem: 1100. Mars Numbers (20)
* Author: HQ
* Time: 2017-09-08 22:25
* State: Done
* Memo:
*/
#include "iostream"
#include "string"
#include "map"
#include "vector"
using namespace std;

string i2num[13] = {"tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct",	"nov", "dec"};;
string i2higherNum[13] = {"", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy","lok", "mer", "jou"};

bool isNum(string s){
	if(s[0] >= '0' && s[0] <= '9')
		return true;
	return false;
}

void cal(){
	int n;
	cin>>n;
	int x;
	string s;
	string s1,s2;
	getchar();
	for(int i=0;i<n;i++){
		getline(cin,s);
		if(isNum(s)){
			x = stoi(s);
			int a,b;
			a = x/13;
			b = x % 13;
			if(!a && !b)
				cout<<i2num[0]<<endl;
			if(!a && b)
				cout<<i2num[b]<<endl;
			if(a && !b)
				cout<<i2higherNum[a]<<endl;
			if(a && b)
				cout<<i2higherNum[a]<<" "<<i2num[b]<<endl;

		}else{
			if(s.length() == 4){
				cout<<0<<endl;
				continue;
			}
			s1 = string(s,0,3);
			x = 0;
			if(s.length()>3){
				s2 = string(s,4,3);
				for (int i = 1; i <= 12; i++) {
					if (s1 == i2higherNum[i]) {
						x += i * 13;
					}
					if (s2 == i2num[i]) {
						x += i;
					}
				}
			}else{
				for (int i = 1; i <= 12; i++) {
					if (s1 == i2higherNum[i]) {
						x += i * 13;
					}
					if (s1 == i2num[i]) {
						x += i;
					}
				}
			}
			cout<<x<<endl;
		}
	}
}

int main(){
	cal();
	system("pause");
}