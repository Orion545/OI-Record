#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#define fo(i,x,y) for(i=x;i<=y;i++)
#define N 300550
#define ll long long
using namespace std;
int n,m,i,j,k,x,y,t,tot,u,v,xx,yy;
int a[N],nxt[N*2],lst[N],b[N*2];
ll inf,f[N][2];
char ch;
void link(int x,int y)
{
	b[++tot]=y;
	nxt[tot]=lst[x];
	lst[x]=tot;
}
int read()
{
	int x=0;
	char ch=getchar();
	while (ch<'0' || ch>'9') ch=getchar();
	while (ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
	return x;
}
bool judge()
{
	if (x || y) return false;
	int l=lst[u];
	while (l)
	{
		int to=b[l];
		if (to==v) return true;
		l=nxt[l];
	}
	return false;
}
void dfs(int x,int fa)
{
	int l=lst[x];
	ll sum1,sum2;
	bool bz=false;
	sum1=sum2=0;
	while (l)
	{
		int to=b[l];
		if (to!=fa)
		{
			dfs(to,x);
			if (bz || f[to][1]==inf) bz=true,sum1=inf;else sum1+=f[to][1];
			sum2+=min(f[to][0],f[to][1]);
		}
		l=nxt[l];
	}
	if (bz) f[x][0]=inf,f[x][1]=sum2+a[x];
	else
	{
		f[x][0]=sum1;
		f[x][1]=sum2+a[x];
	}
	if (u==x) f[x][1-xx]=inf;
	if (v==x) f[x][1-yy]=inf;
}
int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	scanf("%d%d",&n,&m);
	ch=getchar();
	while (ch<'0' || ch>'9') ch=getchar();
	fo(i,1,n) a[i]=read();
	fo(i,1,n-1)
	{
		x=read();y=read();
		link(x,y);link(y,x);
	}
	fo(i,1,m)
	{
		u=read();x=read();
		v=read();y=read();
		if (judge()) printf("-1\n");
		else
		{
			memset(f,25,sizeof(f));
			xx=x;yy=y;inf=f[1][0];
			dfs(1,0);
			printf("%lld\n",min(f[1][0],f[1][1]));
		}
	}
	return 0;
}
