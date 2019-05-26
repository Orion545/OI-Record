#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<set>
using namespace std;
const int maxn=5e4+77;
int x[maxn],y[maxn],d[maxn],list[maxn],n,m,cnt,tot,f[maxn],g[maxn];
struct E
{
	int to,next,v;
}e[maxn*2];
struct node
{
	int val,id;
};
set<int> q;
void add(int u,int v,int val)
{
	e[++cnt].to=v; e[cnt].next=list[u]; list[u]=cnt; e[cnt].v=val;
}
void init()
{
	for(int i=1; i<=n-1; i++) add(x[i],y[i],d[i]),add(y[i],x[i],d[i]);
}
bool check1()
{
	for(int i=1; i<=n-1; i++)
	{
		if(x[i]+1!=y[i]) return 0;
	}
	return 1;
}
bool check2()
{
	for(int i=1; i<=n-1; i++)
	{
		if(x[i]!=1) return 0;
	}
	return 1;
}
void work1()
{
	int l=1,r=(n-1)*10077;
	while(l<=r)
	{
		int mid=(l+r)>>1,s=0,sum=0;
		for(int i=1; i<=n-1; i++)
		{
			s+=d[i]; if(s>=mid) s=0,sum++;
		}
		if(sum>=m) l=mid+1; else r=mid-1;
	}
	printf("%d",r);
}
void work2()
{
	sort(d+1,d+n);
	int l=1,r=(n-1)*10077;
	while(l<r)
	{
		int mid=(l+r)>>1,sum=0;
		int tot=n-1; 
		while(tot>0&&d[tot]>=mid) tot--,sum++;
		for(int i=1; i<=tot; i++) q.insert(d[i]);
		while(q.size())
		{
			set<int>::iterator t=q.begin();
			int tt=*t; q.erase(tt);
			set<int>::iterator p=q.lower_bound(mid-tt);
			if(p!=q.end()) q.erase(*p),sum++;
		}
		if(sum>=mid) l=mid+1;else r=mid-1;
	}
	printf("%d",r);
}
node dfs(int u,int fa)
{
	node s;
	s.val=0; s.id=u;
	for(int i=list[u]; i; i=e[i].next)
	{
		int v=e[i].to;
		if(v==fa) continue;
		node p=dfs(v,u);
		p.val+=e[i].v;
		if(p.val>s.val) s=p;
	}
	return s;
}
void workk()
{
	init();
	int t=dfs(1,0).id;
	printf("%d",dfs(t,0).val);
}
void dp(int u,int fa,int mid)
{
	set<int> qs;
	for(int i=list[u]; i; i=e[i].next)
	{
		int v=e[i].to;
		if(v==fa) continue;
		dp(v,u,mid);
		g[v]+=e[i].v;
		if(g[v]>=mid) f[u]++;else qs.insert(g[v]);
		f[u]+=f[v];
	}
	while(qs.size())
	{
		set<int>::iterator t=qs.begin();
		int tt=*t; qs.erase(tt);
		set<int>::iterator p=qs.lower_bound(mid-tt);
		if(p==qs.end()) g[u]=max(g[u],tt);else
			qs.erase(*p),f[u]++;
	}
}
void work()
{
	init();
	int l=1,r=10077*(n-1);
	while(l<r)
	{
		memset(f,0,sizeof(f)); memset(g,0,sizeof(g));
		int mid=(l+r)>>1;
		dp(1,0,mid);
		if(f[1]>=m) l=mid+1;else r=mid-1;
	}
	printf("%d",r);
}
int main()
{
	freopen("track.in","r",stdin); freopen("track.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n-1; i++) scanf("%d%d%d",&x[i],&y[i],&d[i]);
	if(m==1) workk();
	if(check1()) work1();else
	if(check2()) work2();
	else work();
}
//rp++










