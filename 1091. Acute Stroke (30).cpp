/*
* Problem: 1091. Acute Stroke (30)
* Author: HQ
* Time: 2017-09-04 00:24
* State: Done
* Memo:
*/
#include "iostream"
#include "queue"
using namespace std;

struct node{
	int l;
	int m;
	int n;
};

int G[65][1300][130];
int M,N,L,T;
int ans = 0;
int X[6] = {1, 0, 0, -1, 0, 0};
int Y[6] = {0, 1, 0, 0, -1, 0};
int Z[6] = {0, 0, 1, 0, 0, -1};

bool judge(int x, int y, int z) {
	if(x < 0 || x >= L || y < 0 || y >= M || z < 0 || z >= N) return false;
	if(G[x][y][z] == 0) return false;
	return true;
}

void init(){
	cin>>M>>N>>L>>T;
	int i,j,k;
	for(i = 0; i < L; i++){
		for(j = 0; j < M; j++){
			for(k = 0; k < N; k++)
				scanf("%d",&G[i][j][k]);
		}
	}
}

int bfs(int x, int y, int z){
	queue<struct node> que;
	int cnt = 0;
	struct node temp;
	temp.l = x;
	temp.m = y;
	temp.n = z;
	G[x][y][z] = 0;
	que.push(temp);
	while(!que.empty()){
		struct node top = que.front();
		que.pop();
		cnt ++;
		for(int i = 0; i < 6; i++) {
			int tx = top.l + X[i];
			int ty = top.m + Y[i];
			int tz = top.n + Z[i];
			if(judge(tx, ty, tz)) {
				G[tx][ty][tz] = 0;
				temp.l = tx, temp.m = ty, temp.n = tz;
				que.push(temp);
			}
		}
	}
	return (cnt>=T)?cnt:0;
}

int main(){
	init();
	int i,j,k;
	for(i = 0; i < L; i++){
		for(j = 0; j < M; j++){
			for(k = 0; k < N; k++)
				if(G[i][j][k])
					ans += bfs(i,j,k);
		}
	}
	cout<<ans<<endl;
	system("pause");
}