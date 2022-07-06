#include<iostream>
using namespace std;
int main(){
	int n,m;
	cin>>n>>m;
	while(n and m){
		cout<<(n*m%2?0:n*m/2)<<'\n';
		cin>>n>>m;
	}
}