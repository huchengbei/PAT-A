/*
* Problem: 1089. Insert or Merge (25)
* Author: HQ
* Time: 2017-09-02 23:33
* State: Done
* Memo:
*/
#include "iostream"
#include "algorithm"
using namespace std;

int initial[100 + 5];
int sorted[100 + 5];
int N,i,j;

void print_ans(int f){
	if(f)
		cout<<"Insertion Sort"<<endl;
	else
		cout<<"Merge Sort"<<endl;
	cout<<sorted[0];
	for(int i = 1; i < N; i++)
		cout<<" "<<sorted[i];
}

bool isKisOk(int k){
	int i,j;
	for(i = 0; i < N/k; i++){
		for(j = i * k + 1; j < N && j < i * k + k; j++){
			if(sorted[j] < sorted[j -1])
				return false;
		}
	}
	return true;
}

void sortMerge(){
	int k = 1;
	while(isKisOk(k)){
		k *= 2;
	}
	for(i = 0; i <= N/k; i++){
		sort(sorted + i * k, sorted + min(i*k+k,N));
	}
}

int main(){
	bool flag; //trueÊÇinsert
	cin>>N;
	for(i = 0; i < N; i++){
		cin >> initial[i];
	}
	for(i = 0; i < N; i++){
		cin >> sorted[i];
	}
	for(i = 1; i < N; i++){
		if(sorted[i] < sorted[i - 1])
			break;
	}
	flag = true;
	for(j = i; j < N; j++){
		if(initial[j] != sorted[j]){
			flag = false;
			break;
		}
	}
	if(flag){
		sort(sorted,sorted+i+1);
		print_ans(flag);
	}else{
		sortMerge();
		print_ans(flag);
	}
	system("pause");
}