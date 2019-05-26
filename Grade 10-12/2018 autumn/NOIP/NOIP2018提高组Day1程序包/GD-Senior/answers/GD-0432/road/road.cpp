#include<bits/stdc++.h>
using namespace std;

int n;
long long a[100010];
long long f[100010];

inline int read()
{
	long long x=0,f=1;char c=getchar();
	while (c<'0' || c>'9') {if (c=='-') f=0;c=getchar();}
	while (c>='0' && c<='9') x=x*10+(c^48),c=getchar();
	return f?x:-x;
}

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read();for (int i=1;i<=n;i++) a[i]=(long long)read();
	f[1]=a[1];
	for (int i=2;i<=n;i++)
	{
		if (a[i]<=a[i-1]) f[i]=f[i-1];
		else f[i]=f[i-1]+(a[i]-a[i-1]);
	}
	printf("%lld\n",f[n]);
	return 0;
}
