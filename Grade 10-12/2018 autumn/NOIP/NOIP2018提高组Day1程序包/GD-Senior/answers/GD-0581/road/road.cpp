#include <cstdio>
#define LL long long
inline char get_c()
{
	static char buf[1<<14],*p1=buf,*p2=buf;
	return (p1==p2)&&(p2=(p1=buf)+fread(buf,1,1<<14,stdin),p1==p2)?EOF:*p1++;
}
LL read_()
{
	LL f=1,k=0;char c=get_c();
	while(c<'0'||c>'9') c=='-'&&(f=-1),c=get_c();
	while(c>='0'&&c<='9') k=k*10ll+c-'0',c=get_c();
	return k*f;
}
LL a[100100],n,ans;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read_();
	for(int i=1;i<=n;i++) a[i]=read_();
	ans=a[1];
	for(int i=2;i<=n;i++)
	{
		if (a[i]>a[i-1]) ans+=(a[i]-a[i-1]);
	}
	printf("%lld",ans);
	return 0;
}
