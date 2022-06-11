#include<iostream>
#include<string>
using namespace std;
string t,maxn;
int main(){
	freopen("test/str.in","r",stdin);
	cin>>t,maxn=t[0];
	size_t sz=t.size(),sz2=1,id=0;
	for(int i=0;i<sz;i++){
		cout<<maxn[id%sz2]<<t[i]<<'\n';
		if(maxn[id%sz2]!=t[i])
			maxn=t.substr(0,i+1),sz2=i+1,id=i%sz2;
		id++;
	}
	cout<<(sz%sz2?sz:sz2);
}