#include<iostream>
#include<cstdio>
using namespace std;


int n,m,i,j,k,l,x,y,z;
int nex[100005],dm[100005],len[100005],last[50005];
bool b[50005];
long long ans,a[50005],f[50005];

void add(int x, int y, int z)
{
	j++;
	nex[j]=last[x];
	last[x]=j;
	dm[j]=y;
	len[j]=z;
}

int dfs(int x)
{
	b[x]=1;
	//printf("%d\n",x);
	long long ma=0,le,lma=0;
	for (int i=last[x]; i; i=nex[i])
		if (!b[dm[i]])
		{
			le=dfs(dm[i]);
			le+=len[i];
			if (le>ma) lma=ma,ma=le;
			else if (le>lma) lma=le;
			//printf("%d %d %d %d %d\n",x,dm[i],ma,le,lma);
			//printf("%d\n",le);
		}
	ans=max(ans,ma+lma);
	//printf("%d %d\n",x,ans);
	//printf("%d %d %d\n",x,ma,lma);
	return ma;
}

int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	scanf("%d%d",&n,&m);
	
	if (m==1)
	{
		for (i=1; i<n; i++)
		{
			scanf("%d%d%d",&x,&y,&z);
			add(x,y,z);
			add(y,x,z);
		}
		dfs(1);
		printf("%lld",ans);
		return 0;
	}
	for (i=1; i<n; i++)
	{
		scanf("%d%d%d",&x,&y,&z);
		a[x]=z;
		f[0]+=z;
	}
	for (i=1; i<n; i++)
		for (j=min(i,m); j; j--)
			f[j]=max(min(f[j-1],a[i]),f[j]+a[i]);
	printf("%lld",f[m]);
	return 0;
}
