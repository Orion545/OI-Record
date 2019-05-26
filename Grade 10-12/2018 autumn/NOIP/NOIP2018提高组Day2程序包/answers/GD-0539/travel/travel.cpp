#include<cstdio>
#include<cstdlib>
#include<string.h>
#include<algorithm>
#include<cmath>
#include<iostream>
#define N 5100
#define M 5100
using namespace std;
struct node
{
	long u,v;
	bool operator<(const node &x)const
	{
		return u<x.u||u==x.u&&v>x.v;
	}
}a[2*M];
struct edge_node
{
	long to,next;
	void md(long h1,long h2)
	{
		to=h1,next=h2;
	}
}edge[M];
long el=0,head[N];
bool oo[N];
void dfs(long now)
{
	oo[now]=false;
	printf("%ld ",now);
	for (long i=head[now];i!=0;i=edge[i].next){
		long to=edge[i].to;
		if (oo[to]){
			dfs(to);
		}
	}
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	long n,m,i;
	scanf("%ld%ld",&n,&m);
	for (i=1;i<=m;i++){
		scanf("%ld%ld",&a[i].u,&a[i].v);
		a[m+i].u=a[i].v,a[m+i].v=a[i].u;
	}
	sort(a+1,a+2*m+1);
	for (i=1;i<=2*m;i++){
		edge[++el].md(a[i].v,head[a[i].u]),head[a[i].u]=el;
	}
	memset(oo,true,sizeof(oo));
	dfs(1);
	putchar('\n');
	fclose(stdin);
	fclose(stdout);
	return 0;
}
