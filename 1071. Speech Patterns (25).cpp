/*
* Problem: 1071. Speech Patterns (25)
* Author: HQ
* Time: 2017-08-23 00:40
* State: Done
* Memo:
*/
#include "iostream"
#include "algorithm"
#include "map"
#include "vector"
#include "string"

using namespace std;

char isAlpha(char c){
	if(c<='9' && c >= '0')
		return c;
	if(c<='z' && c >= 'a')
		return c;
	if(c<='Z' && c >= 'A')
		return c-('A' - 'a');
	return 0;
} 

bool comp(const pair<string,int> &a,const pair<string,int> &b){
	return a.second>b.second;
}

int main(){
	map<string,int> mm;
	map<string,int>::iterator it;
	char c;
	string s = "";
	while(scanf("%c",&c)){
		if(c=='\n')
			break;
		c = isAlpha(c);
		if (c)
			s += c;
		else{
			if(s.size()){
				if(mm.count(s)){
					mm[s] ++;
				}else{
					mm[s] = 1;
				}
			}
			s = "";
		}
	}
	// 处理如果最后是可行字符的情况
	if(s.size()){
		if(mm.count(s)){
			mm[s] ++;
		}else{
			mm[s] = 1;
		}
	}
	vector<pair<string,int>> v(mm.begin(),mm.end());
	sort(v.begin(),v.end(),comp);
	cout<<v[0].first<<" "<<v[0].second<<endl;
	//system("pause");
}