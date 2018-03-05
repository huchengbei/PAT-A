/*
* Problem: 1107. Social Clusters (30)
* Author: HQ
* Time: 2017-09-13 23:15
* State: Done
* Memo:
*/
#include "iostream"
#include "vector"
#include "algorithm"
using namespace std;

int father[1001] = {0};
int pre[1001] = {0}; // pre[i] means the last person who has a hobby i
int N;
vector<int> ans;

int getF(int x){
	int a = x,t;
	while(x != father[x]){
		x = father[x];
	}
	while(a != father[a]){
		t = a;
		a = father[a];
		father[t] = x;
	}
	return x;
}

void Union(int a,int b){
	int fa = getF(a);
	int fb = getF(b);
	father[fb] = fa;
}

void init(){
	scanf("%d",&N);
	int i,k,j,x;
	ans.resize(N + 1,0);
	for(i = 0; i < 1001; i++)
		father[i] = i;
	for(i = 1; i <= N; i++){
		scanf("%d: ",&k);
		for(j = 0; j < k; j ++){
			scanf("%d",&x);
			if(pre[x] == 0)
				pre[x] = i;
			Union(i,getF(pre[x]));
		}
	}
}

void cal(){
	int  i,f;
	for(i = 1; i <= N; i++){
		f = getF(i);
		if( f == i)
			ans[0]++;
		ans[getF(i)] ++;
	}
	sort(ans.begin() + 1,ans.end());
}

int main(){
	init();
	cal();
	printf("%d\n",ans[0]);
	if(ans[0]){
		printf("%d",ans[ans.size() - 1]);
		for(int i = ans.size() - 2,k = 1; k < ans[0]; i--,k++)
			printf(" %d",ans[i]);
		printf("\n");
	}
	system("pause");;
}