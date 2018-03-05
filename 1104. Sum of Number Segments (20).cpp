/*
* Problem: 1104. Sum of Number Segments (20)
* Author: HQ
* Time: 2017-09-11 23:28
* State: Done
* Memo:
*/
#include "iostream"
using namespace std;

int main(){
	int n;
	double x,sum = 0;
	cin>>n;
	for(int i = 1; i <= n; i++){
		cin>>x;
		sum += x * (n + 1 - i) * i;
	}
	printf("%.2lf\n",sum);
	system("pause");
}