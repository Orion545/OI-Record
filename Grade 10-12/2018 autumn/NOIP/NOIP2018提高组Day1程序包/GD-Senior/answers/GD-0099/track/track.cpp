#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
using namespace std;
int const N=50010;
int n,m;
int v[N],d[N],x[N];
int read()
{
	char C;int ret=1;
	C=getchar();
	while(C<'0'||C>'9')
	{
	  if(C=='-') ret=-1;
	  C=getchar();
	}
	int num=0;
	while(C>='0'&&C<='9') num=num*10+C-48,C=getchar();
	return num*ret;
}
struct Edge
{
	int to,dis;
	Edge(int t,int d):to(t),dis(d){}
};
vector<Edge> edge[N];
void dfs(int u)
{
	for(int i=0; i<edge[u].size(); i++)
	{
		int to=edge[u][i].to,dis=edge[u][i].dis;
		if(!v[to]&&d[u]+dis>d[to])
		{
			v[to]=1;
			d[to]=d[u]+dis;
			dfs(to);
			v[to]=0;
		}
	}
}
void Solve1()
{
	int ans=0;
	for(int i=1; i<=n; i++)
	{
		v[i]=1;
		dfs(i);
		int Max=0;
		for(int j=1; j<=n; j++) Max=max(Max,d[j]);
		ans=max(Max,ans);
		memset(d,0,sizeof(d));
		memset(v,0,sizeof(v));
	}
	printf("%d",ans);
	return;
}
bool check(long long lim)
{
	long long sum=0,tot=0;
	for(int i=1; i<=n; i++)
	{
		if(sum<lim) sum+=x[i];
		if(sum>=lim) sum=0,tot++;
		if(tot>m) return false;
	}
	return true;
}
void Solve2(long long Min,long long sum)
{
	long long left=Min,right=sum;
	while(left+1<right)
	{
		int mid=left+right>>1;
		if(check(mid)) right=mid;
		else left=mid;
	}
	printf("%lld",right);
	return ;
}
int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	n=read();m=read();bool t=1;
	int Min=1<<29;
	long long sum=0;
	for(int i=1; i<n; i++)
	{
		int a=read(),b=read(),l=read();
		if(b!=a+1) t=0;
		else x[a]=l;
		Min=min(l,Min);
		sum+=l;
		edge[a].push_back(Edge(b,l));
		edge[b].push_back(Edge(a,l));
	}
	if(m==1) Solve1();
	if(t) Solve2(Min,sum);
	return 0;
}

