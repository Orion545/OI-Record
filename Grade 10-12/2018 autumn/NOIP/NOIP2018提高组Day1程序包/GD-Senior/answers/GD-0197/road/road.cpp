#include <bits/stdc++.h>
using namespace std;
const long long Maxx=0x3f3f3f3f;
inline long long read()
{
	long long x=0,f=1;char s=getchar();
	while(s>'9'||s<'0')
	{
		if(s=='-') f=-1;
		s=getchar();
	}
	while(s<='9'&&s>='0') x=x*10+s-48,s=getchar();
	return x*f;
}
long long ans=0;
long long a[110000];
void get_ans(long long l,long long r,long long stp)
{
	if(l>r) return ;
	long long minn=Maxx;
	for(register long long i=l;i<=r;++i) minn=min(minn,a[i]);
	ans+=minn-stp;
	long long ll=l;
	for(long long i=l;i<=r;++i)
	{
		if(a[i]==minn)
		{
			a[i]=Maxx;
			get_ans(ll,i-1,minn);ll=i+1;
		}
	}
	get_ans(ll,r,minn);
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	long long n=read();
	for(long long i=1;i<=n;i++) a[i]=read();
	get_ans(1,n,0);
	printf("%lld\n",ans);
	return 0;
}
