#include<cstdio>
#include<cstring>
#include<cctype>
#include<algorithm>
#include<iostream>
#include<queue>
using namespace std;

const int maxn=50010;
int n,m,tot,head[maxn],dep[maxn];
typedef long long ll;
ll sum[maxn],t[maxn];
struct node
{
	int nxt,to,dis;
}edge[maxn<<1];
bool vis[maxn],is1,is2,is3;

int rd()
{
	int x=0,f=1;
	char c=getchar();
	while (!isdigit(c))
		f=c=='-'?-1:1,c=getchar();
	while (isdigit(c))
		x=(x<<1)+(x<<3)+(c^48),c=getchar();
	return x*f;
}

void add(int u,int v,int w)
{
	edge[++tot]=(node){head[u],v,w};
	head[u]=tot;
}

void dfs(int u,int fa)
{
	vis[u]=1;
	dep[u]=dep[fa]+1;
	int i,v,w;
	for (i=head[u];i;i=edge[i].nxt)
	{
		v=edge[i].to;
		w=edge[i].dis;
		if (vis[v])
			continue;
		sum[v]=sum[u]+w;
		dfs(v,u);
	}
}

bool ch(ll x)
{
	int l,r=n,k=0;
	ll tmp=0;
	for (l=2;l<=n&&l<=r;l++)
	{
		tmp=t[l];
		while (tmp<x&&l<=r)
		{
			l++;
			tmp+=t[l];
		}
		if (l>r)
			return 0;
		k++;
	}
	return k>=m;
}

ll dis[maxn];
queue <int> q;
bool b[maxn];

int bfs(int u)
{
	memset(dis,0,sizeof(dis));
	memset(b,0,sizeof(b));
	while (!q.empty())
		q.pop();
	int i,v,w;
	ll ans1=-1,ans2;
	b[u]=1;
	dis[u]=0;
	q.push(u);
	while (!q.empty())
	{
		u=q.front();
		q.pop();
		for (i=head[u];i;i=edge[i].nxt)
		{
			v=edge[i].to;
			w=edge[i].dis;
			if (b[v])
				continue;
			b[v]=1;
			dis[v]=dis[u]+(ll)w;
			q.push(v);
			if (ans1<dis[v])
			{
				ans1=dis[v];
				ans2=v;
			}
		}
	}
	return ans2;
}

bool ck(int x)
{
	int i;
	ll tmp=0,cnt=0;
	for (i=2;i<=n;i++)
	{
		if (tmp+sum[i]<=x)
			tmp+=sum[i];
		else
		{
			tmp=sum[i];
			cnt++;
		}
	}
	return cnt>=m;
}

int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	int i,j,u,v,w;
	ll kk;
	n=rd();
	m=rd();
	if (m==1)
		is1=1;
	is2=is3=1;
	for (i=1;i<=n-1;i++)
	{
		u=rd();v=rd();w=rd();
		if (u+1!=v)
			is3=0;
		if (u!=1)
			is2=0;
		add(u,v,w);
		add(v,u,w);
		kk+=w;
	}
	sum[1]=0;
	dfs(1,0);
	if (is1)
	{
		int p=bfs(1);
		int t=bfs(p);
		printf("%lld\n",dis[t]);
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	if (is2)
	{
		t[1]=0;
		ll tmp=0;
		for (i=2;i<=n;i++)
			t[i]=sum[i],tmp+=sum[i];
		sort(t+2,t+n+1);
		ll l=0,r=tmp,mid;
		while (l<r)
		{
			mid=l+r+1>>1;
			if (ch(mid))
				l=mid;
			else
				r=mid-1;
		}
		printf("%lld\n",l);
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	if (is3)
	{
		ll tmp=0;
		for (i=2;i<=n;i++)
			tmp+=sum[i];
		ll l=0,r=tmp,mid;
		while (l<r)
		{
			mid=l+r+1>>1;
			if (ck(mid))
				l=mid;
			else
				r=mid-1;
		}
		printf("%lld\n",l);
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	printf("%lld\n",kk);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
