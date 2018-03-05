/*
* Problem: 1101. Quick Sort (25)
* Author: HQ
* Time: 2017-09-08 23:19
* State: Done
* Memo:
*/
#include "iostream"
#include "vector"
using namespace std;

int N;
long long data[100000 + 5];
long long minInR[100000 + 5];
vector<long long> ans;

void init(){
	cin>>N;
	int i;
	for(i = 0; i < N; i++){
		cin>>data[i];
	}
}

void cal(){
	int i;
	minInR[N -1] = 0x3FFFFFFF;
	for(i = N - 2; i >= 0; i--)
		minInR[i] = min(data[i + 1],minInR[i + 1]);
	long long maxNum = -1; // current max num ; the largest num before i
	for(i = 0; i < N; i++){
		if(data[i] > maxNum && data[i] < minInR[i]){
			ans.push_back(data[i]);
		}
		maxNum = max(maxNum,data[i]);
	}
}

void printAns(){
	int k =ans.size();
	cout<<k<<endl;
	if(k){
		cout<<ans[0];
		for(int i = 1; i< k; i++){
			cout<<" "<<ans[i];
		}
	}
	cout<<endl;
}

int main(){
	//cout<<0x3<<" "<<0x3F<<" "<<0x3FF<<" "<<0x3FFF<<endl;
	init();
	cal();
	printAns();
	system("pause");
}