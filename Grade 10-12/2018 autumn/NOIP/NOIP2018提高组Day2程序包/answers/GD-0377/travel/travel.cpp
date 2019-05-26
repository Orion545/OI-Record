#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define N 6000
#define forline  for(int i=head[u];i;i=edge[i].nxt) 
using namespace std;
int head[N],a[N],n,m,q[N],cnt,x,y,ex[N],c[N];
bool vi[N];
struct node{
	int to;
	int nxt;
}edge[N*2];
bool cmp(int x,int y)
{
	return x<y;
}
void add(int x,int y)
{
	edge[++cnt].to=y;
	edge[cnt].nxt=head[x];
	head[x]=cnt;
}
void dfs(int u)
{
	int tot=0;
	q[++cnt]=u;
	vi[u]=1;
	int s[N];
	int tmp=n+20;
	forline
	{
		int v=edge[i].to;
		if (vi[v])	continue;
		if (ex[i]==1)	continue;
		s[++tot]=v;
	}
	sort(s+1,s+1+tot,cmp);
	for (int i=1;i<=tot;i++)	dfs(s[i]);
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++)
	{
		scanf("%d%d",&x,&y);
		add(x,y);	add(y,x);
	}
	int o=cnt;	cnt=0;
	memset(c,0x4f,sizeof(c));
	if (m==n)
	{
		for (int i=1;i<=o-1;i+=2)
		{
			if (i!=1)	ex[i-1]=ex[i-2]=0;
			ex[i]=1;	ex[i+1]=1;
			memset(vi,0,sizeof(vi));	cnt=0;
			dfs(1);
			if (cnt!=n)	continue;
			int  fl=0;
			for (int j=1;j<=n;j++)	
			{
				if (c[j]<q[j])	fl=1;
				else if (c[j]>q[j])	fl=2;
				if (fl)	break;
			}
			if (fl==2)
			for (int j=1;j<=n;j++)	c[j]=q[j];
		}
		for (int i=1;i<=n;i++)	printf("%d ",c[i]);
	}	
	else 
	{
		dfs(1);
		for (int i=1;i<=n;i++)	printf("%d ",q[i]);
	}
	cout<<endl;
	fclose(stdin);	fclose(stdout);
	return 0;
}
