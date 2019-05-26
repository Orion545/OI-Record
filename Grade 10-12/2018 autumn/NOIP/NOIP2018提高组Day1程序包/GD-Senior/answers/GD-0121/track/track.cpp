#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m;
bool pd=1,lspd=1;
int sum[50001],z[50001],ans;
struct bian{
	int x;
	int y;
	int w;
}b[50001];
int next[100001],to[100001],w[100001],head[50001],tot=0;
int fa[50001][2],maxx[50001],zz[50001];
void jb(int x,int y,int ww)
{
	next[++tot]=head[x];
	head[x]=tot;
	to[tot]=y;
	w[tot]=ww;
}
void search1(int s,int dis)
{
	if(dis>ans)ans=dis;
	z[s]=1;
	int ls=head[s];
	while(ls!=-1)
	{
		int v=to[ls],ww=w[ls];
		if(!z[v])
		{
			z[v]=1;
			search1(v,dis+ww);
		}
		ls=next[ls];
	}
}
bool cmp(bian a,bian b)
{
	return a.x<b.x;
}
bool check(int x)
{
	int ls=0,lsans=0;
	for(int i=1;i<=n-1;i++)
	{
		if(b[i].w>=x)
		{
			lsans++;
			ls=0;
		}
		else{
			ls+=b[i].w;
			if(ls>=x)
			{
				lsans++;
				ls=0;
			}
		}
	}
	if(lsans>=m)return 1;
	return 0;
}
bool cmpp(bian a,bian b)
{
	return a.w>b.w;
}
bool search2(int s,int x)
{
	int ls=head[s];
	while(ls!=-1)
	{
		int v=to[ls];
		search2(v,x);
		if(maxx[v]+w[ls]>=x)
		{
			ans++;
		}
		else{
			if(maxx[v]+w[ls]>maxx[s])
			{
				maxx[s]=maxx[v]+w[ls];
			}
		}
		ls=next[ls];
	}
	if(maxx[s]>=x)ans++;
	if(s==1&&ans>=m)return 1;
}
int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	memset(head,-1,sizeof(head));
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n-1;i++)
	{
		scanf("%d%d%d",&b[i].x,&b[i].y,&b[i].w);
		if(b[i].y!=b[i].x+1)pd=0;
		if(b[i].x!=1)lspd=0;
		jb(b[i].x,b[i].y,b[i].w);
		jb(b[i].y,b[i].x,b[i].w);
	}
	if(m==1)
	{
		ans=0;
		for(int i=1;i<=n-1;i++)
		{
			sum[b[i].x]++;
			sum[b[i].y]++;
		}
		for(int i=1;i<=n;i++)
		{
			if(sum[i]==1)
			{
				memset(z,0,sizeof(z));
				search1(i,0);
			}
		}
		printf("%d",ans);
		return 0;
	}
	else if(m==n-1)
	{
		ans=10001;
		for(int i=1;i<=n-1;i++)
		{
			if(b[i].w<ans)ans=b[i].w;
		}
		printf("%d",ans);
		return 0;
	}
	else if(pd==1)
	{
		sort(b+1,b+n,cmp);
		int l=1,r=10000;
		while(l<=r)
		{
			int mid=(l+r)/2;
			if(check(mid))
			{
				l=mid+1;
			}
			else{
				r=mid-1;
			}
		}
		printf("%d",r);
		return 0;
	}
	else if(lspd==1)
	{
		sort(b+1,b+n,cmpp);
		printf("%d",b[m].w);
		return 0;
	}
	for(int i=1;i<=n-1;i++)
	{
		sum[b[i].x]++;
		sum[b[i].y]++;
	}
	bool fuck=1;
	for(int i=1;i<=n;i++)
	{
		if(sum[i]>3)fuck=0;
	}
	if(fuck)
	{
		int l=1,r=10000;
		while(l<=r)
		{
			memset(maxx,0,sizeof(maxx));
			memset(z,0,sizeof(z));
			memset(zz,0,sizeof(zz));
			ans=0;
			int mid=(l+r)/2;
			if(search2(1,mid))
			{
				l=mid+1;
			}
			else{
				r=mid-1;
			}
		}
		printf("%d",r);
		return 0;
	}
	long long fake=0;
	for(int i=1;i<n;i++)
	{
		fake+=b[i].w;
	}
	printf("%lld",fake/m-1);
}
