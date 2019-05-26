#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define maxn 5010

int n,m,len=0;
struct node{int x,y,next;};
node e[maxn*2];
int first[maxn];
void buildroad(int x,int y)
{
	len++;
	e[len].x=x;
	e[len].y=y;
	e[len].next=first[x];
	first[x]=len;
}
int list[maxn*2],t=0;
int notx=0,noty=0;
bool vis[maxn];
void dfs(int x,int fa)
{
	if(!vis[x])printf("%d ",x);
	vis[x]=true;
	int now=t;
	for(int i=first[x];i;i=e[i].next)
	{
		int y=e[i].y;
		if(y==fa||vis[y])continue;
		if(x==notx&&y==noty)continue;
		list[++t]=y;
	}
	if(now!=t)
	{
		sort(list+now+1,list+t+1);
		int p=t;
		for(int i=now+1;i<=p;i++)
		dfs(list[i],x);
	}
	else return;
}
int huan[maxn],tt=0,zhan[maxn],to=0;
bool v[maxn],tf=false;
int li[maxn],ts=0;
void gethuan(int x,int fa)
{
	zhan[++to]=x;v[x]=true;
	int now=ts;
	for(int i=first[x];i;i=e[i].next)
	{
		int y=e[i].y;
		if(tf)return;
		if(y==fa)continue;
		li[++ts]=y;
	}
	if(now!=ts)
	{
		sort(li+now+1,li+ts+1);
		int p=ts;
		for(int i=now+1;i<=p;i++)
		{
			if(tf)return;
			int y=li[i];
			if(v[y])
			{
				int p=to;
				while(zhan[p]!=y)p--;
				for(int j=p;j<=to;j++)
				huan[++tt]=zhan[j];
				tf=true;
			}
			else gethuan(y,x);
			if(tf)return;
		}
		
	}
	to--;
}

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int x,y;
		scanf("%d %d",&x,&y);
		buildroad(x,y);
		buildroad(y,x);
	}
	if(m==n-1)dfs(1,0);
	else
	{
		gethuan(1,0);
		for(int i=2;i<=tt;i++)
		if(huan[i]>huan[tt])
		{
			notx=huan[i-1];
			noty=huan[i];
			break;
		}
		if(!notx)notx=huan[1],noty=huan[tt];
		dfs(1,0);
	}
}
