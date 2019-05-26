#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long
inline int read() {
	int f=1,x=0;
	char c=getchar();
	for (;c<'0'||c>'9';c=getchar()) f=c=='-'?-1:1;
	for (;c>='0'&&c<='9';c=getchar()) x=x*10+c-48;
	return f*x;
}
const int N=1e5+50;
int a[N],n,i;
ll ans;
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read();
	for (i=1;i<=n;++i) a[i]=read();
	for (i=n+1;i>=1;i--) a[i]=a[i]-a[i-1];
	for (i=1;i<=n+1;i++) if (a[i]>0) ans+=a[i];
	printf("%lld\n",ans);
	return 0;
}
