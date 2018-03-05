/*
* Problem: 1108. Finding Average (20)
* Author: HQ
* Time: 2017-09-14 00:04
* State: Done
* Memo:
*/
#include "iostream"
#include "string"
#include "cmath"
using namespace std;

double s2d(string s){
	int i,l = s.length();
	int flag = 0; // 0: ÕýÊý
	if(s[0] == '-')
		flag = 1;
	double num = 0;
	int dot = 0;
	for(i = flag; i < l; i++){
		if(!((s[i] >= '0' && s[i] <= '9') || s[i] == '.'))
			return 9999;
		if(s[i] == '.'){
			if(!dot)
				dot ++;
			else
				return 9999;
		}else{
			if(dot)
				dot ++;
			num *= 10;
			num += s[i] - '0';
		}
	}
	if(dot > 3)
		return 9999;
	if(flag)
		return (-1) * num/pow(10.0,dot?(dot -1):0);
	return num/pow(10.0,dot?(dot -1):0);
}

int main(){
	string s ;
	int n,i,cnt = 0;
	double sum = 0,x;
	cin>>n;
	for(i = 0; i < n; i ++){
		cin>>s;
		x = s2d(s);
		if(x >= -1000 && x <= 1000){
			cnt ++;
			sum += x;
		}else
			cout<<"ERROR: "<<s<<" is not a legal number"<<endl;
	}
	if(cnt == 1)
		printf("The average of %d number is %.2f\n",cnt,sum/cnt);
	else if(cnt)
		printf("The average of %d numbers is %.2f\n",cnt,sum/cnt);
	else
		printf("The average of 0 numbers is Undefined\n");
	system("pause");
}