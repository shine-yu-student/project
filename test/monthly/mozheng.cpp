#include<iostream>
#include<string>
using namespace std;
string s;
int n,a,b,cnt;
int main(){
	cin>>n>>a>>b;
	for(int i=0;i<n;i++){
		cin>>s>>s;
		if(s[0]=='/'){
			if(s.substr(1)=="oh")cnt+=a;
			if(s.substr(1)=="hsh")cnt+=b;
		}
	}
	cout<<cnt;
}