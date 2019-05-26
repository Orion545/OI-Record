#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
int head[101000],to[101000],next[101000],tot,w[101000];
int n,m;
long long dis[1010][1010],mmax;
long long s1max,s2max;
long long ans,s[51000],g[51000];
void cc(int x,int y,int z)
{
	to[++tot]=y;next[tot]=head[x];head[x]=tot;w[tot]=z;
	to[++tot]=x;next[tot]=head[y];head[y]=tot;w[tot]=z;
}
void bfs(int x,int fx,int t)
{
	for(int i=head[x];i;i=next[i])
	{
		int v=to[i];if(v==fx||dis[t][v])continue;
		dis[t][v]=dis[t][x]+w[i];
		mmax=max(dis[t][v],mmax);
		bfs(v,x,t);
	}
}
int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	scanf("%d%d",&n,&m);
	int x,y,z,num=0,sum=0;
	for(int i=1;i<=n-1;i++)
	{
		scanf("%d%d%d",&x,&y,&z);
		if(x==1)num++;
		if(x+1==y)sum++;
		g[x]=z;
		cc(x,y,z);
		if(s1max<=z)
		{
			s2max=s1max;
			s1max=z;
		}
	}
	if(m==1){
		if(num!=n-1)
		{
		for(int i=1;i<=n;i++)bfs(i,0,i);
		printf("%lld",mmax);//10
		return 0;		
		}
		if(num==n-1)
		{
		printf("%lld",s1max+s2max);//5
		return 0;
	    }
	}
	if(sum==n-1)
	{
		long long ans=0;
		for(int i=1;i<=n-1;i++)
		s[i]=s[i-1]+g[i];
		for(int i=1;i<=n-1;i++)
		{
			if(ans!=0)
			ans=min(ans,s[i+m]-s[i]);
			else
			ans=s[i+m]-s[i];
		}
		printf("%lld",ans);
		return 0;
	}
}
