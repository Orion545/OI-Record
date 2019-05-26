#include <queue>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
inline int read()
{
	int x=0,w=0;char ch=getchar();
	while(ch<'0'||ch>'9')w|=ch=='-',ch=getchar();
	while(ch>='0'&&ch<='9')x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return w?-x:x;
}
struct node
{
	int x,y,ne;
	friend bool operator < (const node &a1,const node &a2)
	{ return a1.y>a2.y; }
}a[21000];
int last[5100],len,n,m,fa[5100],dep[5100],aa,bb;
bool v[5100],vv[5100],bk;
priority_queue<node> q[5100],qq[5100];
inline void ins(int x,int y)
{
	a[++len].x=x,a[len].y=y;
	a[len].ne=last[x],last[x]=len;
	q[x].push(a[len]);
	qq[x].push(a[len]);
}
inline void dfs(int x)
{
	v[x]=0,printf("%d ",x);
	while(!q[x].empty())
	{
		node no=q[x].top();q[x].pop();
		int y=no.y;
		if(v[y])dfs(y);
	}
}
inline void dfs1(int x,int mi)
{
	v[x]=0,printf("%d ",x);
	while(!q[x].empty())
	{
		bool pd=1;
		for(int i=last[x];i;i=a[i].ne)if(!vv[a[i].y]&&v[a[i].y])pd=0;
		int pp=1e9;
		for(int i=last[x];i;i=a[i].ne)if(v[a[i].y])pp=min(pp,a[i].y);
		if(pd&&bk&&vv[x]&&pp>mi){bk=0;return;}
		node no=q[x].top();q[x].pop();
		int y=no.y;
		if(v[y])
		{
			pp=1e9;
			for(int i=last[x];i;i=a[i].ne)if(v[a[i].y])pp=min(pp,a[i].y);
			dfs1(y,pp);
		}
	}
}
void gettr(int x)
{
	while(!qq[x].empty())
	{
		node no=qq[x].top();qq[x].pop();
		int y=no.y;
		if(y!=fa[x])
		{
			if(!fa[y])
			{
				fa[y]=x;
				dep[y]=dep[x]+1;
				gettr(y);
			}
			else
			{
				aa=x,bb=y;
				if(dep[aa]<dep[bb])swap(aa,bb);
			}
		}
	}
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	memset(v,1,sizeof(v));
	n=read(),m=read();
	register int i;
	for(i=1;i<=m;++i)
	{
		int x=read(),y=read();
		ins(x,y),ins(y,x);
	}
	if(m==n-1)dfs(1);
	else
	{
		fa[1]=0;
		dep[1]=1;
		gettr(1);
		while(dep[aa]>dep[bb])vv[aa]=1,aa=fa[aa];
		while(aa!=bb)vv[aa]=vv[bb]=1,aa=fa[aa],bb=fa[bb];
		vv[aa]=bk=1,dfs1(1,1e9);
	}printf("\n");
	return 0;
}
