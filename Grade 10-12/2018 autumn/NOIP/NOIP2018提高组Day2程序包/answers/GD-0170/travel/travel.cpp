#include<bits/stdc++.h>
#define M 5005
using namespace std;
void read(int &x)
{
	x=0;
	char ch=getchar();
	while (!isdigit(ch))
	{
		ch=getchar();
	}
	while (isdigit(ch))
	{
		x=(x<<3)+(x<<1)+ch-'0';
		ch=getchar();
	}
}
void out(int x)
{
	if (x>9)
		out(x/10);
	putchar(x%10+'0');
}
struct node
{
	int u,v,nxt;
}a[M*2];
int first[M];
bool vis[M];
int top;
int n,m;
void addedge(int u,int v)
{
	++top;
	a[top].u=u;
	a[top].v=v;
	a[top].nxt=first[u];
	first[u]=top;
}
void dfs(int u)//Ò»¿ÅÊ÷ 
{
	priority_queue<int,vector<int>,greater<int> >q;
	vis[u]=1;
	printf("%d ",u);
	for (int i=first[u];i!=0;i=a[i].nxt)
	{
		int v=a[i].v;
		if (!vis[v])
			q.push(v);
	}
	while (!q.empty())
	{
		int now=q.top();
		q.pop();
		if (!vis[now])
		{
			dfs(now);
		}
	}
	return;
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=m;i++)
	{
		int u,v;
		read(u),read(v);
		addedge(u,v);
		addedge(v,u);
	}
	dfs(1);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

