#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cmath>
using namespace std;
const int MAXN=1e5+10;
int a[MAXN];
inline int read()
{
	int re=0; char ch=getchar();
	while(ch<'0' || ch>'9') ch=getchar();
	while(ch>='0' && ch<='9') re=re*10+(ch^48),ch=getchar();
	return re;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n=read(),ans=0,last=0;
	for(int i=1;i<=n;i++) a[i]=read();
	for(int i=1;i<=n;i++)
	{
		if(a[i]>last) ans+=a[i]-last;
		last=a[i];
	}
	printf("%d\n",ans);
	return 0;
}
