/*
* Problem: 1088. Rational Arithmetic (20)
* Author: HQ
* Time: 2017-09-02 22:47
* State: Done
* Memo:
*/
#include "iostream"
#include "string"
using namespace std;

long long a,b,c,d;

long long int gcd(long long int m, long long int n) {
	return n == 0 ? m : gcd(n, m % n);
}

void num2string(long long m,long long n){
	bool sign = true;
	if(n == 0){
		cout<<"Inf";
		return;
	}
	if(m == 0){
		cout<<"0";
		return;
	}
	if(m<0){
		sign = !sign;
		m = -m;
	}
	if(n < 0){
		sign = !sign;
		n = -n;
	}
	long long g = gcd(m,n);
	m = m/g;
	n = n/g;
	if(!sign)
		cout<<"(-";
	long long x = m/n,y=m%n;
	if(x == 0)
		cout<<y<<"/"<<n;
	else if(y == 0)
		cout<<x;
	else
		cout<<x<<" "<<y<<"/"<<n;
	
	if(!sign)
		cout<<")";
}

void add(){
	long long e = a * d + b * c,f = b * d;
	num2string(a,b);
	cout<<" + ";
	num2string(c,d);
	cout<<" = ";
	num2string(e,f);
	cout<<endl;
}

void min(){
	long long e = a * d - b * c,f = b * d;
	num2string(a,b);
	cout<<" - ";
	num2string(c,d);
	cout<<" = ";
	num2string(e,f);
	cout<<endl;
}

void mul(){
	long long e =  a * c,f = b * d;
	num2string(a,b);
	cout<<" * ";
	num2string(c,d);
	cout<<" = ";
	num2string(e,f);
	cout<<endl;
}

void div(){
	long long e = a * d,f = b * c;
	num2string(a,b);
	cout<<" / ";
	num2string(c,d);
	cout<<" = ";
	num2string(e,f);
	cout<<endl;
}
int main(){
	char ch;
	cin>>a;
	scanf("%c",&ch);
	cin>>b>>c;
	scanf("%c",&ch);
	cin>>d;
	add();
	min();
	mul();
	div();
	system("pause");
}