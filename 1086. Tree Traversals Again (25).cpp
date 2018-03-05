/*
* Problem: 1086. Tree Traversals Again (25)
* Author: HQ
* Time: 2017-08-31 23:04
* State: Done
* Memo:
*/
#include "iostream"
#include "string"
using namespace std;

struct node{
	int data;
	struct node *l;
	struct node *r;
};

typedef struct node * Tree;


int N;
Tree root;
bool first =true;

Tree buildTree(){
	static int cou = 0;
	cou ++;
	if (cou > 2*N)
		return NULL;
	string order;
	cin>>order;
	int t = order.find("sh");
	if(t > -1){
		Tree temp = (Tree)malloc(sizeof(struct node));
		int x;
		cin>>x;
		temp->data = x;
		temp->l = buildTree();
		temp->r = buildTree();
		return temp;
	}
	return NULL;
}

void init(){
	cin>>N;
	root = buildTree();
}

void postOrder(Tree r){
	if(r != NULL){
		postOrder(r->l);
		postOrder(r->r);
		if(first){
			cout<<r->data;
			first = false;
		}else
			cout<<" "<<r->data;
	}
	return;

}

int main(){
	init();
	postOrder(root);
	cout<<endl;
	system("pause");
}