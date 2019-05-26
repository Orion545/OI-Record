#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
#define INF 10000
using namespace std;
int n,m,u,v,pos=1,c[101],next[1000][1000];
bool g[1000][1000],vst[1000];
void devour(int po)
{
	int righ=-1;
	c[pos]=po;
	vst[po]=1;
	pos++;
	for(int i=1;i<=n;i++)
	{
		if(g[po][i]==1&&vst[i]==0)
		{
			righ++;
			next[po][righ]=i;
		}
	}
	if(righ==-1)
		return;
	for(int i=0;i<=righ;i++)
	{
		devour(next[po][i]);
	}
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d%d",&n,&m);
	memset(g,0,sizeof(g));
	memset(c,0,sizeof(c));
	memset(next,0,sizeof(next));
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&u,&v);
		g[u][v]=g[v][u]=1;		
	}
	devour(1);
	for(int i=1;i<=n;i++)
		cout<<c[i]<<" ";
	cout<<endl;
	return 0;
} 
