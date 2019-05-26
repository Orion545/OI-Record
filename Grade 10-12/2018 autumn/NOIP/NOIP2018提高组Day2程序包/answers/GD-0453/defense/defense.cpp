#include<stdio.h>
#include<string.h>
#include<algorithm>
#define MAXN 100005
#define MAXM MAXN*2
#define ll long long
#define INF 1000000007
#define fo(i,a,b) for (ll i=a;i<=b;++i)
#define fd(i,a,b) for (ll i=a;i>=b;--i)
#define rep(i,a) for (ll i=last[a];i;i=next[i])

using namespace std;

ll last[MAXM],next[MAXM],tov[MAXM];
ll f[MAXN][2],p[MAXN];
char type[5];
ll n,m,tot;

ll min(ll x,ll y)
{
	return x<y?x:y;
}
ll read()
{
	ll x=0,f=1;char ch=getchar();
	while (ch<'0' || '9'<ch){if (ch=='-')f=-1;ch=getchar();}
	while ('0'<=ch && ch<='9')x=x*10+ch-'0',ch=getchar();
	return x*f;
}
void link(ll x,ll y)
{
	next[++tot]=last[x],last[x]=tot,tov[tot]=y;
}
void dp(ll x,ll y)
{
	rep(i,x)if (tov[i]!=y)
	{
		dp(tov[i],x);
		f[x][0]+=f[tov[i]][1];
		f[x][1]+=min(f[tov[i]][0],f[tov[i]][1]);
	}
}
int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	n=read(),m=read(),scanf("%s",&type);
	fo(i,1,n)p[i]=read();
	fo(i,1,n-1)
	{
		ll x=read(),y=read();
		link(x,y),link(y,x);
	}
	if (n<=2000 && m<=2000)
	{
		fo(i,1,m)
		{
			fo(j,1,n)f[j][0]=0,f[j][1]=p[j];
			ll a=read(),x=read(),b=read(),y=read();
			f[a][x^1]=INF,f[b][y^1]=INF;
			dp(1,0);
			if (min(f[1][0],f[1][1])>=INF)printf("-1\n");
			else printf("%lld\n",min(f[1][0],f[1][1]));
		}
		return 0;
	}
	return 0;
}
