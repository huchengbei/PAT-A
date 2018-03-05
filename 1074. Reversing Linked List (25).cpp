/*
* Problem: 1074. Reversing Linked List (25)
* Author: HQ
* Time: 2017-08-26 00:12
* State: Done
* Memo:
*/
#include "iostream"

using namespace std;

int main(){
	int list[100005];
	int nextList[100005];
	int link[100005];
	int start;
	int n,k,sum=0;
	cin>>start>>n>>k;
	int add;
	int  data;
	int nextAdd;

	for (int i = 0; i < n; i++){
		cin>>add>>data>>nextAdd;
		list[add] = data;
		nextList[add] = nextAdd;
	}
	int i = 0;
	while(start!= -1){
		link[++sum] = start;
		start = nextList[start];
	}
	//cout<<sum<<endl;
	int next = k>sum?1:k;
	for(i = 1; i <= sum; i ++){
		printf("%05d %d ",link[next],list[link[next]]);
		if ((next - 1) / k < sum / k){
			next--;
			if(next % k == 0)
				next += 2 * k;
			if(next > sum){
				next -= k - 1;
			}
		}else
			next ++;
		if(next > sum)
			cout<<"-1"<<endl;
		else
			printf("%05d\n",link[next]);

	}
	system("pause");
}