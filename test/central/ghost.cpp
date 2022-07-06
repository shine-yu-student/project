#include<iostream>
#include<queue>
#include<utility>
using namespace std;
struct stu{
	pair<int,int> pos;
	int pro,life,step;
};
deque<stu> q;
short vis[810][810],vis2[810][810];
char t;
int n,m,ans;
constexpr int dx[]{0,1,0,-1},dy[]{1,0,-1,0};
int main(){
	freopen("test/ghost.in","r",stdin);
	int T;
	cin>>t;
	while(T--){
		ans=-1;
		while(!q.empty())q.pop_front();
		cin>>n>>m;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>t;
				if(t=='X')vis[i][j]=true;
				if(t=='Z')vis[i][j]=vis2[i][j]=true,q.push_front({{i,j},-1,1,-1});
				if(t=='M')vis[i][j]=true,q.push_back({{i,j},1,2,0});
				if(t=='G')vis[i][j]=true,q.push_back({{i,j},0,0,0});
			}
		}
		while(!q.empty()){
			auto tmp=q.front();
			q.pop_front();
			auto [x,y]=tmp.pos;
			if(tmp.pro==-1){
				if(tmp.life){
					for(int i=0;i<4;i++){
						int nx=x+dx[i],ny=y+dy[i];
						if(nx>0 and nx<=n and ny>0 and ny<=m and !vis2[nx][ny]){
							q.push_front({{nx,ny},-1,tmp.life-1,-1});
							vis[nx][ny]=vis2[nx][ny]=true;
						}
					}
				}else{
					for(int i=0;i<4;i++){
						int nx=x+dx[i],ny=y+dy[i];
						if(nx>0 and nx<=n and ny>0 and ny<=m and !vis2[nx][ny]){
							q.push_back({{nx,ny},-1,2,-1});
							vis[nx][ny]=vis2[nx][ny]=true;
						}
					}
				}
			}else{
				int opt=tmp.pro?2:3;
				if(tmp.life){
					for(int i=0;i<4;i++){
						int nx=x+dx[i],ny=y+dy[i];
						if(nx>0 and nx<=n and ny>0 and ny<=m and !(vis[nx][ny]==1) and !(vis[nx][ny]==opt)){
							if(vis[nx][ny]){ans=tmp.step+1;break;}
							q.push_front({{nx,ny},tmp.pro,tmp.life-1,tmp.step+1});
							vis[nx][ny]=opt;
						}
					}
				}else{
					for(int i=0;i<4;i++){
						int nx=x+dx[i],ny=y+dy[i];
						if(nx>0 and nx<=n and ny>0 and ny<=m and !(vis[nx][ny]==1) and !(vis[nx][ny]==opt)){
							if(vis[nx][ny]){ans=tmp.step+1;break;}
							q.push_back({{nx,ny},tmp.pro,tmp.pro?2:0,tmp.step+1});
							vis[nx][ny]=opt;
						}
					}
				}
			}
		}
		cout<<ans<<'\n';
	}
}