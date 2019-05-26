//provided by hsfz_konjac
#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
#define ll long long
#define rint register int
#define rua int
#define INF 2147483647
inline void read(ll&x)
{
	static char c;while(!isdigit(c=getchar()));
	for(x=0;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+c-'0';
}
inline void read(int&x){static ll lc;read(lc);x=lc;}
inline ll min(ll a,ll b){return a<b?a:b;}
int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	ll s[2],a[100010];
	int n,m,x,y,k,l;
	read(n);read(m);read(x);
	for(rint i=1;i<=n;++i)
	{
		read(a[i]);
		s[i&1]+=a[i];
	}
	for(rint i=1;i<=m;++i)
	{
		read(x);read(k);read(y);read(l);
		if(k&l)
		{
			if((x&1)^(y&1))printf("%d\n",min(s[x&1]+a[y],s[y&1]+a[x]));
			else printf("%d\n",s[x&1]);
		}
		else if(k!=l)printf("%d\n",s[(k?x:y)&1]);
		else printf("-1\n");
	}
	return 0;
}

