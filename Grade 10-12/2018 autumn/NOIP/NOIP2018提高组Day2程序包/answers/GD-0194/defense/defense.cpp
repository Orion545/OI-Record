#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=200010;
typedef long long ll;
const ll inf=100000000000000;
ll n,m,v[maxn],a,b,x,y,f[maxn][3];
ll cur,h[maxn],nxt[maxn],p[maxn];
char op[5];
void add_edge(ll x,ll y)
{
	cur++;
	nxt[cur]=h[x];
	h[x]=cur;
	p[cur]=y;
}
void dfs(int o,int fa,int st)
{
	if(f[o][st]!=-1)return;
	f[o][st]=0;
	if(st==1)f[o][st]=v[o];
	if(st==0)
	{
		for(int j=h[x];j;j=nxt[j])if(p[j]!=fa)
		{
			if(p[j]==b&&!y){f[o][st]=inf;return;}
			dfs(p[j],o,1);
			f[o][st]+=f[p[j]][1];
		}
	}
	else if(st==1)
	{
		for(int j=h[x];j;j=nxt[j])if(p[j]!=fa)
		{
			if(p[j]==b&&y==0)dfs(p[j],o,0),f[o][st]+=f[p[j]][0];
			else if(p[j]==b&&y==0)dfs(p[j],o,1),f[o][st]+=f[p[j]][1];
			else dfs(p[j],o,0),dfs(p[j],o,1),f[o][st]+=min(f[p[j]][0],f[p[j]][1]);
		}
	}
}
int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	scanf("%lld%lld%s",&n,&m,op);
	for(int i=1;i<=n;i++)scanf("%lld",v+i);
	for(int i=1;i<n;i++)scanf("%lld%lld",&x,&y),add_edge(x,y),add_edge(y,x);
	if(op[0]=='A')
	{
		
		return 0;
	}
	if(op[1]=='1')
	{
		while(m--)
		{
			scanf("%lld%lld%lld%lld",&a,&x,&b,&y);
			memset(f,-1,sizeof f);
			dfs(1,-1,1);
			if(f[1][1]==inf)printf("-1\n");
			else printf("%lld\n",f[1][1]);
		}
		return 0;
	}
	return 0;
}
