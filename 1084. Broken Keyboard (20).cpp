/*
* Problem: 1084. Broken Keyboard (20)
* Author: HQ
* Time: 2017-08-30 00:37
* State: Done
* Memo:
*/
#include "iostream"
#include "string"
#include "map"

using namespace std;

map<char,bool> isPrinted;

void printC(char c){
	if(c >= 'a' && c <= 'z')
		c = c + 'A' - 'a';
	if(isPrinted[c])
		return;
	printf("%c",c);
	isPrinted[c] = true;
}

int main(){
	string a,b;
	cin>>a>>b;
	int l1 = a.length(),l2 = b.length(),i,j;
	for(i = 0, j = 0;i < l1;){
		if(j >= l2){
			printC(a[i++]);
			continue;
		}
		if(a[i] == b[j]){
			i++;
			j++;
		}else
			printC(a[i++]);
	}
	system("pause");
}