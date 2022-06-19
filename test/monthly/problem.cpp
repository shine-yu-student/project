#include<iostream>
using namespace std;
typedef unsigned int uint;
int n;
uint seed;
int a[10001],fa[10001];
inline uint get_next(uint &seed){
	seed ^= seed << 13;
	seed ^= seed >> 17;
	seed ^= seed << 5;
	return seed;
}

int main(){
	cin>>n>>seed;
	for (register int i = 1; i <= n; i++){
		a[i] = get_next(seed);
	}
	for (register int i = 2; i <= n; i++){
		fa[i] = get_next(seed) % (i - 1) + 1;
	}
	
	return 0;
}