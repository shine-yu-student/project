#include<iostream>
#include<string>
#include<cstdio>
using namespace std;
struct tim{
	int x=0,y=0,z=0;
	tim operator-(const tim &t)const{
		int x1=(x-t.x<0?24-(x-t.x):x-t.x),y1=y-t.y,z1=z-t.z;
		if(z1<0)z1+=60,y1--;
		if(y1<0)y1+=60,x1--;
		if(x1<0)x1+=24;
		return tim{x1,y1,z1};
	}
	tim operator+(const tim &t)const{
		int x1=x+t.x,y1=y+t.y,z1=z+t.z;
		if(z1>60)z1-=60,y1++;
		if(y1>60)y1-=60,x1++;
		if(x1>24)x1-=24;
		return tim{x1,y1,z1};
	}
	friend ostream& operator<<(ostream& out,const tim& t){
		out.width(2);
		out.fill('0');
		out<<t.x<<':';
		out.width(2);
		out.fill('0');
		out<<t.y<<':';
		out.width(2);
		out.fill('0');
		out<<t.z;
		return out;
	}
	bool operator==(const tim &t)const{
		return x==t.x and y==t.y and z==t.z;
	}
};
tim get_t(){
	string s;
	tim ret;
	cin>>s;
	if(s=="end")return {-1,-1,-1};
	ret.x=(s[0]-'0')*10+s[1]-'0';
	ret.y=(s[3]-'0')*10+s[4]-'0';
	ret.z=(s[6]-'0')*10+s[7]-'0';
	return ret;
}
int main(){
	tim s;
	while(1){
		tim a=get_t();
		if(a==tim{-1,-1,-1})break;
		tim b=get_t()-a;
		s=s+b;
	}
	cout<<s;
}