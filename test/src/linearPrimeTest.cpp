#include "../../lib/diy_search.hpp"
using namespace std;
using namespace diy;
int main(){
	// freopen("test/linearPrimeTest.in","r",stdin);
	// freopen("test/linearPrimeTest.out","w",stdout);
	int n,m,t;
	cin>>n>>m;
	auto lst=linearPrimeSearch(n);
	cin.tie(0),cout.tie(0);
	for(int i=0;i<m;i++){
		cin>>t;
		cout<<lst[t-1]<<'\n';
	}
}