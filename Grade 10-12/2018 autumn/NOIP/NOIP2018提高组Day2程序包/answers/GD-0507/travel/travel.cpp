#include<bits/stdc++.h>
using namespace std;
const int N=5050;
struct Tedge{
	int v,nxt;
}e[N*2];
stack<int> sta;
multiset<int> Set[N];
multiset<int>::iterator it;
int ans[N],ans1[N],in[N],head[N];
int n,m,tot=1,cnt; 
inline int read()
{
	char ch=getchar();int x=0,f=0;
	for(; ch<'0'||ch>'9' ;ch=getchar())	if(ch=='-')	f=1;
	for(;'0'<=ch&&ch<='9';ch=getchar())	x=(x<<3)+(x<<1)+(ch^48);
	return f?-x:x;
}
void add(int u,int v)
{
	e[++tot]=(Tedge){v,head[u]};head[u]=tot;
	e[++tot]=(Tedge){u,head[v]};head[v]=tot;
}
void dfs1(int u)
{
	in[u]=1;ans[++cnt]=u;
	for(int i=head[u];i;i=e[i].nxt)
	{
		int v=e[i].v;
		if(!in[v])	Set[u].insert(v);
	}
	if(Set[u].empty())	return ;
	for(it=Set[u].begin();it!=Set[u].end();it=Set[u].begin())
	{
		Set[u].erase(it);
		dfs1(*it);
	}	
}
void solve1()
{
	dfs1(1);
	for(int i=1;i<cnt;i++)	printf("%d ",ans[i]);
	printf("%d\n",ans[cnt]);
}
void dfs2(int u,int k)
{
	if(!in[u])ans[++cnt]=u;in[u]=1;
	for(int i=head[u];i;i=e[i].nxt)
	{
		int v=e[i].v;
		if(i==k||(i==(k^1)))	continue;
		if(!in[v])	Set[u].insert(v);
	}
	if(Set[u].empty())	return ;
	for(it=Set[u].begin();it!=Set[u].end();it=Set[u].begin())
	{
		Set[u].erase(it);
		dfs2(*it,k);
	}	
}
void solve2(){
	ans1[1]=n+1;
	for(int i=1;i<=m;i++)	
	{
		memset(in,0,sizeof in);
		cnt=0;
		for(int j=1;j<=n;j++)	ans[j]=n+1;
		dfs2(1,i*2);
		for(int j=1;j<=n;j++)
		{
			bool flag=0;
			if(ans1[j]<ans[j])	break;
			if(ans1[j]>ans[j])
			{
				for(int k=1;k<=n;k++)	ans1[k]=ans[k];
				flag=1;
			}
			if(flag)	break;
		}
	}
	for(int i=1;i<n;i++)	printf("%d ",ans1[i]);
	printf("%d\n",ans1[n]);
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	n=read(); m=read();
	for(int i=1;i<=m;i++)
	{
		int u=read(),v=read();
		add(u,v);
	}
	if(m==n-1)	solve1();
		else	solve2();
	return 0;
}
