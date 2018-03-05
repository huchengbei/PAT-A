/*
* Problem: 1069. The Black Hole of Numbers (20)
* Author: HQ
* Time: 2017-08-18 00:11
* State: Done
* Memo:
*/
#include "stdio.h"
#include <algorithm>
#include <vector>
using namespace std;
int big(int num){
	vector<int> arr;
	arr.push_back(num / 1000);
	arr.push_back(num / 100 % 10);
	arr.push_back(num / 10 % 10);
	arr.push_back(num % 10);
	sort(arr.begin(),arr.end());
	return arr[3] * 1000 + arr[2] * 100 + arr[1] * 10 + arr[0];
}

int small(int num){
	vector<int> arr;
	arr.push_back(num / 1000);
	arr.push_back(num / 100 % 10);
	arr.push_back(num / 10 % 10);
	arr.push_back(num % 10);
	sort(arr.begin(),arr.end());
	return arr[0] * 1000 + arr[1] * 100 + arr[2] * 10 + arr[3];
}

int main(){
	int num = 0;
	scanf("%d",&num);
	int b = big(num);
	int s = small(num);
	int newnum = b - s;
	if (num == newnum)
		printf("%04d - %04d = %04d\n",b,s,newnum);
	while(num != newnum){
		printf("%04d - %04d = %04d\n",b,s,newnum);
		num = newnum;
		b = big(num);
		s = small(num);
		newnum = b - s;
	}
	//system("pause");
}