#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
inline int read()
{
	int x=0,w=0;char ch=getchar();
	while(ch<'0'||ch>'9')w|=ch=='-',ch=getchar();
	while(ch>='0'&&ch<='9')x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return w?-x:x;
}
int a[150];
bool v[30010];
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	int t=read();
	while(t--)
	{
		int n=read(),ans=0;
		for(int i=1;i<=n;++i)a[i]=read();
		sort(a+1,a+n+1);
		memset(v,0,sizeof(v)),v[0]=1;
		for(int i=1;i<=n;++i)
		{
			if(!v[a[i]])++ans;
			for(int j=a[i];j<=a[n];++j)
				v[j]|=v[j-a[i]];
		}printf("%d\n",ans);
	}
	return 0;
}
