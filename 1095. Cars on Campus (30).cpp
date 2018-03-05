/*
* Problem: 1095. Cars on Campus (30)
* Author: HQ
* Time: 2017-09-07 23:08
* State: Done
* Memo:
*/
#include "iostream"
#include "algorithm"
#include "vector"
#include "string"
#include "map"
using namespace std;

struct node{
	string car;
	int time;
	string status;
};

bool cmp(struct node a,struct node b){
	return a.time < b.time;
}
bool cmpWithCarNum(struct node a,struct node b){
	if(a.car != b.car)
		return a.car < b.car;
	return a.time < b.time;
}

int N,K;
int maxTime = 0;
map<string,int> parkInTime;
map<string,bool> parkStatus;
vector<struct node> records;
vector<struct node> realRecords;
map<string,int> parkTime;

void init(){
	scanf("%d %d",&N,&K);
	int i;
	string car,status;
	int h,m,s;
	char c1[10];
	char c2[10];
	for(i = 0; i < N; i ++){
		scanf("%s %d:%d:%d %s",c1,&h,&m,&s,c2);
		car = string(c1);
		status = string(c2);
		struct node temp;
		temp.car = car;
		temp.time = h * 3600 + m * 60 + s;
		temp.status = status;
		records.push_back(temp);
	}
}

void cal(){
	parkStatus.clear();
	int i,j;
	int h,m,s,time;
	char c;
	int carNum = 0;
	for(i = 0,j = 0; i < K; i++){
		scanf("%d:%d:%d",&h,&m,&s);
		time = h * 3600 + m * 60 + s;
		while(j < realRecords.size() && realRecords[j].time <= time){
			if(realRecords[j].status == "in"){
				parkStatus[realRecords[j].car] = true;
				parkInTime[realRecords[j].car] = realRecords[j].time;
				carNum ++;
			}else if(parkStatus[realRecords[j].car]){
				parkStatus[realRecords[j].car] = false;
				parkTime[realRecords[j].car] += realRecords[j].time - parkInTime[realRecords[j].car];
				maxTime = max(maxTime,parkTime[realRecords[j].car]);
				carNum --;
			}
			j ++;
		}
		printf("%d\n",carNum);
	}
	while(j < realRecords.size()){
		if(realRecords[j].status == "in"){
			parkStatus[realRecords[j].car] = true;
			parkInTime[realRecords[j].car] = realRecords[j].time;
		}else if(parkStatus[realRecords[j].car]){
			parkStatus[realRecords[j].car] = false;
			parkTime[realRecords[j].car] += realRecords[j].time - parkInTime[realRecords[j].car];
			maxTime = max(maxTime,parkTime[realRecords[j].car]);
		}
		j ++;
	}
}

void fil(){
	for (int i = 0; i < records.size()-1; i++){
		if(records[i].car != records[i+1].car){
			continue;
		}
		if(records[i].status == "in" && records[i+1].status == "out"){
			realRecords.push_back(records[i ++]);
			realRecords.push_back(records[i]);
		}
		continue;
	}
}

int main(){
	init();
	sort(records.begin(),records.end(),cmpWithCarNum);
	fil();
	sort(realRecords.begin(),realRecords.end(),cmp);
	cal();
	for(auto it = parkTime.begin();it != parkTime.end();it++){
		if(maxTime == it->second)
			printf("%s ",it->first.c_str());
	}
	printf("%02d:%02d:%02d\n",maxTime/3600,maxTime%3600/60,maxTime%60);
	system("pause");
	
}