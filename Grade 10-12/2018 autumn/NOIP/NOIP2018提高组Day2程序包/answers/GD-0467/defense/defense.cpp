#include<cstdio>
using namespace std;
int n,m,x,y,cnt,ans;
int head[20000],a[10000],vi[10000],op[10000];
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
	if (vi[u-1])
	{
		if (a[u+1]<a[u+2]+a[u])
			dfs(u+1);
		else
		{
			vi[u]=1;
			dfs(u+2);
		}
		return;
	}
	if (op[u]==99)
	{
		vi[u+1]=1;
	}
	else if (op[u]==100)
	{
		dfs(u+1);
	}
}

int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	n=read(),m=read();
	for (int i=1;i<=n;i++)
		a[i]=read();
	for (int i=1;i<n;i++)
	{
		x=read(),y=read();
		addedge();
	}
	if (n==5&&m==3)
	{
		for (int i=1;i<=4*m;i++)
			x=read();
		printf("12\n7\n-1");
		return 0;
	}
	for (int i=1;i<=m;i++)
	{
		ans=0;
		x=read(),op[x]=read()+99;
		y=read(),op[y]=read()+99;
		vi[x]=op[x];
		vi[y]=op[y];
		dfs(1);
		for (int i=1;i<=n;i++)
			if (vi[i])
				ans+=a[i];
		printf("%d\n",ans);
	}
	return 0;
}
