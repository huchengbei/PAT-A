/*
* Problem: 1075. PAT Judge (25)
* Author: HQ
* Time: 2017-08-28 21:55
* State: Done
* Memo:
*/
#include "iostream"
#include "algorithm"
#include "vector"
using namespace std;

int N,K,M;
int fullMark[6];

struct node{
	int id;
	int score[6];
	int numOfFull;
	bool isShown;
};

vector<struct node> users;

bool cmp(const struct node a,const struct node b){
	if(a.score[0] != b.score[0])
		return a.score[0] > b.score[0];
	if(a.numOfFull != b.numOfFull)
		return a.numOfFull > b.numOfFull;
	return a.id < b.id;
}

void init(){
	cin>>N>>K>>M;
	int i;
	for(i = 1; i <= K; i++)
		cin>>fullMark[i];
	struct node t = {0,{0,-1,-1,-1,-1,-1},0,false};
	users.resize(N + 1,t);
}
void submit(){
	int i;
	int id,proId,score;
	for(i = 0; i < M; i++){
		cin>>id>>proId>>score;
		if(score != -1)
			users[id].isShown = true;
		score = max(score,0);
		users[id].score[proId] = max(score,users[id].score[proId]);
	}
}

void cal(){
	int i,j;
	for(i = 0;i <= N; i ++){
		users[i].id = i;
		for(j = 1;j <= K; j++){
			if(users[i].score[j] == fullMark[j])
				users[i].numOfFull ++;
			if(users[i].score[j] > -1)
				users[i].score[0] += users[i].score[j];
		}
	}
}

void test(){
	int i;
	for(i = 0; i <= N; i++){
		cout<<users[i].id<<" "<<users[i].score[0]<<endl;
	}
}

void print_ans(){
	int i,j;
	int rank;
	for(i = 1; i <= N; i++){
		if(users[i].isShown){
			if( i == 1 || users[i].score[0] != users[i - 1].score[0])
				rank = i;
			printf("%d %05d %d",rank,users[i].id,users[i].score[0]);
			for(j = 1; j <= K; j++)
				if (users[i].score[j] > -1){
					printf(" %d",users[i].score[j]);
				}else
					printf(" -");
		cout<<endl;
		}
	}
}

int main(){
	//freopen("test.out","w",stdout);
	init();
	submit();
	cal();
	sort(users.begin() + 1,users.end(),cmp);
	print_ans();
	//test();
	system("pause");
}