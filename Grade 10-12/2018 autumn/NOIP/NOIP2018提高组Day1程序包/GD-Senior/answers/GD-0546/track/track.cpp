#include<cstdio>
#include<cstring>
#include<algorithm>
//#include<queue>
//#include<set>
using namespace std;
const int N=50010;
namespace graph
{
	int h[N];
	int v[2*N];
	int w[2*N];
	int t[2*N];
	int cnt;
	void add(int x,int y,int z)
	{
		cnt++;
		v[cnt]=y;
		w[cnt]=z;
		t[cnt]=h[x];
		h[x]=cnt;
	}
};
int n,m;
int f[N];
int g[N];
int a[N];
//multiset<int> st;
int st[N];
int top;
int q[2*N];
int head;
int tail;
void dfs(int x,int fa,int y)
{
	for(int i=graph::h[x];i;i=graph::t[i])
		if(graph::v[i]!=fa)
			dfs(graph::v[i],x,y);
	int t=0;
	f[x]=0;
	g[x]=0;
	for(int i=graph::h[x];i;i=graph::t[i])
	{
		int v=graph::v[i];
		if(v!=fa)
		{
			f[x]+=f[v];
			g[v]+=graph::w[i];
			if(g[v]>=y)
			{
				g[v]=0;
				f[x]++;
			}
			else
				a[++t]=g[v];
		}
	}
	sort(a+1,a+t+1);
	top=0;
	head=t+1;
	tail=t;
	for(int i=1;i<=t;i++)
	{
		while(top&&st[top]+a[i]>=y)
			q[--head]=st[top--];
		if(tail>=head&&a[i]+q[head]>=y)
		{
			head++;
			f[x]++;
		}
		else
		{
			if(a[i]+a[i]>=y)
				q[++tail]=a[i];
			else
				st[++top]=a[i];
		}
	}
	while(top)
		q[--head]=st[top--];
	if(tail>=head)
		g[x]=q[tail];
	else
		g[x]=0;
}
int check(int y)
{
	dfs(1,0,y);
	return f[1]>=m;
}
int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	scanf("%d%d",&n,&m);
	int x,y,z;
	for(int i=1;i<n;i++)
	{
		scanf("%d%d%d",&x,&y,&z);
		graph::add(x,y,z);
		graph::add(y,x,z);
	}
	int l=0,r=500000000;
	while(l<r)
	{
		int mid=(l+r+1)>>1;
		if(check(mid))
			l=mid;
		else
			r=mid-1;
	}
	printf("%d\n",l);
	return 0;
}
