#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<iostream>
#define fo(i,x,y) for(i=x;i<=y;i++)
#define N 5055
using namespace std;
int n,m,i,j,k,x,y,t,p,q,num;
int a[N][N],b[N][2],ans[N],c[N];
bool bz[N];
void dfs(int x)
{
	c[++num]=x;
	bz[x]=true;
	int i;
	fo(i,1,a[x][0])
	{
		int to=a[x][i];
		if ((x==p && to==q) || (x==q && to==p)) continue;
		if (!bz[to]) dfs(to);
	}
}
bool judge()
{
	if (num!=n) return false;
	int i;
	fo(i,1,n)
	{
		if (c[i]<ans[i]) return true;
		if (c[i]>ans[i]) return false;
	}
	return false;
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d%d",&n,&m);
	fo(i,1,m)
	{
		scanf("%d%d",&x,&y);
		a[x][++a[x][0]]=y;
		a[y][++a[y][0]]=x;
		b[i][0]=x;b[i][1]=y;
	}
	fo(i,1,n)
	{
		sort(a[i]+1,a[i]+a[i][0]+1);
		ans[i]=n+1;
	}
	if (m==n-1)
	{
		dfs(1);
		memcpy(ans,c,sizeof(ans));
	}
	else
	{
		fo(i,1,m)
		{
			p=b[i][0];
			q=b[i][1];
			num=0;
			memset(bz,0,sizeof(bz));
			dfs(1);
			if (judge()) memcpy(ans,c,sizeof(ans));
		}
	}
	fo(i,1,n) printf("%d ",ans[i]);
	return 0;
}
