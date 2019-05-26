#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#define endl '\n'
using namespace std;
int n,k;
const int maxn=50005;
int p1;
int maxs1;
int cnt;
int ans=0;
struct ha
{
	int to;
	int next;
	int len;
	int id;
}e[maxn*2];
int pre[maxn];
bool vis[maxn];
inline void addedge(int u,int v,int w,int id)
{
	e[++cnt].to=v;
	e[cnt].len=w;
	e[cnt].next=pre[u];
	e[cnt].id=id;
	pre[u]=cnt;
}
void dfs1(int u,int len,int fa)
{
	register int i,j,v;
	bool flag=true;
	for(i=pre[u];i;i=e[i].next)
	{
		v=e[i].to;
		if(v==fa) continue;
		flag=false;
		dfs1(v,e[i].len+len,u);
	}
	if(flag)
	{
		if(len>maxs1)
		{
			maxs1=len;
			p1=u;
		}
	}
	return;
}
int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	scanf("%d%d",&n,&k);
	register int a,b,c,d;
	int mins1=1e9;
	int tot=0;
	for(a=1;a<n;a++)
	{
		scanf("%d%d%d",&b,&c,&d);
		addedge(b,c,d,a);
		addedge(c,b,d,a);
		tot+=d;
		mins1=min(d,mins1);
	}
	if(k==1)
	{
		dfs1(1,0,0);
		dfs1(p1,0,0);
		cout<<maxs1<<endl;
		return 0;
	}
	else
	if(k==n-1)
	{
		cout<<mins1<<endl;
		return 0;
	}
	printf("%d\n",mins1);
	return 0;
	return 0;
}
/*
7 1
1 2 10
1 3 5
2 4 9
2 5 8
3 6 6
3 7 7
*/
