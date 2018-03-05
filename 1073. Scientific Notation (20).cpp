/*
* Problem: 1073. Scientific Notation (20)
* Author: HQ
* Time: 2017-08-25 00:34
* State: Done
* Memo:
*/
#include "iostream"
#include "string"

using namespace std;

int main(){
	string s;
	int pose;
	cin>>s;
	if (s[0] == '-'){
		cout<<'-';
	}
	int l = s.length();
	int e = s.find('E');
	pose = stoi(string(s,e + 1,l));
	if(pose < 0){
		cout<<"0.";
		for(int i=1;i<= -pose - 1;i++)
			cout<<0;
		for(int i = 1;i < e; i++)
			if(s[i] !=  '.')
				cout<<s[i];
		cout<<endl;
	}else{
		int point = pose + 2;
		int len = max(e-2,point-1);
		//cout<<len<<endl;
		for(int i = 1; i <= len; i++){
			if(i<e && s[i] == '.'){
				point ++;
				len ++;
				continue;
			}
			if(i == point)
				cout<<'.';
			if(i < e)
				cout<<s[i];
			else
				cout<<0;
		}
		cout<<endl;
	}
	system("pause");
}