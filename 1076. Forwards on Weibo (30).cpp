/*
* Problem: 1076. Forwards on Weibo (30)
* Author: HQ
* Time: 2017-08-30 00:28
* State: Done
* Memo:
*/
#include "iostream"
#include "queue"
#include "vector"
using namespace std;

vector<bool> visited;
queue<int> que;
int G[1000 + 5][1000 + 5];
int N,L;


void init(){
	cin>>N>>L;
	fill(G[0],G[0]+ 1005*1005,0);
	int m,i,j;
	int k;
	for(i = 1; i <= N; i ++){
		cin>>m;
		for(j = 1; j <= m; j++){
			cin>>k;
			G[i][k] = 1;
		}
	}
}

void bfs(int root){
	visited.clear();
	visited.resize(N+1,false);
	while(!que.empty()){
		que.pop();
	}
	int level = 1;
	int num=1,nextnum = 0,cou = 0,ans=0;
	que.push(root);
	visited[root] = true;
	int a;
	int i;
	while(!que.empty()){
		if(level > L)
			break;
		cou ++;
		a = que.front();
		que.pop();
		for(i = 1; i <= N; i++){
			if(G[i][a] && !visited[i]){
				visited[i] = true;
				ans ++;
				que.push(i);
				nextnum ++;
			}
		}
		if(cou == num){
			num = nextnum;
			nextnum = 0;
			cou = 0;
			level ++;
		}
	}
	cout<<ans<<endl;
}

void print_G(){
	int i,j;
	for(i = 1;i <= N; i++)
		cout<<"\t"<<i;
	cout<<endl;
	for(i = 1;i <= N; i++)
		cout<<"-------\t";
	cout<<endl;
	for(i = 1; i <= N; i++){
		cout<<i<<"|";
		for(j=1; j <= N; j++)
			cout<<"\t"<<G[i][j];
		cout<<endl;
	}

}

int main(){
	init();
	//print_G();
	int k,root;
	cin>>k;
	for(int i = 0; i < k; i++){
		cin>>root;
		bfs(root);
	}
	system("pause");
}