#include<cstdio>
#include<cctype>
#define N 100005
long long n,a[N],ans=0;
inline void Ip(long long&x)
{
	x=0;
	char ch=getchar();
	while(!isdigit(ch)) ch=getchar();
	while(isdigit(ch))
	{
		x=x*10+ch-48;
		ch=getchar();
	}
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	Ip(n);
	a[0]=0;
	for(int i=1;i<=n;i++) Ip(a[i]);
	ans=0;
	for(int i=1;i<=n;i++) if(a[i]>=a[i-1]) ans+=a[i]-a[i-1];
	printf("%lld",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
