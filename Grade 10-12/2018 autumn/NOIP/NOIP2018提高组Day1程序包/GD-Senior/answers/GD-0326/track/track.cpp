#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<queue>
#include<algorithm>

using namespace std;

const int maxn=110000;
const int INF=2e9;

struct arr{
	int x,y,w;
	int next;
}edge[maxn];
int ls[maxn];
int edge_m;

int n,m;

void add(int x,int y,int w)
{
	edge[++edge_m]=(arr){x,y,w,ls[x]},ls[x]=edge_m;
	edge[++edge_m]=(arr){y,x,w,ls[y]},ls[y]=edge_m;
	return;
}

int ans=0;
int wz=0;

int dfs(int x,int fa,int l)
{
	if (l>ans) 
	{ans=l,wz=x;}
	for (int i=ls[x];i;i=edge[i].next)
	{
		if (edge[i].y==fa) continue;
		dfs(edge[i].y,x,l+edge[i].w);
	}
	return 0;
}

void origami1()
{
	dfs(1,0,0);
	dfs(wz,0,0);
}

int b[maxn];

int pan(int ne)
{
	int nw=0;
	int num=0;
	for (int i=1;i<n;i++)
	{
		nw+=b[i];
		if (nw>=ne)
		{
			num++;
			nw=0;
		}
	}
	if (num>=m) return 1;
	else return 0;
}

void origami2()
{
	int num=0;
	for (int i=1;i<=edge_m;i+=2) num+=edge[i].w;
	int l=1,r=num;
	while (l<r)
	{
		int mid=((l+r)/2)+1;
		if (pan(mid)) l=mid;
		else r=mid-1;
	}
	ans=l;
}

int a[maxn];

int duan(int ne)
{
	int num=0;
	int nw=0;
	for (int i=n-1;i>=1;i--)
	{
		nw=i;
		if (a[i]<ne) break;
		num++;
	}
	if (num>=m) return 1;
	int j=0;
	for (int i=nw;i>j;i--)
	{
		j++;
		while (((a[i]+a[j])<ne)&&(j<i)) j++;
		if (j==i) break;
		if (a[i]+a[j]>=ne) num++;
	}
	if (num>=m) return 1;
	else return 0;
}

void origami3()
{
	int num=0;
	for (int i=1;i<=edge_m;i+=2) num+=edge[i].w;
	sort(a+1,a+n);
	int l=1,r=num;
	while (l<r)
	{
		int mid=((l+r)/2)+1;
		if (duan(mid)) l=mid;
		else r=mid-1;
	}
	ans=l;
}

int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	scanf("%d%d",&n,&m);
	int fl=1;
	int f2=1;
	for (int i=1;i<n;i++)
	{
		int x,y,w;
		scanf("%d%d%d",&x,&y,&w);
		add(x,y,w);
		a[i]=w;
		b[x]=w;
		if ((x+1)!=y) fl=0;
		if (x!=1) f2=0;
	}
	if (m==1)
		origami1();
	else
		if (fl)
			origami2();
		else 
			if (f2)
				origami3();
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
