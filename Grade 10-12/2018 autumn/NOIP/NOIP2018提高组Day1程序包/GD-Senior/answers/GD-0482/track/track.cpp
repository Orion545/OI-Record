#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <queue>
#include <vector>
#define ft first
#define sd second 
#define rep(i,x,y) for(int i=x;i<=y;++i)
#define LL long long
const int N =  200000+233;
using namespace std;

struct xx
{
	int V,nxt,q;
}b[N<<1];

int G,head[N];

void add(int x,int y,int z)
{
	b[++G]=(xx){y,head[x],z};
	head[x]=G;
}

int n,m,x,y,z;
LL st[N],f[N],ans,l,r,mid;
#define F(x) for (int i=head[x];i;i=b[i].nxt)
#define v b[i].V
int cnt;
map <LL ,int > g;
map <LL ,int > ::iterator it,it1;
void debug()
{
	printf("---\n");
	for (it=g.begin();it!=g.end();++it)
	  printf("%lld %d\n",it->ft,it->sd);
	printf("---\n");
}

void dfs(int x,int Fa)
{
	F(x) if (v^Fa) dfs(v,x);
	int tp=0;
	F(x) if ((v^Fa))st[++tp]=f[v]+b[i].q;
	
	if (tp==0)return ;
	sort(st+1,st+1+tp);
	int q=tp;
	while (q&&st[q]>=mid)  ++cnt,--q;
	g.clear();
	rep(i,1,q) ++g[st[i]];
	rep(i,1,q)
	{
	//	it1=g.lower_bound(st[i]);
		it=g.lower_bound(mid-st[i]);
		if (!g.count(st[i])||it==g.end()) continue;
		if (it->ft==st[i]&&it->sd>1)
				{
					it->sd-=2,++cnt;
					if (it->sd==0) g.erase(it);
				}
				
			else 
			{
				if (it->ft==st[i]) it=g.lower_bound(st[i]+1);
				if (it!=g.end())
				{
					--it->sd,++cnt,--it1->sd;
			        if (it->sd==0) g.erase(it);
			        if (it1->sd==0) g.erase(it1);
				}
				
			}
	}
	if (!g.empty()) 
	{
		it=g.end();
		--it;
		f[x]=it->ft;
	}
	else f[x]=0;
}

int vis[N];
void dfs2(int x,int Fa)
{
	F(x) if (v^Fa) dfs2(v,x);
	int tp=0;
	F(x) if ((v^Fa))st[++tp]=f[v]+b[i].q;
	rep(i,1,tp) vis[i]=0;
	sort(st+1,st+1+tp);
	rep(i,1,tp) if (st[i]>=mid) ++cnt,vis[i]=1;
	rep(i,1,tp) rep(j,i+1,tp)
	 if (!vis[i]&&!vis[j]&&st[i]+st[j]>=mid)
	   ++cnt,vis[i]=vis[j]=1;
	f[x]=0;
	rep(i,1,tp) if (!vis[i]) f[x]=max(f[x],st[i]);
}
int check2()
{
	cnt=0;
	dfs2(1,0);
	if (cnt>=m) return 1;
	return 0;
}

int check()
{
	cnt=0;
	dfs(1,0);
	if (cnt>=m) return 1;
	return 0;
}

void solve()
{
	l=1;
	while (l<=r)
	{
		mid=(l+r)>>1;
		if (check2()) 
		  ans=mid,l=mid+1;
		else r=mid-1;
	}
}
int du[N];
int main()
{//
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	scanf("%d%d",&n,&m);
	int mx=0;
	rep(i,2,n)  
	  scanf("%d%d%d",&x,&y,&z),add(x,y,z),add(y,x,z),r+=z,
	   ++du[x],++du[y];
	rep(i,1,n) mx=max(mx,du[i]);
	if (mx<=70)
	{
		solve();
		printf("%lld",ans);
		return 0;
	}
	l=1;
	while (l<=r)
	{
		mid=(l+r)>>1;
		if (check()) ans=mid,l=mid+1;
		else r=mid-1;
	}
	printf("%lld",ans);
	return 0;
}
/*
6 2
1 2 1 
1 3 1
1 4 2
1 5 3
1 6 4


*/
