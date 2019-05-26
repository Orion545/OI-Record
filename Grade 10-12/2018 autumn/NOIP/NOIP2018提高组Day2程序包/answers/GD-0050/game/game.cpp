#include<cstdio>
#include<iostream>
using namespace std;
const int mo=1e9+7;
int n,m;
long long ans;
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d%d",&n,&m);
	int i,j;ans=1;
	for (i=2;i<=n;++i)
		for (j=1;j<m;++j)
			(ans*=3)%=mo;
	(ans*=4)%=mo;
	printf("%lld\n",ans);
}

