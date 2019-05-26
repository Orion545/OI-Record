#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#include<vector>
#define inf 10000000
#define ll long long
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int n,m,ans,cnt;
struct edge{int to,next;}e[4000005];
int a[100005];
int pre[100005],next[100005],last[100005];
int belong[100005];
bool vis[100005],d[100005];
void insert(int u,int v)
{
	e[++cnt].to=v;e[cnt].next=last[u];last[u]=cnt;
	e[++cnt].to=u;e[cnt].next=last[v];last[v]=cnt;
}
void del(int x)
{
	d[x]=1;
	int t=pre[x];
	next[t]=next[x];
	pre[next[x]]=t;
}
void dfs(int x)
{
	a[ans]++;
	vector<int> t;
	for(int i=last[x];i;i=e[i].next)t.push_back(e[i].to);
	sort(t.begin(),t.end());
	int k=0;
	for(int i=next[0];i<=n;i=next[i])
	{
		while(i>t[k]&&k<t.size()-1)k++;
		if(i!=t[k]&&!d[i])
		{
			del(i),dfs(i);
		}
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
		if(!d[i])
			del(i),ans++,dfs(i);
	printf("%d\n",ans);
	sort(a+1,a+ans+1);
	for(int i=1;i<=ans;i++)
		printf("%d ",a[i]);
	return 0;
}
