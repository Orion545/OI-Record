#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#include<vector>
#define next ddf
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int n,m,ans,cnt;
struct edge{int to,next;}e[400005];
int a[200005],q[200005];
int pre[200005],next[200005],last[200005];
int belong[200005];
bool vis[200005],t[200005];
void insert(int u,int v)
{
	e[++cnt].to=v;e[cnt].next=last[u];last[u]=cnt;
	e[++cnt].to=u;e[cnt].next=last[v];last[v]=cnt;
}
void del(int x)
{
	int t=pre[x];
	next[t]=next[x];
	pre[next[x]]=t;
}
void bfs(int x)
{
	int head=0,tail=1;
	q[0]=x;
	while(head!=tail)
		{
			a[ans]++;
			int now=q[head];head++;
			for(int i=last[now];i;i=e[i].next)t[e[i].to]=1;
			for(int i=next[0];i<=n;i=next[i])
				if(!t[i])
					del(i),q[tail++]=i;
			for(int i=last[now];i;i=e[i].next)t[e[i].to]=0;
		}
}
int main()
{
	n=read();m=read();
	for(int i=0;i<=n;i++)next[i]=i+1;
	for(int i=1;i<=n+1;i++)pre[i]=i-1;
	for(int i=1;i<=m;i++)
	{
		int u=read(),v=read();
		insert(u,v);
	}
	for(int i=next[0];i<=n;i=next[0])
		del(i),ans++,bfs(i);
	printf("%d\n",ans);
	sort(a+1,a+ans+1);
	for(int i=1;i<=ans;i++)
		printf("%d ",a[i]);
	return 0;
}
