#include<iostream>
using namespace std;
int row[19],col[19],pal[19];
int a[10][10],st[1512],ans=-1;
constexpr int loc[][9]{
	{6,6,6,6,6,6,6,6,6},
	{6,7,7,7,7,7,7,7,6},
	{6,7,8,8,8,8,8,7,6},
	{6,7,8,9,9,9,8,7,6},
	{6,7,8,9,10,9,8,7,6},
	{6,7,8,9,9,9,8,7,6},
	{6,7,8,8,8,8,8,7,6},
	{6,7,7,7,7,7,7,7,6},
	{6,6,6,6,6,6,6,6,6}
};
void print(){
	int sum = 0;
	for(int i=0;i<9;i++){
		for(int j=0;j<9;j++){
			sum+=a[i][j]*loc[i][j];
		}
	}
	ans = max(ans,sum);
}
void init(){
	for(int i=0;i<=8;i++){
		row[i]=col[i]=pal[i]=(1>>9-1);
	}
	for(int i=0;i<512;i++){
		int j=i;
		while(j){
			st[i]+=j&1;
			j>>=1;
		}
	}
}
int find(int i,int j){
	return row[i] bitand col[j] bitand pal[i/3*3+j/3];
}
void dfs(){
	int cnt=10;
	int x,y;
	for(int i=0;i<9;i++){
		for(int j=0;j<9;j++){
			if(a[i][j])continue;
			int num=st[find(i,j)];
			if(num<cnt){
				cnt=num,x=i,y=j;
			}
		}
	}
	if(cnt==10){
		print();
		return;
	}
	int num=find(x,y);
	for(int i=0;i<9;i++){
		int f=(1<<i);
		if(num&f){
			a[x][y]=i+1;
			row[x]-=f,col[y]-=f,pal[x/3*3+y/3]-=f;
			dfs();
			row[x]+=f,col[y]+=f,pal[x/3*3+y/3]+=f;
			a[x][y]=0;
		}
	}
}
int main(){
	init();
	for(int i=0;i<9;i++){
		for(int j=0,x;j<9;j++){
			cin>>x;
			a[i][j]=x;
			if(x==0)continue;
			int num=(1<<(x-1));
			row[i]-=num,col[j]-=num,pal[i/3*3+j/3]-=num;
		}
	}
	dfs();
	cout<<ans<<endl;
}