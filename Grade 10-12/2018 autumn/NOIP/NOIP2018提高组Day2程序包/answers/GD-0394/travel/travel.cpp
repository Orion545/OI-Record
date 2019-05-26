#include<iostream>
#include<cstdio>
#include<queue>
#define maxn 5005
using namespace std;

priority_queue<int,vector<int>,greater<int> >state;
int n,m,u[maxn*2],v[maxn*2],first[maxn],next[maxn*2],gs[maxn],num;
bool vis[maxn],ch;

inline int read()
{
	char ch=getchar();
	while (ch<'0'||ch>'9') ch=getchar();
	int res=ch-48;
	ch=getchar();
	while (ch<='9'&&ch>='0') res=res*10+ch-48,ch=getchar();
	return res;
}

void add(int x)
{
	u[x]=read(); v[x]=read(); next[x]=first[u[x]]; first[u[x]]=x; 
	u[x+1]=v[x]; v[x+1]=u[x]; next[x+1]=first[v[x]]; first[v[x]]=x+1;
	
}

void dfs(int x)
{
	num--; vis[x]=true; 
	printf("%d ",x);
	if (num==0) 
	{
		ch=true; return;
	}
	int Min=maxn*2;
	priority_queue<int,vector<int>,greater<int> >q;
	for (int i=first[x]; i; i=next[i])
		if (!vis[v[i]])
			q.push(v[i]);
	while (!q.empty())
	{
		if (ch) return;
		int x1=q.top(); q.pop();
		dfs(x1);
	}
	vis[x]=false;
}

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
		
	n=read(); m=read(); num=n;
	for (int i=1; i<=m*2; i+=2)
		add(i);
	if (m==n)
	{
		state.push(1); 
		while (!state.empty())
		{
			int x=state.top();
			state.pop();
			if (vis[x]) continue;
			vis[x]=true;
			printf("%d ",x);
			for (int i=first[x]; i; i=next[i])
				if (!vis[v[i]])
					state.push(v[i]);
		}
	}
	else
	{
		ch=false; dfs(1);
	}
		
	fclose(stdin);fclose(stdout);
	return 0;
} 
