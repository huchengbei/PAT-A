/*
* Problem: 1072. Gas Station (30)
* Author: HQ
* Time: 2017-08-24 22:31
* State: Done
* Memo:
*/
#include "iostream"
#include "string"

using namespace std;
int N,M,K,D;
int map[1000 + 20][1000 + 20] = {-1};
int dist[1000 + 20];
int visited[1000 + 20];
int res = -1,cost1,min_dist = 0;

int getId(string s){
	if (s.find('G')!=-1){
		return N + stoi(string(s,1)) - 1;
	}
	return stoi(s) - 1;
}

void init(){
	cin>>N>>M>>K>>D;
	cost1 = N * (D + 1);
	int i,j;
	string s,e;
	int start,end;
	int dis;
	for (i = 0; i< M + N; i++){
		for (j = 0; j< M + N; j++){
			map[i][j] = D + 1;
		}
		map[i][i] = 0;
		dist[i] = D + 1;
	}
	for (i = 0; i < K; i++){
		cin>>s>>e>>dis;
		start = getId(s);
		end = getId(e);
		map[start][end] = map[end][start] = dis;
	}
}

void printMap(){
	int i,j;
	printf("0");
	for(i=0;i<M+N;i++){
		printf("\t%d",i);
	}
	cout<<endl;
	for (i = 0; i< M + N; i++){
		printf("%d",i);
		for (j = 0; j< M + N; j++){
			cout<<"\t"<<map[i][j];
		}
		cout<<endl;
	}
}

void dijk(int x){
	int i,j;
	for (i = 0; i < M + N; i ++){
		dist[i] = D + 1;
		visited[i] = 0;
	}
	visited[x] = 1;
	dist[x] = 0;
	for (int count = 0; count < M + N - 1; count++) {
		int k = x,min_d = D + 1;
		for (j = 0; j < M + N; j ++){
			if(!visited[j] && min_d > dist[j]){
				k = j;
				min_d = dist[j];
			}
		}
		visited[k] = 1;
		for (int v = 0; v < M + N; v++)
			if (!visited[v] && map[k][v] && dist[k] != D + 1 && dist[k] + map[k][v] < dist[v])
				dist[v] = dist[k] + map[k][v];
	}
	int  tcost1 = 0,tmin_dist = D+1;
	for(i = 0; i < N; i ++){
		if(dist[i] > D)
			return ;
		else{
			tcost1 += dist[i];
			tmin_dist = min(tmin_dist,dist[i]);
		}
	}
	if(tmin_dist>min_dist || (tmin_dist==min_dist && tcost1<cost1)){
		res = x;
		cost1 = tcost1;
		min_dist = tmin_dist;
	}
	return ;
}


int main(){
	init();
	//printMap();
	for(int i = N; i < M + N;i++){
		dijk(i);
	}
	if(res != -1){
		cout<<"G"<<res-N+1<<endl;
		printf("%.1f %.1f\n",(double)min_dist,((double)cost1)/N);
	}else
		printf("No Solution\n");
	//system("pause");
}