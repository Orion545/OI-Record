#include<cstdio>
using namespace std;
int n,m,x,y,cnt,index;
int head[20000],b[5005],vi[5005],pre[5005],a[5005][3];
struct edge{
	int next,to;
}e[20000];

inline int read()
{
	int s=0;
	char ch=getchar();
	while (ch<'0'||ch>'9') ch=getchar();
	while (ch>='0'&&ch<='9') {s=s*10+ch-48;ch=getchar();}
	return s;
}

void addedge()
{
	e[++cnt].next=head[x],e[cnt].to=y,head[x]=cnt;
	e[++cnt].next=head[y],e[cnt].to=x,head[y]=cnt;
}

void dfs(int u)
{
	if (index==n)
		return;
	int minn=10000;
	for (int i=head[u];i;i=e[i].next)
	{
		int v=e[i].to;
		if (!vi[v]&&v<minn)
			minn=v;
	}
	if (minn!=10000)
	{
		vi[minn]=1;
		pre[minn]=u;
		b[++index]=minn;
		dfs(minn);
		dfs(pre[u]);
	}
	else
		dfs(pre[u]);
}

void dfs2(int u)
{
	if (index==n)
		return;
	for (int i=0;i<=1;i++)
		if (!vi[a[u][i]])
		{
			int v=a[u][i];
			b[++index]=v;
			vi[v]=1;
			dfs2(v);
		}
}

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	n=read(),m=read();
	b[++index]=1;
	vi[1]=1;
	if (m==n-1)
	{
		for (int i=1;i<=m;i++)
		{
			x=read(),y=read();
			addedge();
		}	
		dfs(1);
	}
	else
	{
		for (int i=1;i<=m;i++)
		{
			x=read(),y=read();
			a[x][a[x][2]++]=y;
			a[y][a[y][2]++]=x;
			
		}
		int p=a[1][0],q=a[1][1];
		if (p<q) 
		{
			b[++index]=p;
			vi[p]=1;    
			int k;
			if (a[p][0]==1) k=a[p][1]; 
			else k=a[p][0];
			if (k<q)
			{
				b[++index]=k;
				vi[k]=1;
				dfs2(k);
			}
			else
			{
				b[++index]=q;
				vi[q]=1;
				dfs2(q);
			}
		}
		else
		{
			b[++index]=q;
			vi[q]=1;
			int k;
			if (a[q][0]==1) k=a[q][1]; 
			else k=a[q][0];
			if (k<p)
			{
				b[++index]=k;
				vi[k]=1;
				dfs2(k);
			}
			else
			{
				b[++index]=p;
				vi[p]=1;
				dfs2(p);
			}
		}
	}
	for (int i=1;i<=index;i++)
		printf("%d ",b[i]);
	return 0;
}
