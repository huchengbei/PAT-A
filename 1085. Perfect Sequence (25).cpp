/*
* Problem: 1085. Perfect Sequence (25)
* Author: HQ
* Time: 2017-08-30 23:39
* State: Done
* Memo:
*/
#include "iostream"
#include "algorithm"

using namespace std;

int N;
long long P;
long long data[100000 + 5];
int ans = 0;
void init(){
	int i;
	cin>>N>>P;
	for(i = 0; i < N; i++)
		cin>>data[i];
}

void cal(){
	int i,j;
	long long k;
	for(i = 0, j = 0; i < N,j < N; i++,j++){
		k = data[i] * P;
		j = i + ans;
		while(j < N && data[j]<=k){
			ans = max(ans,j-i+1);
			j++;
		}
	}
}


int main(){
	init();
	sort(data,data + N);
	cal();
	cout<<ans<<endl;
	system("pause");
}