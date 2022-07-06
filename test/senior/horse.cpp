#include<iostream>
#include<utility>
#include<queue>
using namespace std;
constexpr int dx[]{1,2,2,1,-1,-2,-2,-1},dy[]{2,1,-1,-2,-2,-1,1,2};
queue<pair<pair<int,int>,int>> q;
int n,m;
pair<int,int> s,e;
const int N=4e2+10;
bool vis[N][N];
char tmp;
int launch(){
	auto [sx,sy]=s;
	q.push({s,0});
	vis[sx][sy]=true;
	while(!q.empty()){
		auto tmp=q.front();
		q.pop();
		auto [pos,stp]=tmp;
		auto [x,y]=pos;
		for(int i=0;i<8;i++){
			int nx=x+dx[i],ny=y+dy[i];
			if(nx>0 and nx<=n and ny>0 and ny<=m and !vis[nx][ny]){
				vis[nx][ny]=true;
				if(e==make_pair(nx,ny))return stp+1;
				q.push({{nx,ny},stp+1});
			}
		}
	}
	return -1;
}
int main(){
	freopen("test/horse.in","r",stdin);
	cin>>m>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>tmp;
			if(tmp=='*')vis[i][j]=1;
			if(tmp=='K')s={i,j},vis[i][j]=1;
			if(tmp=='H')e={i,j};
		}
	}
	cout<<launch();
}