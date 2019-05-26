#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct edge
{
	int x,y;
}bian[11000];
inline bool cmp(edge x,edge y){return x.x==y.x?x.y>y.y:x.x<y.x;}
struct node
{
	int x,y,next;
}a[11000];int len,last[5100];
inline void ins(int x,int y)
{
	len++;a[len].x=x;a[len].y=y;
	a[len].next=last[x];last[x]=len;
}
int dfn[5100],low[5100],z;
int r[5100],rlen;
int sta[5100],top;bool v[5100];
inline int mymin(int x,int y){return x<y?x:y;}
void tar(int x,int fa)
{
	dfn[x]=++z;low[x]=z;
	sta[++top]=x;v[x]=true;
	for(int k=last[x];k>0;k=a[k].next)
	{
		int y=a[k].y;
		if(y!=fa)
		{
			if(dfn[y]==0)
			{
				tar(y,x);
				low[x]=mymin(low[x],low[y]);
			}
			else if(v[y]==true)low[x]=mymin(low[x],dfn[y]);
		}
	}
	if(dfn[x]==low[x])
	{
		if(sta[top]==x)top--;
		else
		{
			r[++rlen]=sta[top];
			do
			{
				top--;
				r[++rlen]=sta[top];
			}while(sta[top]!=x);
			top--;
		}
	}
}
/*zzzz*/
int xxxx,yyyy;
int aa[5100],alen;
void dfs(int x,int fa)
{
	aa[++alen]=x;
	for(int k=last[x];k>0;k=a[k].next)
	{
		int y=a[k].y;
		if(x==xxxx&&y==yyyy)continue;
		if(x==yyyy&&y==xxxx)continue;
		if(y!=fa)dfs(y,x);
	}
}
int cc[5100];
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int n,m;scanf("%d%d",&n,&m);
	len=0;memset(last,0,sizeof(last));
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&bian[2*i-1].x,&bian[2*i-1].y);
		bian[2*i].x=bian[2*i-1].y;
		bian[2*i].y=bian[2*i-1].x;
	}
	sort(bian+1,bian+2*m+1,cmp);
	for(int i=1;i<=2*m;i++)ins(bian[i].x,bian[i].y);
	if(m==n-1)
	{
		xxxx=0;yyyy=0;
		alen=0;dfs(1,0);
		for(int i=1;i<alen;i++)printf("%d ",aa[i]);
		printf("%d\n",aa[alen]);
	}
	else
	{
		memset(cc,63,sizeof(cc));
		memset(dfn,0,sizeof(dfn));
		memset(low,0,sizeof(low));
		memset(v,false,sizeof(v));
		top=0;z=0;rlen=0;tar(1,0);
		for(int i=1;i<=rlen;i++)
		{
			xxxx=r[i];yyyy=r[i%rlen+1];
			alen=0;dfs(1,0);
			int bk=0;
			for(int i=1;i<=n;i++)
			{
				if(aa[i]>cc[i]){bk=1;break;}
				if(aa[i]<cc[i]){bk=-1;break;}
			}
			if(bk==-1)
			{
				for(int i=1;i<=n;i++)cc[i]=aa[i];
			}
		}
		for(int i=1;i<n;i++)printf("%d ",cc[i]);
		printf("%d\n",cc[n]);
	}
	return 0;
}
