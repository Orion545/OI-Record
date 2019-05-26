#include<cstdio>
#include<algorithm>
#include<vector>
#include<cctype>
using namespace std;
const int N=5005;
vector<int>e[N];
int n,m,top,tot,pos,pos1,num;
int d[N],st[N],dfn[N],ans[N],now[N];
bool bz[N];
inline int read()
{
	int X=0,w=0; char ch=0;
	while(!isdigit(ch)) w|=ch=='-',ch=getchar();
	while(isdigit(ch)) X=(X<<3)+(X<<1)+(ch^48),ch=getchar();
	return w?-X:X;
}
inline void insert(int x,int y)
{
	e[x].push_back(y);
	e[y].push_back(x);
}
void dfs(int x,int y)
{
	printf("%d ",x);
	for(int i=0;i<(int)e[x].size();i++)
	{
		int to=e[x][i];
		if(to^y) dfs(to,x);
	}
}
void find(int x,int y)
{
	st[++top]=x;
	dfn[x]=++tot;
	for(int i=0;i<(int)e[x].size();i++)
	{
		int to=e[x][i];
		if(!dfn[to]) find(to,x); else
		if(to^y && dfn[to]<dfn[x])
			for(int j=top;j;j--)
			{
				d[++d[0]]=st[j];
				if(st[j]==to) break;
			}
	}
	st[top--]=0;
}
void dfs2(int x,int y)
{
	now[++num]=x;
	for(int i=0;i<(int)e[x].size();i++)
	{
		int to=e[x][i];
		if(to^y && to^pos) dfs2(to,x);
	}
}
void dfs3(int x,int y)
{
	now[++num]=x;
	for(int i=0;i<(int)e[x].size();i++)
	{
		int to=e[x][i];
		if(to^y && to^pos1) dfs3(to,x);
	}
}
void dfs1(int x,int y)
{
	now[++num]=x;
	if(x==d[d[0]])
	{
		for(int i=0;i<(int)e[x].size();i++)
		{
			int to=e[x][i];
			if(to^y)
			{
				if(to==d[1]) dfs2(d[1],x); else
					if(to^d[d[0]-1]) dfs1(to,x); else
						if(to^pos1) dfs3(d[d[0]-1],x);
			}
		}
		return;
	}
	for(int i=0;i<(int)e[x].size();i++)
	{
		int to=e[x][i];
		if(to^y) dfs1(to,x);
	}
}
inline bool pd()
{
	for(int i=1;i<=n;i++)
	{
		if(ans[i]<now[i]) return false;
		if(ans[i]>now[i]) return true;
	}
	return false;
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=m;i++) insert(read(),read());
	for(int i=1;i<=n;i++) sort(e[i].begin(),e[i].end());
	if(m==n-1)
	{
		dfs(1,0);
		return 0;
	}
	find(1,0);
	if(d[d[0]-1]<d[1]) reverse(d+1,d+d[0]);
	ans[1]=n;
	for(int i=1;i<d[0];i++)
	{
		pos=d[i+1],pos1=d[i],num=0;
		dfs1(1,0);
		if(pd())
			for(int j=1;j<=n;j++) ans[j]=now[j];
	}
	for(int i=1;i<=n;i++) printf("%d ",ans[i]);
	return 0;
}
