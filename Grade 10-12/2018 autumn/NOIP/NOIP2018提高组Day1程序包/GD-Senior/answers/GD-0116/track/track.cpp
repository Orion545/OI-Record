#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cmath>
#include<cstring>
#define N 50005

using namespace std;
int n,x,y,z,tot,m,ans;
int head[N],tail[N];
int dep[N];
int f[N][21];
int roadd[N][21];
bool check[N];

struct E
{
	int x,y,z;	
};E e[N*3];

bool cmp(E a,E b)
{
	return a.x<b.x;
}

int LCA(int x,int y)
{
	int anss=0;
	if (dep[x]<dep[y]) swap(x,y);
	for (int i=19;i>=0;i--)
	{
		if (dep[f[x][i]]<=dep[y]) ans+=roadd[x][i],x=f[x][i];
	}
	if (x==y) return x;
	for (int i=19;i>=0;i--)
	{
		if (dep[f[x][i]]!=dep[f[y][i]])
		{
			x=f[x][i],y=f[y][i];
			ans+=roadd[x][i];
			ans+=roadd[y][i];
		}
	}
	ans+=roadd[x][0]+roadd[y][0];
	return ans;
}

void dfs_LCA(int x,int father)
{
	if (x!=father) dep[x]=dep[father]+1;
	for (int i=1;i<=20;i++)
	{
		f[x][i]=f[f[x][i-1]][i-1];
		roadd[x][i]=roadd[x][i-1]+roadd[roadd[x][i-1]][i-1];
	}
	for (int i=head[x];i<=tail[x];i++) 
	if (check[i])
	{
		if (x!=father) f[x][0]=father,roadd[x][0]=e[i].z;
		check[i]=false;
		dfs_LCA(e[i].y,x);
	}
}



int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	memset(check,true,sizeof(check));
	ans=0;
	scanf("%d%d",&n,&m);
	tot=0;
	for (int i=1;i<n;i++)
	{
		scanf("%d%d%d",&x,&y,&z);
		e[++tot].x=x;e[tot].y=y;e[tot].z=z;
		e[++tot].x=y;e[tot].y=x;e[tot].z=z;
	}
	sort(e+1,e+tot+1,cmp);
	head[1]=1;
	int cnt=1;
	for (int i=2;i<=tot;i++)
	if (e[i].x!=head[cnt]) tail[cnt++]=i-1,head[cnt]=i;
	tail[cnt]=tot;
	dep[1]=1;
	dfs_LCA(1,1);
	for (int i=1;i<=n;i++)
	for (int j=1;j<=n;j++)
	if (i!=j) 
	{
		int kk=LCA(i,j);
		if (kk>ans) ans=kk;
	}
	printf("%d",ans);
}



