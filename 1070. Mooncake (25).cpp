/*
* Problem: 1070. Mooncake (25)
* Author: HQ
* Time: 2017-08-22 22:59
* State: Done
* Memo:
*/
#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

struct mooncake{
	double tons;
	double price;
	double aver;
};

bool comp(const mooncake &a,const mooncake &b){
	return a.aver>b.aver;
}

int main(){
	int n,d;
	cin>>n>>d;
	vector<mooncake> mc;
	//mc.resize(n);
	int i;
	for (i = 0; i < n; i ++){
		mooncake x;
		cin>>x.tons;
		mc.push_back(x);
	}
	for (i = 0; i < n; i ++){
		cin>>mc[i].price;
		mc[i].aver = mc[i].price/mc[i].tons;
	}
	sort(mc.begin(),mc.end(),comp);
	i = 0;
	double profit = 0;
	while (d && i<n){
		if(d <= mc[i].tons){
			profit += d * mc[i].aver;
			d = 0;
		}else{
			d -= mc[i].tons;
			profit += mc[i].price;
			i ++;
		}
	}
	printf("%.2f",profit);
	//system("pause");
	return 0;
}