/*
* Problem: 1087. All Roads Lead to Rome (30)
* Author: HQ
* Time: 2017-09-01 22:14
* State: Done
* Memo:
*/
#include "iostream"
#include "vector"
#include "map"
#include "string"
using namespace std;

int N,K;
string startCity;
map<string,int> city2id;
map<int,string> id2city;
vector<int> happiness;
int G[200 + 5][200 + 5];
vector<int> routes;
vector<bool> visited;
int numOfRoutes,cost,happ,numOfCity;
int tempCost = 0,tempHapp = 0,tempNumOfCity = 1;
vector<int> tempRoutes;


void init(){
	cin>>N>>K>>startCity;
	happiness.resize(N);
	routes.resize(N);
	visited.resize(N,false);
	tempRoutes.resize(N);
	numOfCity = cost = happ = numOfCity = 0;
	int i;
	city2id[startCity] = 0;
	id2city[0] = startCity;
	string city;
	int h;
	for(i = 1; i < N; i++){
		cin>>city>>h;
		city2id[city] = i;
		id2city[i] = city;
		happiness[i] = h;
	}
	string city2;
	for(i = 0; i < K; i++){
		cin>>city>>city2>>h;
		cost += h;
		G[city2id[city]][city2id[city2]] = h;
		G[city2id[city2]][city2id[city]] = h;
	}
}

void dfs(int city){
	if(city == city2id[string("ROM")]){
		if(tempCost<cost){
			numOfRoutes = 1;
			happ = tempHapp;
			cost = tempCost;
			numOfCity = tempNumOfCity;
			for(int i = 0; i<= numOfCity; i++){
				routes[i] = tempRoutes[i];
			}
		}else if(tempCost == cost){
			numOfRoutes ++;
			if(tempHapp > happ){
				happ = tempHapp;
				numOfCity = tempNumOfCity;
				for(int i = 0; i<= numOfCity; i++){
					routes[i] = tempRoutes[i];
				}
			}else if(tempHapp == happ && tempNumOfCity < numOfCity){
				numOfCity = tempNumOfCity;
				for(int i = 0; i<= numOfCity; i++){
					routes[i] = tempRoutes[i];
				}
			}

		}
		return;
	}
	for(int i = 1; i < N; i++){
		if(!visited[i] && G[city][i]){
			tempCost += G[city][i];
			tempHapp += happiness[i];
			tempNumOfCity ++;
			tempRoutes[tempNumOfCity] = i;
			visited[i] = true;
			dfs(i);
			visited[i] = false;
			tempCost -= G[city][i];
			tempHapp -= happiness[i];
			tempNumOfCity --;
		}
	}
}

void print_G(){
	int i,j;
	for(i = 0;i < N; i++)
		cout<<"\t"<<i;
	cout<<endl;
	for(i = 0;i < N; i++)
		cout<<"-------\t";
	cout<<endl;
	for(i = 0; i < N; i++){
		cout<<i<<"|";
		for(j=0; j < N; j++)
			cout<<"\t"<<G[i][j];
		cout<<endl;
	}

}

int main(){
	init();
	print_G();
	tempNumOfCity = 0;
	tempRoutes[0] = 0;
	visited[0] = true;
	dfs(0);
	printf("%d %d %d %d\n",numOfRoutes,cost,happ,happ/numOfCity);
	for(int i = 0; i < numOfCity; i++)
		cout<<id2city[routes[i]]<<"->";
	cout<<"ROM"<<endl;
	system("pause");
}