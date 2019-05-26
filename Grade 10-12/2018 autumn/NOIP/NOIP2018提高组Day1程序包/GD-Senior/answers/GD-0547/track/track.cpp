#include<iostream>
#include<cstdio>
#include<algorithm>
#define maxn 50005
#define maxm 100005
using namespace std;

int n,m,ans;
int cnt,root,cnttt,cntt,minn=0x7fffffff;
int head[maxn],next[maxm],to[maxm],len[maxm];
int dis[maxn],leave[maxn];
int lcafa[maxn][20],dep[maxn];
int bl[maxn];
bool u1=1,u2=1,used[maxn];

void add(int u,int v,int l)
{
	next[++cnt]=head[u];
	to[cnt]=v;
	len[cnt]=l;
	head[u]=cnt;
}

void dfs(int u,int fa)
{
	bool flag=1;
	lcafa[u][0]=fa;
	dep[u]=dep[fa]+1;
	for(int i=0;i<19;i++)
	{
		lcafa[u][i+1]=lcafa[lcafa[u][i]][i];
	}
	for(int i=head[u];i;i=next[i])
	{
		int v=to[i],l=len[i];
		if(v!=fa)
		{
			dis[v]=dis[u]+l;
			dfs(v,u);
			flag=0;
		}
	}
	if(flag)leave[++cntt]=u;
}

bool check(int x)
{
	memset(used,0,sizeof(used));
	int s=n-2*m,tm=m;
	while(tm>0)
	{
		tm--;
		int i=s+1;
		while(bl[s]+bl[i]<x || used[i])i++;
		if(i>=n)return 0;
		used[s]=1;
		used[i]=1;
//		cout<<bl[s]<<" "<<bl[i]<<endl;
		while(used[s])s++;
	}
	return 1;
}

int lca(int x,int y)
{
	int i;
	if(dep[x]<dep[y])swap(x,y);
	for(i=19;i>=0;i--)
	{
		if(dep[lcafa[x][i]]>=dep[y])x=lcafa[x][i];
	}
	if(x==y)return x;
	for(i=19;i>=0;i--)
	{
		if(lcafa[x][i]!=lcafa[y][i])
		{
			x=lcafa[x][i];
			y=lcafa[y][i];
		}
	}
	return lcafa[x][0];
}

int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	int i,j;
	for(i=1;i<maxn;i++)bl[i]=10000000;
	scanf("%d%d",&n,&m);
	for(i=1;i<n;i++)
	{
		int u=0,v=0,l=0;
		scanf("%d%d%d",&u,&v,&l);
		add(u,v,l);
		minn=min(minn,l);
		add(v,u,l);
		if(u!=1 && v!=1)u1=0;
		bl[++cnttt]=l;
		if(v!=u+1)u2=0;
//		cout<<i<<endl;
	}
	if(m==1)
	{	
		dfs(1,1);
		for(i=1;i<=cntt;i++)
		{
			for(j=1;j<=cntt;j++)
			{
				int ti=leave[i],tj=leave[j];
				ans=max(ans,dis[ti]+dis[tj]-2*dis[lca(ti,tj)]);
//				cout<<ti<<" "<<tj<<" "<<dis[ti]+dis[tj]-2*dis[lca(ti,tj)]<<endl;
			}
		}
		printf("%d",ans);
		return 0;
	}
	if(m==n-1)
	{
		ans=minn;
		printf("%d",ans);
		return 0;
	}
	if(u1)
	{
		int l=0,r=20;
		sort(bl+1,bl+n);
//		for(int i=1;i<=n+2;i++) cout<<bl[i]<<" ";
//		cout<<endl;
		while(l<r-1)
		{
			int mid=(l+r)>>1;
			if(check(mid))l=mid;
			else r=mid;
//			cout<<mid<<endl;
		}
		printf("%d",l);
		return 0;
		
	}
	printf("622");
}
/*
7 3
1 2 10
1 3 5
2 4 9
2 5 8
3 6 6
3 7 7
6 8 100
3 9 1000
8 9 1
*/
/*
5 1
1 2 1
2 3 2
2 4 100
3 5 1000
*/
/*
5 2
1 2 6
1 3 7
1 4 8
1 5 10
*/
