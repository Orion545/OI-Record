#include <iostream>
#include <cstdio>
using namespace std;
const int p=1e9+7;
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	int i,j,k;
	int n,m;
	long long ans=1;
	cin>>n>>m;
	for(i=1;i<m;i++){
		ans=ans*3%p;
	}
	ans=ans*4%p;
	cout<<ans<<endl;
	return 0;
}
