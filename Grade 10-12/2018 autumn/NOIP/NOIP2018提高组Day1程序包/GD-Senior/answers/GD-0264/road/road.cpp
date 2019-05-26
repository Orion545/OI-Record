#include <cstdio>
using namespace std;
inline int read()
{
	int x=0,w=0;char ch=getchar();
	while(ch<'0'||ch>'9')w|=ch=='-',ch=getchar();
	while(ch>='0'&&ch<='9')x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return w?-x:x;
}
int a[110000],p[110000];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n=read(),ans=0;
	for(int i=1;i<=n;++i)
	{
		a[i]=read();
		if(a[i]-a[i-1]>0)ans+=a[i]-a[i-1];
	}printf("%d\n",ans);
	return 0;
}
