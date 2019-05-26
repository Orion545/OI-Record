#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int p,head[5002],to[10002],last[10002];
int a[5002];
void add(int u,int v)
{
	p++;
	last[p]=head[u];
	to[p]=v;
	head[u]=p;
}
void dfs(int x,int fa,int p1)
{
	cout<<x<<" ";
	int p2=p1;
	for(int j=head[x];j;j=last[j])
	if(to[j]!=fa)
	{
		p2++;
		a[p2]=to[j];
	}
	sort(a+p1+1,a+p2+1);
	for(int i=p1+1;i<=p2;i++)
	dfs(a[i],x,p2);
}
bool pt;
int pt1;
void dfs1(int x,int fa)
{
	for(int j=head[x];j;j=last[j])
	if(to[j]!=fa)
	{
		
	}
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int n,m,t1,t2;
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>t1>>t2;
		add(t1,t2);
		add(t2,t1);
	}
	if(m==n-1)
	dfs(1,0,0);
	else
	{
		pt=true;
		dfs()
	}
	cout<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
