#include<algorithm>
#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
struct pla
{
	int to,next;
}a[10010];
int n,m,edge_num,head[5010],lt[5010],na,ans[5010];
bool k[5010];
void add_edge(int x,int y)
{
	edge_num++;
	a[edge_num].next=head[x];
	a[edge_num].to=y;
	head[x]=edge_num;
}
void dfs(int root)
{
	k[root]=1;
	int rm=0;
	for(int i=head[root];i>0;i=a[i].next)
		if(!k[a[i].to])
			lt[++rm]=a[i].to;
	int lk[rm+2];
	for(int i=1;i<=rm;i++)
		lk[i]=lt[i];
	sort(lk+1,lk+rm+1);
	for(int i=1;i<=rm;i++)
	{
		if(k[lk[i]]) continue;
		ans[++na]=lk[i];
		dfs(lk[i]);
	}
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int x,y;
		cin>>x>>y;
		add_edge(x,y);
		add_edge(y,x);
	}
	na=ans[1]=1;
	dfs(1);
	for(int i=1;i<=na;i++)
		cout<<ans[i]<<" ";
	return 0;
}
