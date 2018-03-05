/*
* Problem: 1105. Spiral Matrix (25)
* Author: HQ
* Time: 2017-09-12 22:51
* State: Done
* Memo:
*/
#include "iostream"
#include "math.h"
#include "algorithm"
#include "vector"
using namespace std;

int N;
vector<vector<int>> G;
vector<int> data;
int m,n;

bool cmp(int a,int b){
	return a>b;
}

void init(){
	cin>>N;
	int x;
	for(int i = 0; i < N; i++){
		cin>>x;
		data.push_back(x);
	}
}

void cal(){
	sort(data.begin(),data.end(),cmp);
	m = sqrt(N * 1.0);
	while(N % m){
		m ++;
	}
	m = max(m,N/m);
	n = N/m;
	G.resize(m);
	for(int i = 0; i < m; i ++)
		G[i].resize(n);
}

void build_G(){
	int k = 0;
	int mm = m - 1,nn = n;
	int i = 0,j = 0;
	while(k<N){
		if(nn){
			for(int t = 0; t < nn; t++){
				G[i][j] = k;
				k ++;
				j ++;
			}
			j --;
			i ++;
			nn--;
		}
		if(k >= N)
			break;
		if(mm){
			for(int t = 0; t < mm; t++){
				G[i][j] = k;
				k ++;
				i ++;
			}
			i --;
			j --;
			mm--;
		}
		if(k >= N)
			break;
		if(nn){
			for(int t = 0; t < nn; t++){
				G[i][j] = k;
				k ++;
				j --;
			}
			j ++;
			i --;
			nn--;
		}
		if(k >= N)
			break;
		if(mm){
			for(int t = 0; t < mm; t++){
				G[i][j] = k;
				k ++;
				i --;
			}
			i ++;
			j ++;
			mm--;
		}
	}
}

void print_G(){
	for(int i =0;i<m;i++){
		cout<<G[i][0];
		for(int j=1;j<n;j++)
			cout<<"\t"<<G[i][j];
		cout<<endl;
	}
}
void print_GData(){
	for(int i =0;i<m;i++){
		cout<<data[G[i][0]];
		for(int j=1;j<n;j++)
			cout<<" "<<data[G[i][j]];
		cout<<endl;
	}
}

int main(){
	init();
	if(N == 0){
		cout<<data[0]<<endl;
		return 0;
	}
	cal();
	build_G();
	print_GData();
	system("pause");
}
