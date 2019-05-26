#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN=110,MAXA=2.5e4+10;
inline int read()
{
	int re=0; char ch=getchar();
	while(ch<'0' || ch>'9') ch=getchar();
	while(ch>='0' && ch<='9') re=re*10+(ch^48),ch=getchar();
	return re;
}
int a[MAXN],v[MAXA];
bool cmp(int x,int y) { return x<y; }
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	int T=read();
	while(T--)
	{
		memset(v,0,sizeof(v)); v[0]=1;
		int n=read();
		int ans=0;
		for(int i=1;i<=n;i++) a[i]=read();
		sort(a+1,a+n+1,cmp);
		int maxx=a[n];
		for(int i=0;i<=maxx;i++) if(v[i])
			for(int j=1;j<=n;j++)
				v[i+a[j]]++;
		for(int i=1;i<=n;i++) if(v[a[i]]>1) ans++;
		printf("%d\n",n-ans);
	}
	return 0;
}
