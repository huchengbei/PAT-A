/*
* Problem: 1090. Highest Price in Supply Chain (25)
* Author: HQ
* Time: 2017-09-03 00:32
* State: Done
* Memo:
*/
#include "iostream"
#include "vector"
using namespace std;

vector< vector<int> > G;
vector<int> customer;
int N;
double P;
double r;
double ans;
int level,num,templevel;
int root;

void init(){
	cin>>N>>P>>r;
	G.resize(N);
	customer.resize(N,0);
	int x;
	for(int i = 0; i < N; i++){
		cin>>x;
		if(x == -1)
			root = i;
		else{
			customer[x]++;
			G[x].resize(customer[x],i);
		}
		
	}
	level = templevel = 0;
	num = 0;
}

void dfs(int r){
	int i,j;
	for(i = 0; i < customer[r]; i++){
		templevel ++;
		dfs(G[r][i]);
		templevel --;
	}
	if(!customer[r]){
		if(templevel > level){
			level = templevel;
			num = 1;
		}else if(templevel == level){
			num ++;
		}
	}
}

int main(){
	init();
	dfs(root);
	ans =P;
	for(int i =0;i < level; i++)
		ans *= 1 + r / 100;
	printf("%.2f %d",ans,num);
	system("pause");
}