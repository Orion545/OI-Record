#include<algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<iostream>
#define N 5005
#define ll long long
using namespace std;
int n,m,p[N],x,y,a,b,tot,last[N*2],next[N*2],tov[N*2];
ll f[N][2],ans;
char s[10];
int ins(int x,int y){tov[++tot]=y,next[tot]=last[x],last[x]=tot;}
int min(int x){return (x<y)?x:y;}
int get(int c)
{
	if (c!=a&&c!=b)
		return min(f[c][1],f[c][0]);
	if (c==a)
		return f[c][x];
	return f[c][y];
}
int get1(int c)
{
	if (c!=a&&c!=b)
		return f[c][1];
	if (c==a)
		if (!x)
			return 214748364;
		else
			return f[c][x];
	if (!y)
		return 214748364;
	else
		return f[c][y];
}
int dg(int c,int l)
{
	if (b==c)
		swap(a,b),swap(x,y);
	int aa=a;
	f[c][0]=0,f[c][1]=p[c];
	for (int i=last[c];i;i=next[i])
	{
		int d=tov[i];
		if (d==l)
			continue;
		dg(d,c);
		if (aa!=c)
			f[c][0]+=get1(d),f[c][1]+=get(d);
		else
			if (!x)
				f[c][0]+=get1(d);
			else
				f[c][1]+=get(d);
	}
}
int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	scanf("%d %d %s",&n,&m,s);
	for (int i=1;i<=n;i++)
		scanf("%d",&p[i]);
	for (int i=1;i<=n-1;i++)
		scanf("%d%d",&x,&y),ins(x,y),ins(y,x);
	while (m--)
	{
		scanf("%d%d%d%d",&a,&x,&b,&y);
		memset(f,63,sizeof f);
		dg(1,0);
		if (a!=1&&b!=1)
			ans=min(f[1][1],f[1][0]);
		else
			if (a==1)
				ans=f[1][x];
			else
				ans=f[1][y];
		if (ans>100000000)
			ans=-1;
		printf("%lld\n",ans);
	}
}
