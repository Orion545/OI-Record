#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#define inf 0x3f3f3f3f
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0' || ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0' && ch<='9')x=x*10+ch-'0',ch=getchar();
	return x*f;
}
inline void write(int x)
{
	if(x<0)putchar('-');
	if(x>9)write(x/10);
	putchar(x%10+'0');
}
int a[100010];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n=read();
	for(int i=1;i<=n;i++)a[i]=read();a[n+1]=0;
	long long ans=0;
	while(1)
	{
		bool bk=true;int last=0,mn=inf;
		for(int i=1;i<=n+1;i++)
		{
			if(a[i]!=0)bk=false,mn=min(mn,a[i]);
			else
			{
				for(int j=last+1;j<=i-1;j++)a[j]-=mn;
				last=i;if(mn!=inf)ans+=mn,mn=inf;
			}
		}
		if(bk==true)break;
	}
	printf("%lld\n",ans);
	return 0;
}
