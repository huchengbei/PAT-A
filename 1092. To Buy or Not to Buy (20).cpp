/*
* Problem: 1092. To Buy or Not to Buy (20)
* Author: HQ
* Time: 2017-09-04 22:59
* State: Done
* Memo:
*/
#include "iostream"
#include "map"
#include "string"
using namespace std;

map<char,int> c2i;

int eva[65];
int shop[65];
int more=0,miss=0;

void init(){
	string a,b;
	cin>>a>>b;
	int i,id;
	for(i = '0'; i <= '9'; i++){ // 此时i可理解为char型
		id = i - '0';
		c2i[i] = id;
	}
	for(i = 'a'; i <= 'z'; i++){ // 此时i可理解为char型
		id = i - 'a' + 10;
		c2i[i] = id;
	}
	for(i = 'A'; i <= 'Z'; i++){ // 此时i可理解为char型
		id = i - 'A' + 36;
		c2i[i] = id;
	}
	for(i = 0; i < a.length(); i++){
		shop[c2i[a[i]]] ++;
	}
	for(i = 0; i < b.length(); i++){
		eva[c2i[b[i]]] ++;
	}
}

void cal(){
	for(int i= 0; i < 62; i++){
		if(shop[i] > eva[i])
			more += shop[i] - eva[i];
		else
			miss += eva[i] - shop[i];
	}
}

int main(){
	init();
	//prin();
	cal();
	if(miss > 0)
		printf("No %d",miss);
	else
		printf("Yes %d",more);
	system("pause");
}