/*
* Problem: 1102. Invert a Binary Tree (25)
* Author: HQ
* Time: 2017-09-09 22:02
* State: Done
* Memo:
*/
#include "iostream"
#include "queue"
using namespace std;

int N;
int l[10];
int r[10];
int root;
bool isChild[10];

void init(){
	cin>>N;
	char c1,c2;
	char c;
	for(int i = 0; i < N; i++){
		cin>>c1>>c2;
		if(c1 >= '0' && c1 <= '9'){
			l[i] = c1 - '0';
			isChild[c1 - '0'] = true;
		}else
			l[i] = -1;
		if(c2 >= '0' && c2 <= '9'){
			r[i] = c2 - '0';
			isChild[c2 - '0'] = true;
		}else
			r[i] = -1;
	}
	for(int i = 0; i < N; i++){
		if(!isChild[i]){
			root = i;
			break;
		}
	}
}

void levelOrder(){
	queue<int> que;
	que.push(root);
	bool first = true;
	int x;
	while(!que.empty()){
		x = que.front();
		que.pop();
		if(first){
			cout<<x;
			first = false;
		}else{
			cout<<" "<<x;
		}
		if(r[x] != -1)
			que.push(r[x]);
		if(l[x] != -1)
			que.push(l[x]);
	}
	cout<<endl;
}

void inOrder(int ro){
	static bool first = true;
	if(r[ro] != -1)
		inOrder(r[ro]);
	if(first){
		cout<<ro;
		first = false;
	}else{
		cout<<" "<<ro;
	}
	if(l[ro] != -1)
		inOrder(l[ro]);
}

int main(){
	init();
	levelOrder();
	inOrder(root);
	cout<<endl;
	system("pause");
}