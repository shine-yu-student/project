#include<iostream>
#include<climits>
using namespace std;
int main(){
	freopen("test/car.in","r",stdin);
	int d,k,a,b,t,minn,cur=0;
	cin>>d>>k>>a>>b>>t;
	minn=d*b;
	for(int i=1;i<=d;i++){
		cur+=a;
		minn=min(minn,cur+(d-i)*b);
		if(i%k==0)cur+=t;
	}
	cout<<min(minn,cur);
}