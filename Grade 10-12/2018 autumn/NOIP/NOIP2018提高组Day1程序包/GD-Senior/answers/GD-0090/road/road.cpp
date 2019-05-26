#include <cstdio>
#include <cstring>
#include <algorithm>

#define For(i,a,b) for(int i=a;i<=b;++i)
#define Rep(i,a,b) for(int i=b;i>=a;--i)
#define ll long long

#define p(x) ('0'<=x&&x<='9')
char cc;
template <class T> void read(T &x)
{
	static int re;
	x=0; re=1; cc=getchar();
	while(!p(cc)) { re= cc=='-'?-1:1; cc=getchar(); }
	while(p(cc)) { x=x*10+cc-'0'; cc=getchar(); }
	x=x*re;
}
#undef p

using namespace std;

#define N 100010

int n,dep[N],cur;
ll ans;

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	read(n);
	For(i,1,n) read(dep[i]);
	For(i,1,n)
	{
		if(dep[i]>dep[i-1])
			ans+=0LL+dep[i]-dep[i-1];
	}
	printf("%lld",ans);
	return 0;
}
