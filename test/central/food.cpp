#include<iostream>
#include<queue>
#include<functional>
using namespace std;
int n,t;
char tmp;
priority_queue<int,vector<int>,greater<int>> q;
int main(){
	freopen("test/food.in","r",stdin);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>tmp;
		if(tmp=='i'){
			cin>>t;
			q.push(t);
		}else cout<<q.top()<<' ',q.pop();
	}
}