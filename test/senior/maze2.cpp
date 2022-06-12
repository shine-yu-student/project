#include<iostream>
using namespace std;
typedef long long ll;
const int N=1e6+10;
ll a[N],j[N]={1},tree[N],n;
ll ans;
auto lowbit=[](int x){return x&-x;};
void update(int x,int y){
	while(x<=n){
		tree[x]+=y;
		x+=lowbit(x);
	}
}
ll query(int x){
	ll sum=0;
	while(x){
		sum+=tree[x];
		x-=lowbit(x);
	}
	return sum;
}
int main(){
	// freopen("test/cantor.in","r",stdin);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		j[i]=j[i-1]*i;
		update(i,1);
	}
	for(int i=1;i<=n;i++){
		ans+=query(a[i]-1)*j[n-i];
		update(a[i],-1);
	}
	cout<<ans+1;
}