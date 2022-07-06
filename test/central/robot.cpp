#include<iostream>
#include<vector>
using namespace std;
int n,t,id;
char c;
size_t sz;
vector<int> lst;
int main(){
	freopen("test/robot.in","r",stdin);
	auto bg=lst.cbegin();
	cin.tie(0);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>c;
		if(c=='I'){
			cin>>t;
			if(id==sz)lst.push_back(t);
			else lst.insert(bg+id,t);
			id++,sz++;
		}
		if(c=='D' and id){
			lst.erase(begin(lst)+id-1);
			id--,sz--;
		}
		if(c=='L' and id)id--;
		if(c=='R' and id<sz)id++;
		if(c=='Q'){
			cin>>t;
			size_t tmp=0,maxn=0;
			for(int j=0;j<t;j++){
				tmp+=lst[j];
				maxn=max(maxn,tmp);
			}
			cout<<maxn<<'\n';
		}
	}
}