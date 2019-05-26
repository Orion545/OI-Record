#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>
#include<cstdlib>
using namespace std;
#define INF 500000001
#define N 50020
struct edge{
	int x,y,l,nex,ney;
}e[N];
int n,m,cnt = 0;
int f[N];
int gg[N],ne[N],g[N],l[N];
bool check(int k)
{
	int now = 0,per=0;
	for(int i=1;i<=n;i++) 
	{
		if(now+gg[i]>=k) 
		{
			now=0;
			per ++;
		}
		else now +=gg[i];
	}
	if(per<m) return 0;
	return 1;
}
void dfs(int u,int pre)
{
	f[u] = 0;
	int j=g[u];
	while(j)
	{
		if(e[j].x == u )
		{
			if(e[j].y != pre)
			{
			dfs(e[j].y,u);
			f[u] = max(f[u],f[e[j].y] + e[j].l);
			}
			j = e[j].nex;
		}
		if(e[j].y == u)
		{
			if(e[j].x != pre)
			{
			dfs(e[j].x,u);
			f[u] = max(f[u],f[e[j].x] +e[j].l);
			}
			j = e[j].ney;
		}
	} 
	return ;
}
int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	scanf("%d%d",&n,&m);
	bool bo = 0,bo2=1;
	for(int i=1;i<n;i++)
	  {
	  	int x,y;
	  	scanf("%d%d%d",&x,&y,&l[i]);
	  	if(abs(x-y)!=1) bo=1;
	  	if(x!=1 && y!=1) bo2=1;
	  	e[++cnt].x = x;
		 e[cnt].y =y;
		 e[cnt].l = l[i];
		 e[cnt].nex =g[x];
		 e[cnt].ney =g[y];
		 g[x] = g[y] = cnt;
	}
	if(!bo)
	{
		for(int i=1;i<=n;i++)
		{
			int j=g[i];
			while(j)
			{
				int to = e[j].x+e[j].y-i;
				if(to>i) gg[i] = e[j].l; 
				if(e[j].x == i)j = e[j].nex;
				else j =e[j].ney;
			}
		}
		int l = 0, r = INF;
		while(l+1<r)
		{
			int mid = (l+r)>>1;
			if(check(mid)) l = mid;
			else r = mid-1;
		}
		printf("%d\n",l);
	}
	else if(m==1)
	{
		int ans = 0;
		for(int i=1;i<=n;i++)
		{
			memset(f,0,sizeof(f));
			dfs(i,0);
			ans = max(ans,f[i]);
		}
		printf("%d\n",ans);
	}
	return 0;
}
