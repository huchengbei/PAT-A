/*
* Problem: 1094. The Largest Generation (25)
* Author: HQ
* Time: 2017-09-05 22:52
* State: Done
* Memo:
*/
#include "iostream"
#include "vector"
#include "queue"
using namespace std;

int N,M;
vector<vector<int>> G;
int level,ans;


void init(){
	cin>>N>>M;
	G.resize(N + 1);
	int i,k,j,x;
	for(i = 0; i < M; i++){
		cin>>x>>k;
		G[x].resize(k);
		for(j = 0; j < k; j++){
			cin>>G[x][j];
		}
	}
}

void bfs(){
	int root = 1;
	int x,i;
	queue<int> que;
	level = 1;
	ans = 1;

	int numInLevel = 0,numInNextLevel = 0,num = 0,tempLevel = 0;

	que.push(root);
	numInLevel ++;
	tempLevel ++;
	while(!que.empty()){
		x = que.front();
		que.pop();
		num ++;
		for(i = 0; i < G[x].size(); i++){
			que.push(G[x][i]);
			numInNextLevel ++;
		}
		if(num == numInLevel){
			if(numInNextLevel > ans){
				level = tempLevel + 1;
				ans = numInNextLevel;
			}
			tempLevel ++;
			numInLevel = numInNextLevel;
			numInNextLevel = 0;
			num = 0;
		}
	}

}

int main(){
	init();
	bfs();
	printf("%d %d",ans,level);
	system("pause");
}