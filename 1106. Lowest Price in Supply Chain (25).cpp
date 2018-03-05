/*
* Problem: 1106. Lowest Price in Supply Chain (25)
* Author: HQ
* Time: 2017-09-12 23:29
* State: Done
* Memo: 
*/
#include "iostream"
#include "vector"
#include "queue"
#include "cmath"
using namespace std;

vector<vector<int>> G;

int N;
double P,r;
int ansLevel,ansNum;

void init(){
	cin>>N>>P>>r;
	G.resize(N);
	int i,j,k,x;
	for(i = 0; i < N; i++){
		cin>>k;
		for(j = 0; j < k; j++){
			cin>>x;
			G[i].push_back(x);
		}
	}
}

void bfs(){
	queue<int> que;
	bool flag = false;
	int cnt = 0,num = 1;
	int nextNum = 0;
	ansLevel = 1;
	ansNum = 0;
	que.push(0);
	int x,i;
	while(!que.empty()){
		x = que.front();
		que.pop();
		cnt ++;
		if(G[x].size() == 0){
			flag = true;
			ansNum ++;
		}
		for(i = 0; i < G[x].size(); i++){
			que.push(G[x][i]);
			nextNum ++;
		}
		if(cnt == num){
			if(flag)
				return;
			ansLevel ++;
			num = nextNum;
			nextNum = 0;
			cnt = 0;
		}
	}
}

int main(){
	init();
	bfs();
	printf("%.4f %d\n",P * pow(1+ r / 100,ansLevel - 1),ansNum);
	system("pause");
}
