#include<algorithm>
#include<cstdio>
#include<iostream>
#include<queue>
#include<cstdlib>
#include<cstring>
using namespace std;

int d[100005],f[100000][20],anc[100000][20],p[100000][20];
long long ans,n;

long long dfs(int l,int r,int s)	{
	if (l==r)	{
		return s-d[l];
	}
	int Len=(r-l+1),y=-1;
	while (Len!=0)	{
		Len>>=2;++y;
	}
	int x;
	if (f[l][y]<f[r-(1<<y)+1][y]) x=p[l][y];
	else x=p[r-(1<<y)+1][y];
	int total=dfs(l,x-1,d[x])+dfs(x+1,r,d[x]);
}

void merge()	{
	memset(anc,0,sizeof(anc));
	memset(f,0x3f,sizeof(f));
	for (int i=1;i<=n;++i)	{
		f[i][0]=d[i];
		anc[i][0]=i;
		p[i][0]=i;
	}
	for (int k=1;k<=20;++k)	{
		for (int i=1;i<=n;++i)	{
			if (f[i][k-1]<f[anc[i][k-1]][k-1])	{
				f[i][k]=f[i][k-1];
				p[i][k]=p[i][k-1];
			}
			else 	{
				f[i][k]=f[anc[i][k-1]][k-1];
				p[i][k]=p[anc[i][k-1]][k-1];
			}
			anc[i][k]=anc[anc[i][k-1]][k-1];
		}
	}
	ans=dfs(1,n,0);
}
 
int main()	{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int maxx=0;
	scanf("%d",&n);
	for (int i=1;i<=n;++i)	{
		scanf("%d",&d[i]);
		maxx=max(maxx,d[i]);
	}
	if (n<=1000)	{
		for (int k=1;k<=maxx;++k)	{
			int s=0;
			for (int i=1;i<=n;++i)
				if (d[i]<k) 	{
					if (s!=0) ans++;
					s=0;
				}
				else ++s;
			if (s!=0) ans++;
		}
	}
	else 	{
		merge();
	}
	printf("%lld\n",ans);
	return 0;
}
