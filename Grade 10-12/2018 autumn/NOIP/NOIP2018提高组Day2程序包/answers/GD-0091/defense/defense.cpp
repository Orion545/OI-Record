#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
int n,m;
int cost[2005];
long long f[200005],g[200005];
char s[5];
int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	scanf("%d%d%s\n",&n,&m,s);
	for(int i=1;i<=n;i++) scanf("%d",&cost[i]);
	f[1]=cost[1];
	for(int i=1;i<n;i++) 
	{
		int x,y;
		scanf("%d%d",&x,&y);
	}
	for(int i=2;i<=n;i++) f[i]=min(f[i-1],f[i-2])+cost[i];
	while(m--)
	{
		int a,x,b,y;
		scanf("%d%d%d%d",&a,&x,&b,&y);
		if(a>b)
		{
			swap(a,b);
			swap(x,y);	
		}
		g[a]=f[a];
		if(x==1)
		{
			g[a+1]=f[a]+cost[a+1];
			for(int i=a+2;i<=b;i++) g[i]=min(g[i-1],g[i-2])+cost[i];
		} 
		else
		{
			g[a+1]=f[a-1]+cost[a+1];
			g[a+2]=g[a+1]+cost[a+2];
			for(int i=a+3;i<=b;i++) g[i]=min(g[i-1],g[i-2])+cost[i];
		}
		if(y==1)
		{
			g[b+1]=g[b]+cost[b+1];
			for(int i=b+2;i<=n;i++) g[i]=min(g[i-1],g[i-2])+cost[i];
		}
		else
		{
			g[b+1]=g[b-1]+cost[b+1];
			g[b+2]=g[b+1]+cost[b+2];
			for(int i=b+3;i<=n;i++) g[i]=min(g[i-1],g[i-2])+cost[i];
		}
		if(b<n-1||y==1) printf("%lld\n",min(g[n],g[n-1]));
		if(y==0)
		{
			if(b==n) printf("%lld\n",g[n-1]);
			if(b==n-1) printf("%lld\n",g[n]);
		}
	}
	return 0;
}
