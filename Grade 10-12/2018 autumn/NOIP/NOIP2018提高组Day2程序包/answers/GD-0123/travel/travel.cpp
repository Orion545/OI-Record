#include<bits/stdc++.h>
#define LL long long
using namespace std;

struct node
{
	int x,y;
}a[10001],d;
vector<int> edges[10001],edgess[10001];
bool vis[10001],bo[10001],f=0,ff=0;
int b[10001],c[10001],cnt=0,tp=0,nw=0;

LL read()
{
	LL num=0; int f=1;
	char ch=getchar();
	while(!isdigit(ch))
	{
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(isdigit(ch))
	{
		num=num*10+ch-'0';
		ch=getchar();
	}
	return num*f;
}

bool cmp(node a,node b)
{
	if(a.x==b.x) return a.y<b.y;
	return a.x<b.x;
}

void dfs1(int root,int fa)
{
	vis[root]=1;
	int len=edgess[root].size();
	for(int i=0;i<len;i++)
	{
		if(vis[edgess[root][i]] && edgess[root][i]!=fa)
		{
			nw=root; tp=edgess[root][i];
			f=1; return;
		}
		if(vis[edgess[root][i]]) continue;
		dfs1(edgess[root][i],root);
		if(f==1)
		{
			if(root==tp) ff=1;
			if(!ff) c[++cnt]=root;
			return;
		}
	}
}

void dfs(int root)
{
	vis[root]=1;
	b[++cnt]=root;
	int len=edges[root].size();
	for(int i=0;i<len;i++)
	{
		int r=edges[root][i];
		if(vis[r]) continue;
		dfs(r);
	}
}

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int n=read(),m=read();
	for(int i=1;i<=m;i++)
	{
		a[i].x=read(); a[i].y=read();
		if(a[i].x>a[i].y) swap(a[i].x,a[i].y);
	}
	sort(a+1,a+m+1,cmp); memset(bo,sizeof(bo),0);
	if(n==m)
	{
		for(int i=1;i<=m;i++)
		{
			edgess[a[i].x].push_back(a[i].y);
			edgess[a[i].y].push_back(a[i].x);
		}
		memset(vis,sizeof(vis),0);
		dfs1(1,0);
		for(;cnt>0;cnt--)
		if(c[cnt]>nw)
		{
			d.x=c[cnt];
			d.y=c[cnt+1];
			break;
		}
		for(int i=1;i<=m;i++)
		if(a[i].x==d.x && a[i].y==d.y || a[i].x==d.y && a[i].y==d.x)
		{
			bo[i]=1; break;
		}
	}
	for(int i=1;i<=m;i++)
	if(!bo[i])
	{
		edges[a[i].x].push_back(a[i].y);
		edges[a[i].y].push_back(a[i].x);
	}
	for(int i=1;i<=n;i++) vis[i]=0;
	cnt=0;
	dfs(1);
	for(int i=1;i<=cnt;i++) printf("%d ",b[i]);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
