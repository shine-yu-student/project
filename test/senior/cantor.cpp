#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int cnt=1;
int main(){
	freopen("test/cantor.in","r",stdin);
	int n;
	cin>>n;
	vector<int> a(n),b(n);
	for(int i=0;i<n;i++){
		cin>>b[i];
		a[i]=i+1;
	}
	while(a!=b){
		next_permutation(a.begin(),a.end()),cnt++;
	}
	cout<<cnt;
}