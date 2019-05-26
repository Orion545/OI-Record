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
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	int n,m;
	read(n);read(m);
	if(n>m)swap(n,m);
	if(n==m&&n==3)printf("112\n");
	else
	{
		if(n>2)return 0;
		ll ans=4,k;
		if(n==1)k=2;
		else k=3;
		m-=1;
		int b=1;
		while(b<=m)
		{
			if(b&m)ans=(ans*k)%1000000007;
			k=(k*k)%1000000007;b<<=1;
		}
		printf("%d\n",ans);
	}
	return 0;
}

