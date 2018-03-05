/*
* Problem: 1093. Count PAT's (25)
* Author: HQ
* Time: 2017-09-04 23:27
* State: Done
* Memo:
*/
#include "iostream"
#include "string"
using namespace std;

string s;
long long P[100000 + 5];
long long T[100000 + 5];
long long ans = 0;

void init(){
	cin>>s;
	int i;
	P[0] = 0;
	for(i = 1; i < s.length(); i++){
		P[i] = (s[i-1] == 'P')?P[i - 1] + 1:P[i - 1];
	}
	T[s.length() - 1] = 0;
	for(i = s.length() - 2; i >= 0; i--){
		T[i] = (s[i+1] == 'T')?T[i + 1] + 1:T[i + 1];
	}
}

void cal(){
	int i;
	for(i = 1; i < s.length() - 1; i++){
		if(s[i] == 'A')
			ans += P[i] * T[i] % 1000000007;
	}
}

int main(){
	init();
	cal();
	cout<<ans % 1000000007<<endl;
	system("pause");
}