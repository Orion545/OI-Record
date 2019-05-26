#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
inline char get_c()
{
	static char buf[1<<14],*p1=buf,*p2=buf;
	return (p1==p2)&&(p2=(p1=buf)+fread(buf,1,1<<14,stdin),p1==p2)?EOF:*p1++;
}
int read_()
{
	int f=1,k=0;char c=get_c();
	while(c<'0'||c>'9') c=='-'&&(f=-1),c=get_c();
	while(c>='0'&&c<='9') k=k*10+c-'0',c=get_c();
	return k*f;
}
int T,a[110],n,mx,ans,pr;
bool vis[25030];
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	T=read_();
	for(int ca=1;ca<=T;ca++)
	{
		n=read_(); ans=0;
		for(int i=1;i<=n;i++) a[i]=read_();
		sort(a+1,a+n+1); mx=a[n];
		memset(vis,0,sizeof(vis));
		vis[0]=true;
		for(int i=1;i<=n;i++)
		{
			if (vis[a[i]]) continue;
			ans++;
			for(int j=1;j<=mx;j++)
			{
				pr=j-a[i];
				if (pr<0) continue;
				if (vis[pr]) vis[j]=true;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
