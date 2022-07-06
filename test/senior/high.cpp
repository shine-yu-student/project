#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int main(){
	long long a,b,c;
	cin>>a>>b>>c;
	a%=c,b%=c;
	cout<<a*b%c;
}