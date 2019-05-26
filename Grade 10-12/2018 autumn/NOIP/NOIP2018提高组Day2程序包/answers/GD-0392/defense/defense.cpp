#include <bits/stdc++.h>

using namespace std;
const long long maxn=4005;
long long pan[maxn],pp[maxn],to[maxn],nextt[maxn],f[maxn],g[maxn],costt[maxn];
long long n,m,x,xx,yy,y,p,tp1,tp2;
char s[10];
void dfs(long long k)
{
	pan[k]=1;
	long long pu=pp[k],cnt=0;
	while (pu>0)
	{
		if (pan[to[pu]]==0)
		{
			dfs(to[pu]);
			cnt++;
		}
		pu=nextt[pu];
	}
	pan[k]=0;
	if ((k!=xx || tp1!=0) && (k!=yy || tp2!=0))
	f[k]=costt[k];else f[k]=1000000000;
	if ((k!=xx || tp1!=1) && (k!=yy || tp2!=1))
	g[k]=0; else g[k]=1000000000;
	pu=pp[k];
	while (pu>0)
	{
		if (pan[to[pu]]==0)
		{
		if ((k!=xx || tp1!=0) && (k!=yy || tp2!=0))
		{
			f[k]+=min(f[to[pu]],g[to[pu]]);
		}
		else f[k]=1000000000;
		if ((k!=xx || tp1!=1) && (k!=yy || tp2!=1))
		{
			g[k]+=f[to[pu]];
		}
		else g[k]=1000000000;
		}
		pu=nextt[pu];
	}
}
int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	cin>>n>>m;scanf("%s",&s+1);
	for (long long i=1;i<=n;i++) scanf("%lld",&costt[i]);
	for (long long i=1;i<n;i++)
	{
		scanf("%lld %lld",&x,&y);
		p++;to[p]=y;nextt[p]=pp[x];pp[x]=p;
		p++;to[p]=x;nextt[p]=pp[y];pp[y]=p;
	}
	for (long long i=1;i<=m;i++)
	{
		scanf("%lld%lld%lld%lld",&xx,&tp1,&yy,&tp2);
		dfs(1);
		if (min(f[1],g[1])>=1000000000) printf("-1\n");
		else printf("%lld\n",min(f[1],g[1]));
	}
	return 0;
}
