#include<cmath>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f*=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
	return x*f;
}
struct node{
	int x,y,next;
}a[210000];int len,last[210000];
void ins(int x,int y)
{
	len++;
	a[len].x=x;a[len].y=y;
	a[len].next=last[x];last[x]=len;
}
int v[5100],ans[5100],s;
void dfs(int x,int fa)
{
	int minn=1<<29;
	while(minn!=1<<30)
	{
		minn=1<<30;
		for(int k=last[x];k;k=a[k].next)
			if(!v[a[k].y]&&a[k].y!=fa)minn=min(minn,a[k].y);
		if(minn!=1<<30)v[minn]=1,ans[++s]=minn;
		if(minn!=1<<30)dfs(minn,x);
	}
}
int dfn[5100],sta[5100],id,cnt;
int belong[5100],low[5100];
int top;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int n,m;
	n=read();m=read();
	len=0;memset(last,0,sizeof(last));
	for(int i=1;i<=m;i++)
	{
		int x,y;
		x=read();y=read();
		ins(x,y);ins(y,x);
	}
	s=1;ans[1]=1;
	memset(v,0,sizeof(v));dfs(1,0);
	for(int i=1;i<s;i++)printf("%d ",ans[i]);
	printf("%d\n",ans[s]);
	return 0;
} 
