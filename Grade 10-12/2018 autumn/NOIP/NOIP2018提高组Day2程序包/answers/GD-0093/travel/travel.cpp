#include <iostream>
#include <algorithm>
#include <string.h>
#include <string>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

const int maxn=5010,INF=1e9;
int n,m,cur,t,Min,p;
int res[maxn],ans[maxn],L[maxn],mp[maxn][maxn],vis[maxn];
struct data
{
	int x,y,num;
}a[maxn*2];

bool cmp(data a,data b) {return (a.x<b.x || a.x==b.x && a.y<b.y);}

void dfs(int k,int to,int col)
{
	Min=INF;res[++p]=k;vis[k]=col;
	for (register int i=1;i<=L[k];i++)
		if (vis[mp[k][i]]!=col) dfs(mp[k][i],k,col);
}

void made2()
{
	for (int i=1;i<=2*m;i++) mp[a[i].x][++L[a[i].x]]=a[i].y;
	p=0;dfs(1,1,1);
	for (int j=1;j<=n;j++) ans[j]=res[j];
}

void made1()
{
	for (register int i=1;i<=m;i++)
	{
		for (register int j=1;j<=n;j++) L[j]=0;
		for (register int j=1;j<=2*m;j++)
		{
			if (i==a[j].num) continue;
			mp[a[j].x][++L[a[j].x]]=a[j].y;
		}
		p=0;dfs(1,1,i);
		
		if (p!=n) continue;
		bool ok=false;
		for (register int j=1;j<=n;j++)
			if (ans[j]>res[j]) {ok=true;break;}
				else if (ans[j]<res[j]) break;
		if (ok) for (int j=1;j<=n;j++) ans[j]=res[j];
	}
}

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++)
	{
		scanf("%d%d",&a[i].x,&a[i].y);a[i].num=i;
		a[i+m].x=a[i].y;a[i+m].y=a[i].x;a[i+m].num=i;
	}
	sort(a+1,a+1+2*m,cmp);
	
	for (int i=1;i<=n;i++) ans[i]=INF;
	if (n==m) made1();else made2();
	for (int i=1;i<n;i++) printf("%d ",ans[i]);
	printf("%d\n",ans[n]);
	
	return 0;
}
