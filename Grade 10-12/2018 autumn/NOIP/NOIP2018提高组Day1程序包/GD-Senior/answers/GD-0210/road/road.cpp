#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N=1e5+10;
ll n,ans,a[N],b[N];

int read()
{
	int ret=0;char c=getchar();
	while(!isdigit(c)) c=getchar();
	while(isdigit(c)) ret=ret*10+(c^48),c=getchar();
	return ret;
}

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	n=read();
	for(int i=1;i<=n;++i) 
	{
		a[i]=read(),b[i]=a[i]-a[i-1];
		if(b[i]>0) ans+=b[i];
	}
	printf("%lld\n",ans);
	
	return 0;
}
