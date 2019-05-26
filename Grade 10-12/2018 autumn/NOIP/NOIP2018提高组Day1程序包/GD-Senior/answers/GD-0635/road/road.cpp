#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
typedef long long ll;
inline int read()
{
	int x=0,f=1; char ch=getchar();
	while(ch<'0' || ch>'9'){if(ch=='-')f=-1; ch=getchar();}
	while(ch>='0' && ch<='9'){x=x*10+ch-'0'; ch=getchar();}
	return x*f;
}
inline ll lread()
{
	ll x=0,f=1; char ch=getchar();
	while(ch<'0' || ch>'9'){if(ch=='-')f=-1; ch=getchar();}
	while(ch>='0' && ch<='9'){x=x*10+ch-'0'; ch=getchar();}
	return x*f;
}
const int N=1e5+10;
ll a[N],b[N];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n=read();
	a[0]=0;
	for(int i=1;i<=n;i++) a[i]=lread(),b[i]=a[i]-a[i-1];
	ll ans=0;
	for(int i=1;i<=n;i++)
	{
		if(b[i]>0) ans+=b[i];
	}
	printf("%lld\n",ans);
	return 0;	
}
