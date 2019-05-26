#include<iostream>
#include<string>
#include<cstring>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<stdio.h>
#include<algorithm>
#include<set>
using namespace std;

const int maxn=50100;

struct edge
{
	int obj,len;
	edge *Next;
} e[maxn<<1];
edge *head[maxn];
int cur=-1;

int f[maxn];
int sum;

set <int> a;

int dis[maxn];

int n,m,maxR=0;

void Add(int x,int y,int z)
{
	cur++;
	e[cur].obj=y;
	e[cur].len=z;
	e[cur].Next=head[x];
	head[x]=e+cur;
}

void Find(int node,int fa)
{
	for (edge *p=head[node]; p; p=p->Next)
	{
		int son=p->obj;
		if (son==fa) continue;
		dis[son]=dis[node]+p->len;
		Find(son,node);
	}
}

void Solve1()
{
	dis[1]=0;
	Find(1,1);
	
	int root=1;
	for (int i=2; i<=n; i++) if (dis[i]>dis[root]) root=i;
	
	dis[root]=0;
	Find(root,root);
	
	int ans=0;
	for (int i=1; i<=n; i++) ans=max(ans,dis[i]);
	printf("%d\n",ans);
}

void Dfs(int node,int fa,int x)
{
	for (edge *p=head[node]; p; p=p->Next)
		if (p->obj!=fa) Dfs(p->obj,node,x);
	
	a.clear();
	for (edge *p=head[node]; p; p=p->Next)
		if (p->obj!=fa) a.insert(f[p->obj]+p->len);
	
	set <int> :: iterator P,Q;
	while ( !a.empty() )
	{
		P=a.end();
		P--;
		if ( (*P)>=x ) a.erase(P),sum++;
		else break;
	}
	
	f[node]=0;
	while ( !a.empty() )
	{
		P=a.begin();
		Q=a.lower_bound( x-(*P) );
		if (P==Q) Q++;
		
		if (Q==a.end()) f[node]=max(f[node], (*P) ),a.erase(P);
		else
		{
			a.erase(P);
			a.erase(Q);
			sum++;
		}
	}
}

int Binary()
{
	double x=log( (double)n )/log(2.0);
	x=x*( log( (double)maxR )/log(2.0) );
	int y=n*(int)x+10;
	y=max(5000000/y,1);
	y=max(n/y,1);
	
	int L=0,R=maxR;
	while (L+1<R)
	{
		int mid=( (L+R)>>1 );
		int temp=0;
		
		for (int i=1; i<=n; i+=y)
		{
			sum=0;
			Dfs(i,i,mid);
			temp=max(temp,sum);
		}
		
		if (temp>=m) L=mid;
		else R=mid;
	}
	return L;
}

int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	
	scanf("%d%d",&n,&m);
	for (int i=1; i<=n; i++) head[i]=NULL;
	for (int i=1; i<n; i++)
	{
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		Add(x,y,z);
		Add(y,x,z);
		maxR+=z;
	}
	maxR=maxR/m+50;
	
	if (m==1) Solve1();
	else
	{
		int ans=Binary();
		printf("%d\n",ans);
	}
	
	return 0;
}





























