/*
* Problem: 1103. Integer Factorization (30)
* Author: HQ
* Time: 2017-09-11 22:31
* State: Done
* Memo:
*/
#include "iostream"
#include "math.h"
using namespace std;

int N,K,P;
int factor[20 + 1];
int maxNum;
int ans[400 + 5];
int sumOfAns = 0;
int tempAns[400 + 5];

void init(){
	cin>>N>>K>>P;
	maxNum = 1;
	factor[1] = 1;
	while(factor[maxNum] <= N){
		maxNum ++;
		factor[maxNum] = pow(maxNum * 1.0,P);
	}
	maxNum --;
	sumOfAns = 0;
}

void dfs(int n,int maxnum,int k){
	static int sum = 0;
	if(n > factor[maxnum] * k)
		return;
	if( ( n && (!k)) || ((!n) && k))
		return;
	int i;
	if(n == 0 && k == 0){
		if(sum > sumOfAns){
			for(int j = 1; j <= K; j++)
				ans[j] = tempAns[j];
			sumOfAns = sum;
		}
		return;
	}
	for(i = maxnum; i >= 1; i--){
		if(n - factor[i] < 0)
			continue;
		tempAns[K - k + 1] = i;
		sum += i;
		dfs(n - factor[i],i,k-1);
		sum -=i;
	}
}

void printAns(){
	if(!sumOfAns){
		cout<<"Impossible"<<endl;
		return;
	}
	cout<<N<<" = "<<ans[1]<<"^"<<P;
	for(int i= 2; i <= K; i++){
		cout<<" + "<<ans[i]<<"^"<<P;
	}
	cout<<endl;
}

int main(){
	init();
	dfs(N,maxNum,K);
	printAns();
	system("pause");
}
