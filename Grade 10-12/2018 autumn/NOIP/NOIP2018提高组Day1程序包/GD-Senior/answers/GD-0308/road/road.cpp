#include<cstdio>
#include<cstring>
#include<algorithm>
#define fo(i,a,b) for(int i=(a);i<=(b);++i)
#define fd(i,a,b) for(int i=(a);i>=(b);--i)
#define mset(a,x) memset(a,x,sizeof(a))
using namespace std;
typedef long long ll;
int read()
{
	char ch;int n=0,p=1;
	for(ch=getchar();ch<'0' || '9'<ch;ch=getchar()) if(ch=='-') p=-1;
	for(;'0'<=ch && ch<='9';ch=getchar()) n=n*10+ch-'0';
	return n*p;
}
const int N=1e5+5;
int n,a[N];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read();
	ll ans=0;
	fo(i,1,n) a[i]=read(),ans+=max(0,a[i]-a[i-1]);
	printf("%lld\n",ans);
	return 0;
}

