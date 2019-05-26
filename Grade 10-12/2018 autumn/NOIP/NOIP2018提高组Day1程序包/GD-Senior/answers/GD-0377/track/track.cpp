#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define N 32000
#define forline for(int i=head[u];i;i=edge[i].nxt)
using namespace std;
int a[N],n,m,x,y,z,head[N],cnt,vi[N],ans,minn;
long long d1[N],d2[N],maxn;
struct node{
	int to;
	int nxt;
	int val;
}edge[N];
void add(int x,int y,int z)
{
	edge[++cnt].to=y;
	edge[cnt].val=z;
	edge[cnt].nxt=head[x];
	head[x]=cnt;
}
void work1(int u)
{
	vi[u]=1;
	forline
	{
		int v=edge[i].to;
		if (vi[v])	continue;
		work1(v);
		if ((d1[v]+edge[i].val)>d1[u])
		{
			d2[u]=d1[u];
			d1[u]=d1[v]+edge[i].val;
		}
		else if ((d1[v]+edge[i].val)>d2[u])
			d2[u]=d1[v];
	}
}
void work2(int k)
{
	if (k==0)	
	{
		ans=max(minn,ans);
		return;
	}
	int tmp=minn;
	for (int i=1;i<=n-1;i++)	
		for (int j=i+1;j<=n;j++)
		{
			if (i!=1)
			{
				if (vi[i]||vi[j])	continue;
				minn=min(minn,edge[head[i]].val+edge[head[j]].val);
				vi[i]=1;	vi[j]=1;
				work2(k-1);
				minn=tmp;
				vi[i]=0;	vi[j]=0;
			}
			else
			{
				if (vi[j])	continue;
				vi[j]=1;
				minn=min(minn,edge[head[j]].val);
				work2(k-1);
				vi[j]=0;
				minn=tmp;
			}
		}
}
int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	scanf("%d%d",&n,&m);	bool fl=1;
	for (int i=1;i<=n-1;i++)
	{
		scanf("%d%d%d",&x,&y,&z);
		add(x,y,z);	add(y,x,z);	if (x!=1&&y!=1)	fl=0;
	}
	if (m==1)
	{
		memset(d1,0,sizeof(d1));	memset(d2,0,sizeof(d2));
		work1(1);	maxn=0;
		for (int i=1;i<=n;i++)	maxn=max(maxn,d1[i]+d2[i]);
		printf("%lld\n",maxn);
	}
	else if (fl==1)
	{
		minn=60000;
		work2(m);
		printf("%d\n",ans);
	}
	else if (m==n-1)
	{
		minn=60000;
		for (int i=1;i<=cnt;i++)	minn=min(edge[i].val,minn);
		printf("%d\n",minn);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
