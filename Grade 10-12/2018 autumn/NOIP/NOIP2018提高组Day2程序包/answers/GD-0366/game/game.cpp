#include <iostream>
#include <stdio.h>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

int n,m,mod,num;
long long ans;
long long a[15][1000005],b[10000005];

void Find(int k,int s)
{
	if (k>num)
	 {
	 	if (s!=0)
	 	 {
	 	 	if (s%2==0) ans=(ans+b[n*m-2*s])%mod;
	 	 	 else ans=(ans-b[n*m-2*s]+mod)%mod;
		 }
	 	return;
	 }
	Find(k+1,s+1);
	Find(k+1,s);
}

int main()
{freopen("game.in","r",stdin);
freopen("game.out","w",stdout);
	cin>>n>>m;
	b[1]=2;
	mod=1000000007;
	for (int i=2;i<=n*m;i++)
	 b[i]=(b[i-1]*2)%mod;
	ans=b[n*m];
	int r=min(n,m);
	for (int i=1;i<r;i++)
	 num+=i;
	Find(1,0);
	cout<<ans;
	return 0;
}
