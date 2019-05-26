#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#define qread(x) x=read()
#define qreadl(x) x=readl()
using namespace std;
typedef long long LL;
inline int read() {
	int x=0,f=1;char ch=getchar();
	while(ch<'0' || ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0' && ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return f*x;
}
inline LL readl() {
	LL x=0,f=1;char ch=getchar();
	while(ch<'0' || ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0' && ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return f*x;
}
const int N=1e5+10;
int a[N];
int main() {
	freopen("road.in","r",stdin);freopen("road.out","w",stdout);
	int n;qread(n);a[0]=0;LL ans=0;
	for(int i=1;i<=n;++i)qread(a[i]),ans+=(LL)((a[i]-a[i-1]>0)?(a[i]-a[i-1]):0);
	printf("%lld\n",ans);
	return 0;
}
