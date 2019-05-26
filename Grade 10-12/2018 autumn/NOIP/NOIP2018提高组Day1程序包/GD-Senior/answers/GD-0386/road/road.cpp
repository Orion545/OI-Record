#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#define ll long long
#define maxn 100010
inline ll read()
{
	ll x=0; char c=getchar(),f=1;
	for(;c<'0'||'9'<c;c=getchar())if(c=='-')f=-1;
	for(;'0'<=c&&c<='9';c=getchar())x=x*10+c-'0';
	return x*f;
}
int a[2*maxn];
int n;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++)a[i]=read();
	ll ans=a[1];
	for(int i=2;i<=n;i++)
		if(a[i]>a[i-1])ans+=a[i]-a[i-1];
	printf("%lld\n",ans);
	fclose(stdin); fclose(stdout);
	return 0;
}
