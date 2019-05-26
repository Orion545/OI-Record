#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

const int N=100005;

int n,a[N],b[N],lef[N],rig[N];

int read()
{
	int x=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read();
	for (int i=1;i<=n;i++) a[i]=read();
	int tp=0;
	for (int i=1;i<=n;i++)
	{
		while (tp&&b[tp]>a[i]) tp--;
		lef[i]=b[tp];b[++tp]=a[i];
	}
	tp=0;
	for (int i=n;i>=1;i--)
	{
		while (tp&&b[tp]>=a[i]) tp--;
		rig[i]=b[tp];b[++tp]=a[i];
	}
	int ans=0;
	for (int i=1;i<=n;i++) ans+=a[i]-std::max(lef[i],rig[i]);
	printf("%d\n",ans);
	return 0;
}
